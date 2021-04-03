#include "openethernetdialog.h"
#include "ui_openethernetdialog.h"
#include <QDebug>
#include "lj_v7060.h"
#include <QMessageBox>

#define ToLoadString(x)  #x    //可将宏名转换为字符串

OpenEthernetDialog::OpenEthernetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenEthernetDialog),
    m_xvPortNum(24691)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);

}

OpenEthernetDialog::~OpenEthernetDialog()
{
    delete ui;
}

LJV7IF_ETHERNET_CONFIG OpenEthernetDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    LJV7IF_ETHERNET_CONFIG ethernetConfig;
    int port = ui->lineEdit_port->text().toInt();
    address_ip = ui->lineEdit_ip->text();
    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button){

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

        }else{
            QMessageBox::warning(this,"警告","请输入正确的端口号");
        }
    }else{
        emit cancleClick();
        this->close();
    }
    return ethernetConfig;
}

LJV7IF_ETHERNET_CONFIG OpenEthernetDialog::GetEthernetConfig(){
    LJV7IF_ETHERNET_CONFIG ethernetConfig = this->on_buttonBox_clicked(ui->buttonBox->button(QDialogButtonBox::Ok));
    return ethernetConfig;
}


