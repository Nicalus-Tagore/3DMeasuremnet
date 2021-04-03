#ifndef COMMUNICATIONSETTINGDIALOG_H
#define COMMUNICATIONSETTINGDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class CommunicationSettingDialog;
}

class CommunicationSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommunicationSettingDialog(QWidget *parent = nullptr);
    ~CommunicationSettingDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void CheckReturnCode(int nRc);

    void on_USBradioButton_clicked();

    void on_EtherNetradioButton_clicked();

private:
    Ui::CommunicationSettingDialog *ui;
private:

     int m_xvCurrentDeviceID;//指定设备id
     int m_xvPortNum;
     QString address_ip;
};

#endif // COMMUNICATIONSETTINGDIALOG_H
