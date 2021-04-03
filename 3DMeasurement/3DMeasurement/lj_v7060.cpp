#include "lj_v7060.h"
#include "ui_lj_v7060.h"
#include <QMessageBox>
#include "Resource.h"
#include "ErrorString.h"
#include <QDebug>
#include "openethernetdialog.h"
#include "communicationsettingdialog.h"


#define ToLoadString(x)  #x    //可将宏名转换为字符串
const int DEVICE_ID = 0;
LJV7IF_PROFILE_INFO LJ_V7060::m_profileInfo;

LJ_V7060::LJ_V7060(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LJ_V7060),
    m_xvCurrentDeviceID(0),
    m_xvSendPos(2),
    m_xvReceiveProfileNum(123456789)
{
    ui->setupUi(this);
    this->setWindowTitle("3DMeasurement");
    //this->resize(800,600);
    initStatusLabel();//初始化状态栏
    ui->toolBar->setAllowedAreas(Qt::TopToolBarArea);
    Initialize_Device();//初始化设备
    //连接开始监控按钮信号与槽函数
    connect(StartBtn,&QPushButton::clicked,this,&LJ_V7060::btn_start_clicked);
}

LJ_V7060::~LJ_V7060()
{
    delete ui;
}

void LJ_V7060::initStatusLabel()
{

    //初始化状态栏、工具栏
    StatusLable = new QLabel(ui->statusbar);
    textBrowser = new QTextBrowser(ui->statusbar);
    //textBrowser->resize(1024,200);
    //ui->statusbar->addWidget(StatusLable);
    ui->statusbar->addWidget(textBrowser);
    ui->statusbar->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
    StartBtn = new QPushButton;//开始监控按钮，未连接信号与槽函数
    StartBtn->setText("开始");
    StartBtn->setIcon(QIcon(":/iconPicture/Icon/start.png"));
    ui->toolBar->addWidget(StartBtn);
    ui->toolBar->addAction(ui->actionUSB);
    ui->toolBar->addAction(ui->actionEntherner);
    ui->toolBar->addAction(ui->actionCommClose);
    ui->toolBar->addAction(ui->actionCommunicationSetting);

}

void LJ_V7060::Initialize_Device()
{
    //初始化设备
    int nRc = LJV7IF_Initialize();
    //IDS_SCMD_INITIALIZE 为resource.h中定义的常量
    QString str = ToLoadString(IDS_SCMD_INITIALIZE);//str = "IDS_SCMD_INITIALIZE"
    DisPlayCommandLog(nRc,LoadStringW(str));//LoadStringW(str)=IINITIALIZE

//    for (int i = 0; i < LJV7IF_DEVICE_COUNT; ++i) {
//        m_aDeviceData[i].m_deviceStatus = CDeviceData::DEVICESTATUS_NoConnection;
//        StatusLable->setText(m_aDeviceData[i].GetStatusString());
//    }
}

void LJ_V7060::on_actionUSB_triggered()
{
    //通过USB连接设备
    //指定通过哪台通信设备进行通信m_xvCurrentDeviceID
    int nRc = LJV7IF_UsbOpen(m_xvCurrentDeviceID);
    DisPlayCommandLog(nRc,LoadStringW(ToLoadString(IDS_SCMD_USBOPEN)));
    /*
    switch (nRc) {
    //判断操作是否出错
        case (int)LJV7IF_RC_OK:
                StatusLable->setText("Normal termination");
                break;
        case LJV7IF_RC_ERR_OPEN:
            StatusLable->setText("Failed to open the device");
            break;
        case LJV7IF_RC_ERR_NOT_OPEN:
            StatusLable->setText("Device not open");
            break;
        case LJV7IF_RC_ERR_SEND:
            StatusLable->setText("Command send error");
            break;
        case (int)LJV7IF_RC_ERR_RECEIVE:
            StatusLable->setText("Response reception error");
            break;
        case (int)LJV7IF_RC_ERR_TIMEOUT:
            StatusLable->setText("Time out");
            break;
        case LJV7IF_RC_ERR_PARAMETER:
            StatusLable->setText("Parameter error");
            break;
        case LJV7IF_RC_ERR_NOMEMORY:
            StatusLable->setText("No free space");
            break;
        default:
            StatusLable->setText("Undefined RC (0x%04X)\r\n");
            break;
        }
        */
    CDeviceData::DEVICESTATUS status = (nRc == LJV7IF_RC_OK) ? CDeviceData::DEVICESTATUS_Usb : CDeviceData::DEVICESTATUS_NoConnection;
    m_aDeviceData[m_xvCurrentDeviceID].m_deviceStatus = status;//设备连接状态

}

void LJ_V7060::on_actionEntherner_triggered()
{
    //网线连接
    OpenEthernetDialog *etherNet = new OpenEthernetDialog();
    if(etherNet->exec() == QDialog::Rejected){
        return;}
    LJV7IF_ETHERNET_CONFIG etherNetConfig = etherNet->GetEthernetConfig();
    for(int i = 0; i< 4; i++){
        qDebug()<< etherNetConfig.abyIpAddress[i];
    }
    int nRc = LJV7IF_EthernetOpen(m_xvCurrentDeviceID, &etherNetConfig);
    CDeviceData::DEVICESTATUS status = (nRc == LJV7IF_RC_OK) ? CDeviceData::DEVICESTATUS_Ethernet : CDeviceData::DEVICESTATUS_NoConnection;
    m_aDeviceData[m_xvCurrentDeviceID].m_deviceStatus = status;

    m_aDeviceData[m_xvCurrentDeviceID].m_ethernetConfig = etherNetConfig;

    DisPlayCommandLog(nRc,LoadStringW(ToLoadString(IDS_SCMD_EHTERNETOPEN)));
}
void LJ_V7060::on_actionCommunicationSetting_triggered()
{
    //组合usb通信和EntherNet连接
    CommunicationSettingDialog *PC_SettingDlg = new CommunicationSettingDialog;
    PC_SettingDlg->show();
}

void LJ_V7060::btn_start_clicked(){
    /*
     *StartBtn开始监控按钮槽函数
     *自定义槽函数时，用connect()函数连接信号与槽，不要用自动生成的槽函数命名方式命名，否则会出现警告
     * 如用on_btn_start_clicked()给自定义槽函数命名，会出现如下警告：
     * QMetaObject::connectSlotsByName: No matching signal for on_btn_start_clicked()
    */
    // High-speed data communication start preparations
    int nRc = LJV7IF_RC_OK;
    LJV7IF_HIGH_SPEED_PRE_START_REQ req;
    req.bySendPos = m_xvSendPos;
    nRc = LJV7IF_PreStartHighSpeedDataCommunication(DEVICE_ID, &req, &m_profileInfo);
    if(!CheckReturnCode(nRc)){
        return;
    }

    // Start high-speed data communication.
    nRc = LJV7IF_StartHighSpeedDataCommunication(DEVICE_ID);
    m_xvReceiveProfileNum = 0;
}

bool LJ_V7060::CheckReturnCode(int nRc)
{
    //判断每一步操作是否正确
    if(nRc != LJV7IF_RC_OK){
        QMessageBox::warning(this,"警告","连接失败");
        return false;
    }else
    {
        return true;
    }
}

void LJ_V7060::on_actionCommClose_triggered()
{
    //断开USB或Ethernet的连接。
    int nRc = LJV7IF_CommClose(m_xvCurrentDeviceID);
    DisPlayCommandLog(nRc, IDS_SCMD_COMMCLOSE);
    //执行DLL的结束处理
    nRc = LJV7IF_Finalize();
    DisPlayCommandLog(nRc,LoadStringW(ToLoadString(IDS_SCMD_FINALIZE)));
}

void LJ_V7060::DisPlayCommandLog(int nRc, QString strCommandCode){

    /*打印日志功能*/

    QString strResult; //"USBOpen";EHTERNETOPEN
    if(nRc == LJV7IF_RC_OK){
        strResult=LoadStringW(ToLoadString(IDS_RESULT_OK));
        AddLog(strCommandCode,strResult,nRc);
    }else {
        strResult=LoadStringW(ToLoadString(IDS_RESULT_NG));//EHTERNETOPEN
        AddLog(strCommandCode,strResult,nRc);//结果类似于此：[USBOpen]:NG (0x1000)
        AddErrorLog(nRc);
    }
}

void LJ_V7060::AddLog(QString commandCode, QString result, int nRc)
{
    //为了得到此格式的日志：[USBOpen]:NG(0x1000)
    textBrowser->append('[' + commandCode + ']'+":" + result + "(0x" + QString::number(nRc, 16) + ')');
}

void LJ_V7060::AddLog(QString nDisplayFormat, QString strErrorMessage){
    //StatusLable->setText(nDisplayFormat+":"+strErrorMessage);
    textBrowser->append(nDisplayFormat+":"+strErrorMessage);
}
void LJ_V7060::AddLog(QString nDisplayFormat, int nRc){
    //StatusLable->setText(nDisplayFormat+":"+nRc);
    textBrowser->append(nDisplayFormat+":"+nRc);
}

void LJ_V7060::AddErrorLog(int nRc){
    if (nRc < 0x8000)
        {
            CommonErrorLog(nRc);// Common return code
        }
        else
        {
            IndividualErrorLog(nRc);// Individual return code
        }
}

void LJ_V7060::CommonErrorLog(int nRc){
    /*通用错误日志*/
    //QString format = LoadStringW(ToLoadString(IDS_RC_FORMAT));
    //LoadStringW(ToLoadString())
    switch (nRc)
        {
            case (int)LJV7IF_RC_OK://LoadStringW(ToLoadString(IDS_RC_OK))
                AddAdditionalErrorLog(IDS_RC_FORMAT, IDS_RC_OK);
                break;
            case (int)LJV7IF_RC_ERR_OPEN://LoadStringW(ToLoadString(IDS_RC_ERR_OPEN_DEVICE))
                AddAdditionalErrorLog(IDS_RC_FORMAT,IDS_RC_ERR_OPEN_DEVICE);
                break;
            case (int)LJV7IF_RC_ERR_NOT_OPEN:// LoadStringW(ToLoadString(IDS_RC_ERR_NO_DEVICE))
                AddAdditionalErrorLog(IDS_RC_FORMAT,IDS_RC_ERR_NO_DEVICE);
                break;
            case (int)LJV7IF_RC_ERR_SEND:// LoadStringW(ToLoadString(IDS_RC_ERR_SEND))
                AddAdditionalErrorLog(IDS_RC_FORMAT,IDS_RC_ERR_SEND);
                break;
            case (int)LJV7IF_RC_ERR_RECEIVE://LoadStringW(ToLoadString(IDS_RC_ERR_RECEIVE))
                AddAdditionalErrorLog(IDS_RC_FORMAT, IDS_RC_ERR_RECEIVE);
                break;
            case (int)LJV7IF_RC_ERR_TIMEOUT:
                AddAdditionalErrorLog(IDS_RC_FORMAT, LoadStringW(ToLoadString(IDS_RC_ERR_TIMEOUT)));
                break;
            case (int)LJV7IF_RC_ERR_PARAMETER://LoadStringW(ToLoadString(IDS_RC_ERR_PARAMETER))
                AddAdditionalErrorLog(IDS_RC_FORMAT, IDS_RC_ERR_PARAMETER);
                break;
            case (int)LJV7IF_RC_ERR_NOMEMORY://LoadStringW(ToLoadString(IDS_RC_ERR_NOMEMORY))
                AddAdditionalErrorLog(IDS_RC_FORMAT, IDS_RC_ERR_NOMEMORY);
                break;
            default://LoadStringW(ToLoadString(IDS_NOT_DEFINE_FORMAT))
                AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                break;
        }
}

void LJ_V7060::AddAdditionalErrorLog(QString nDisplayFormat, QString nErrorLog){
    //StatusLable->setText(nDisplayFormat+ ":" + nErrorLog);
    textBrowser->append(nDisplayFormat+":"+nErrorLog);
}

void LJ_V7060::IndividualErrorLog(int nRc){
    switch (m_sendCommand)
        {
            case SENDCOMMAND_REBOOTCONTROLLER:
                {
                    switch (nRc)
                    {
                        case 0x80A0://LoadStringW(ToLoadString(IDS_RC_FORMAT))
                            AddLog(IDS_RC_FORMAT, "Accessing the save area");
                            break;
                        default://LoadStringW(ToLoadString(IDS_NOT_DEFINE_FORMAT))
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_TRIGGER:
                {
                    switch (nRc)
                    {
                        case 0x8080://LoadStringW(ToLoadString(IDS_RC_FORMAT))
                            AddLog(IDS_RC_FORMAT,"The trigger mode is not [external trigger]");
                            break;
                        default://LoadStringW(ToLoadString(IDS_NOT_DEFINE_FORMAT))
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_STARTMEASURE:
            case SENDCOMMAND_STOPMEASURE:
                {
                    switch (nRc)
                    {
                        case 0x8080://LoadStringW(ToLoadString(IDS_RC_FORMAT))
                            AddLog(IDS_RC_FORMAT, "Batch measurements are off");
                            break;
                        case 0x80A0://LoadStringW(ToLoadString(IDS_RC_FORMAT))
                            AddLog(IDS_RC_FORMAT, "Batch measurement start processing could not be performed because the REMOTE terminal is off or the LASER_OFF terminal is on");
                            break;
                        default://LoadStringW(ToLoadString(IDS_NOT_DEFINE_FORMAT))
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_AUTOZERO:
            case SENDCOMMAND_TIMING:
            case SENDCOMMAND_RESET:
            case SENDCOMMAND_GETMEASUREMENTVALUE:
                {
                    switch (nRc)
                    {
                        case 0x8080://LoadStringW(ToLoadString(IDS_RC_FORMAT))
                            AddLog(IDS_RC_FORMAT, "The operation mode is [high-speed (profile only)]");
                            break;
                        default://LoadStringW(ToLoadString(IDS_NOT_DEFINE_FORMAT))
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_CHANGEACTIVEPROGRAM:
                {
                    switch (nRc)
                    {
                        case 0x8080://LoadStringW(ToLoadString(IDS_RC_FORMAT))
                            AddLog(IDS_RC_FORMAT, "The change program setting is [terminal]");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_GETPROFILE:
            case SENDCOMMAND_GETPROFILEADVANCE:
                {
                    switch (nRc)
                    {
                        case 0x8080:
                            AddLog(IDS_RC_FORMAT,"The operation mode is [advanced (with OUT measurement)]");
                            break;
                        case 0x8081:
                            AddLog(IDS_RC_FORMAT, "Batch measurements on and profile compression (time axis) off");
                            break;
                        case 0x80A0:
                            AddLog(IDS_RC_FORMAT, "No profile data");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_GETBATCHPROFILE:
            case SENDCOMMAND_GETBATCHPROFILEADVANCE:
                {
                    switch (nRc)
                    {
                        case 0x8080:
                            AddLog(IDS_RC_FORMAT,"The operation mode is [advanced (with OUT measurement)]");
                            break;
                        case 0x8081:
                            AddLog(IDS_RC_FORMAT,"Not [batch measurements on and profile compression (time axis) off]");
                            break;
                        case 0x80A0:
                            AddLog(IDS_RC_FORMAT, "No batch data (batch measurements not run even once)");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_STARTSTORAGE:
            case SENDCOMMAND_STOPSTORAGE:
                {
                    switch (nRc)
                    {
                        case 0x8080:
                            AddLog(IDS_RC_FORMAT, "The operation mode is [high-speed (profile only)]");
                            break;
                        case 0x8081:
                            AddLog(IDS_RC_FORMAT, "Storage target setting is [OFF] (no storage)");
                            break;
                        case 0x8082:
                            AddLog(IDS_RC_FORMAT, "The storage condition setting is not [terminal/command]");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_GETSTORAGESTATUS:
                {
                    switch (nRc)
                    {
                        case 0x8080:
                            AddLog(IDS_RC_FORMAT, "The operation mode is [high-speed (profile only)]");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_GETSTORAGEDATA:
                {
                    switch (nRc)
                    {
                        case 0x8080:
                            AddLog(IDS_RC_FORMAT, "The operation mode is [high-speed (profile only)]");
                            break;
                        case 0x8081:
                            AddLog(IDS_RC_FORMAT, "The storage target setting is not [OUT value]");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_GETSTORAGEPROFILE:
                {
                    switch (nRc)
                    {
                        case 0x8080:
                            AddLog(IDS_RC_FORMAT, "The operation mode is [high-speed (profile only)]");
                            break;
                        case 0x8081:
                            AddLog(IDS_RC_FORMAT, "The storage target setting is not profile, or batch measurements on and profile compression (time axis) off");
                            break;
                        case 0x8082:
                            AddLog(IDS_RC_FORMAT, "Batch measurements on and profile compression (time axis) off");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_GETSTORAGEBATCHPROFILE:
                {
                    switch (nRc)
                    {
                        case 0x8080:
                            AddLog(IDS_RC_FORMAT, "The operation mode is [high-speed (profile only)]");
                            break;
                        case 0x8081:
                            AddLog(IDS_RC_FORMAT, "The storage target setting is not profile, or batch measurements on and profile compression (time axis) off");
                            break;
                        case 0x8082:
                            AddLog(IDS_RC_FORMAT, "Not [batch measurements on and profile compression (time axis) off]");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_HIGHSPEEDDATAUSBCOMMUNICATIONINITALIZE:
            case SENDCOMMAND_HIGHSPEEDDATAETHERNETCOMMUNICATIONINITALIZE:
                {
                    switch (nRc)
                    {
                        case 0x8080:
                            AddLog(IDS_RC_FORMAT, "The operation mode is [advanced (with OUT measurement)]");
                            break;
                        case 0x80A1:
                            AddLog(IDS_RC_FORMAT, "Already performing high-speed communication error (for high-speed communication)");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            case SENDCOMMAND_PRESTARTHIGHSPEEDDATACOMMUNICATION:
            case SENDCOMMAND_STARTHIGHSPEEDDATACOMMUNICATION:
                {
                    switch (nRc)
                    {
                        case 0x8080:
                            AddLog(IDS_RC_FORMAT,"The operation mode is [advanced (with OUT measurement)]");
                            break;
                        case 0x8081:
                            AddLog(IDS_RC_FORMAT, "The data specified as the send start position does not exist");
                            break;
                        case 0x80A0:
                            AddLog(IDS_RC_FORMAT, "A high-speed data communication connection was not established");
                            break;
                        case 0x80A1:
                            AddLog(IDS_RC_FORMAT, "Already performing high-speed communication error (for high-speed communication)");
                            break;
                        case 0x80A4:
                            AddLog(IDS_RC_FORMAT, "The send target data was cleared");
                            break;
                        default:
                            AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                            break;
                    }
                }
                break;

            default:
                AddLog(IDS_NOT_DEFINE_FORMAT, nRc);
                break;
        }
}

QString LJ_V7060::LoadStringW(QString CommandStr){
   //判断"_"第一次出现的位置
   //对IDS_SCMD_INITIALIZE这样的字符串截取最终获得INITIALIZE
   int num = CommandStr.indexOf("_");
   QString strFirst = CommandStr.mid(num+1);
   int num2 = strFirst.indexOf("_");
   QString cmdStr = strFirst.mid(num2 + 1);
   return cmdStr;
}

void LJ_V7060::on_actionGetVersion_triggered()
{
    //获取动态库版本号
    int nVersion = LJV7IF_GetVersion();
    //StatusLable->setText(QString("Version:%1").arg(nVersion));
    textBrowser->append(QString("Version:%1").arg(nVersion));
}


