/********************************************************************************
** Form generated from reading UI file 'openethernetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENETHERNETDIALOG_H
#define UI_OPENETHERNETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenEthernetDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ip;
    QLineEdit *lineEdit_ip;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_port;
    QLineEdit *lineEdit_port;

    void setupUi(QDialog *OpenEthernetDialog)
    {
        if (OpenEthernetDialog->objectName().isEmpty())
            OpenEthernetDialog->setObjectName(QString::fromUtf8("OpenEthernetDialog"));
        OpenEthernetDialog->resize(361, 222);
        buttonBox = new QDialogButtonBox(OpenEthernetDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(OpenEthernetDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 60, 195, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_ip = new QLabel(layoutWidget);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));

        horizontalLayout->addWidget(label_ip);

        lineEdit_ip = new QLineEdit(layoutWidget);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));

        horizontalLayout->addWidget(lineEdit_ip);

        layoutWidget1 = new QWidget(OpenEthernetDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 110, 195, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_port = new QLabel(layoutWidget1);
        label_port->setObjectName(QString::fromUtf8("label_port"));

        horizontalLayout_2->addWidget(label_port);

        lineEdit_port = new QLineEdit(layoutWidget1);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));

        horizontalLayout_2->addWidget(lineEdit_port);


        retranslateUi(OpenEthernetDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OpenEthernetDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OpenEthernetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OpenEthernetDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenEthernetDialog)
    {
        OpenEthernetDialog->setWindowTitle(QCoreApplication::translate("OpenEthernetDialog", "Dialog", nullptr));
        label_ip->setText(QCoreApplication::translate("OpenEthernetDialog", "Ip \345\234\260\345\235\200", nullptr));
        lineEdit_ip->setText(QCoreApplication::translate("OpenEthernetDialog", "169.254.168.154", nullptr));
        label_port->setText(QCoreApplication::translate("OpenEthernetDialog", "Port", nullptr));
        lineEdit_port->setText(QCoreApplication::translate("OpenEthernetDialog", "24691", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenEthernetDialog: public Ui_OpenEthernetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENETHERNETDIALOG_H
