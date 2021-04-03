#ifndef OPENETHERNETDIALOG_H
#define OPENETHERNETDIALOG_H

#include <QDialog>
#include <QPushButton>
#include "LJV7_IF.h"

namespace Ui {
class OpenEthernetDialog;
}

class OpenEthernetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenEthernetDialog(QWidget *parent = nullptr);
    ~OpenEthernetDialog();
    LJV7IF_ETHERNET_CONFIG GetEthernetConfig();
private slots:
    LJV7IF_ETHERNET_CONFIG on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::OpenEthernetDialog *ui;
    //DWORD m_dwIPAddress;//unsigned long ==DWORD
    int m_xvPortNum;
    QString address_ip;
signals:
    void cancleClick();

};

#endif // OPENETHERNETDIALOG_H
