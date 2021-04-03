#include "communicationsettingdialog.h"
#include "ui_communicationsettingdialog.h"
#include <QDebug>
#include "LJV7_IF.h"
#include "LJV7_ErrorCode.h"
#include <QMessageBox>


CommunicationSettingDialog::CommunicationSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommunicationSettingDialog),
    m_xvCurrentDeviceID(0)
{
    ui->setupUi(this);
    this->setWindowTitle("PC通讯设定");
    ui->USBradioButton->setChecked(true);//默认以USB通讯按钮选中

}

CommunicationSettingDialog::~CommunicationSettingDialog()
{
    delete ui;
}

void CommunicationSettingDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    int nRc = LJV7IF_RC_OK;
    nRc = LJV7IF_Initialize();
    if(ui->USBradioButton->isChecked()){
        if(ui->buttonBox->button(QDialogButtonBox::Ok)==button){
            nRc = LJV7IF_UsbOpen(m_xvCurrentDeviceID);
            CheckReturnCode(nRc);//检查是否通讯成功
            /*
            if(nRc != LJV7IF_RC_OK){
                QMessageBox::warning(this,"警告","连接失败");
                qDebug()<<"error";
            }*/

        }else if(ui->buttonBox->button((QDialogButtonBox::Cancel)) == button){
            this->close();
        }

    }else if(ui->EtherNetradioButton->isChecked()){
        if(ui->buttonBox->button(QDialogButtonBox::Ok)==button){
            LJV7IF_ETHERNET_CONFIG ethernetConfig;
            int port = ui->PortspinBox->text().toInt();
            address_ip = ui->IPlineEdit->text();
            if( port > 0 && port < 65535){
                m_xvPortNum = port;
                //获取IP地址
                int num = address_ip.indexOf(".");
                QString str1 = address_ip.left(num);//192
                QString left1 = address_ip.mid(num+1);//"168.0.1"

                int num2 = left1.indexOf(".");
                QString str2 = left1.left(num2);//168
                QString left2 = left1.mid(num2 +1);//0.1

                QString str3 = left2.left(left2.indexOf("."));//0
                QString left3 = left2.mid(left2.indexOf(".") +1);//1
                QString str4 = left3;//1

                ethernetConfig.abyIpAddress[0] = str1.toUInt();
                ethernetConfig.abyIpAddress[1] = str2.toUInt();
                ethernetConfig.abyIpAddress[2] = str3.toUInt();
                ethernetConfig.abyIpAddress[3] = str4.toUInt();

                ethernetConfig.wPortNo         = (WORD)m_xvPortNum;
                ethernetConfig.reserve[0]      = (BYTE)0;
                ethernetConfig.reserve[1]      = (BYTE)0;
            }
            for(int i = 0; i< 4; i++){
                //验证IP地址是否正确，后期可以删除
                qDebug()<<ethernetConfig.abyIpAddress[i];
            }
            nRc = LJV7IF_EthernetOpen(m_xvCurrentDeviceID, &ethernetConfig);
            if(nRc != LJV7IF_RC_OK){
                QMessageBox::warning(this,"警告","连接失败");
            }
        }else if(ui->buttonBox->button((QDialogButtonBox::Cancel)) == button){
            this->close();
        }
    }

}

void CommunicationSettingDialog::CheckReturnCode(int nRc)
{
    //判断每一步操作是否正确
    if(nRc != LJV7IF_RC_OK){
        QMessageBox::warning(this,"警告","连接失败");
    }
}

void CommunicationSettingDialog::on_USBradioButton_clicked()
{
    //如果usb按钮选中，其他按钮不可用
   ui->EtherNetradioButton->setChecked(false);
   ui->IPlineEdit->setEnabled(false);
   ui->PortspinBox->setEnabled(false);
}

void CommunicationSettingDialog::on_EtherNetradioButton_clicked()
{
    //如果网线通讯按钮被选中，usb按钮不可用
    ui->USBradioButton->setChecked(false);
    ui->IPlineEdit->setEnabled(true);
    ui->PortspinBox->setEnabled(true);
}
