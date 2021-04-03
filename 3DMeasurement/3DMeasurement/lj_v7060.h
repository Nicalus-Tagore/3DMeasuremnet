#ifndef LJ_V7060_H
#define LJ_V7060_H

#include <QMainWindow>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>
#include "Resource.h"

#include "LJV7_IF.h"
#include "LJV7_ErrorCode.h"
#include "DeviceData.h"

namespace Ui {
class LJ_V7060;
}

class LJ_V7060 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LJ_V7060(QWidget *parent = nullptr);
    ~LJ_V7060();

public:
    void Initialize_Device();//初始化设备
    void initStatusLabel();//初始化状态栏
    void DisPlayCommandLog(int nRc, QString  strCommandCode);
    void AddLog(QString commandCode, QString result, int nRc);
    void AddLog(QString nDisplayFormat, int nRc);
    void AddLog(QString nDisplayFormat, QString strErrorMessage);
    QString LoadStringW(QString CommandStr);//获取执行接口字符串
    void AddErrorLog(int nRc);
    void CommonErrorLog(int nRc);
    void IndividualErrorLog(int nRc);
    void AddAdditionalErrorLog(QString nDisplayFormat, QString nErrorLog);
    bool CheckReturnCode(int nRc);//检查每一步调用操作是否成功
private slots:

    void on_actionUSB_triggered();//用USB连接设备

    void on_actionEntherner_triggered();//用网线连接设备

    void on_actionCommClose_triggered();//停止通讯

    void on_actionGetVersion_triggered();//获取DLL版本号

    void on_actionCommunicationSetting_triggered();

    void btn_start_clicked();//startBtn槽函数

private:
    Ui::LJ_V7060 *ui;

    //在状态栏设置标签显示信息
    QLabel *StatusLable;
    QTextBrowser *textBrowser;
    QPushButton * StartBtn;//开始监控按钮

    int m_xvCurrentDeviceID;//指定设备id
    int m_xvSendPos;
    int m_xvReceiveProfileNum;
    static LJV7IF_PROFILE_INFO m_profileInfo;
    CDeviceData m_aDeviceData[LJV7IF_DEVICE_COUNT];//连接状态：设备状态码

    typedef enum
        {
            SENDCOMMAND_NONE,											// None
            SENDCOMMAND_REBOOTCONTROLLER,								// Restart
            SENDCOMMAND_TRIGGER,										// Trigger
            SENDCOMMAND_STARTMEASURE,									// Start measurement
            SENDCOMMAND_STOPMEASURE,									// Stop measurement
            SENDCOMMAND_AUTOZERO,										// Auto zero
            SENDCOMMAND_TIMING,											// Timing
            SENDCOMMAND_RESET,											// Reset
            SENDCOMMAND_CHANGEACTIVEPROGRAM,							// Program switch
            SENDCOMMAND_GETMEASUREMENTVALUE,							// Get measurement results
            SENDCOMMAND_GETPROFILE,										// Get profiles
            SENDCOMMAND_GETBATCHPROFILE,								// Get batch profiles (operation mode "high-speed (profile only)")
            SENDCOMMAND_GETPROFILEADVANCE,								// Get profiles (operation mode "advanced (with OUT measurement)")
            SENDCOMMAND_GETBATCHPROFILEADVANCE,							// Get batch profiles (operation mode "advanced (with OUT measurement)").
            SENDCOMMAND_STARTSTORAGE,									// Start storage
            SENDCOMMAND_STOPSTORAGE,									// Stop storage
            SENDCOMMAND_GETSTORAGESTATUS,								// Get storage status
            SENDCOMMAND_REQUESTSTORAGE,									// Manual storage request
            SENDCOMMAND_GETSTORAGEDATA,									// Get storage data
            SENDCOMMAND_GETSTORAGEPROFILE,								// Get profile storage data
            SENDCOMMAND_GETSTORAGEBATCHPROFILE,							// Get batch profile storage data.
            SENDCOMMAND_HIGHSPEEDDATAUSBCOMMUNICATIONINITALIZE,			// Initialize USB high-speed data communication
            SENDCOMMAND_HIGHSPEEDDATAETHERNETCOMMUNICATIONINITALIZE,	// Initialize Ethernet high-speed data communication
            SENDCOMMAND_PRESTARTHIGHSPEEDDATACOMMUNICATION,				// Request preparation before starting high-speed data communication
            SENDCOMMAND_STARTHIGHSPEEDDATACOMMUNICATION,				// Start high-speed data communication
        } SENDCOMMAND;
        SENDCOMMAND m_sendCommand;
};

#endif // LJ_V7060_H
