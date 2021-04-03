/********************************************************************************
** Form generated from reading UI file 'communicationsettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATIONSETTINGDIALOG_H
#define UI_COMMUNICATIONSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommunicationSettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QRadioButton *EtherNetradioButton;
    QRadioButton *USBradioButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *IPlineEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *PortspinBox;

    void setupUi(QDialog *CommunicationSettingDialog)
    {
        if (CommunicationSettingDialog->objectName().isEmpty())
            CommunicationSettingDialog->setObjectName(QString::fromUtf8("CommunicationSettingDialog"));
        CommunicationSettingDialog->resize(408, 301);
        buttonBox = new QDialogButtonBox(CommunicationSettingDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CommunicationSettingDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 70, 131, 16));
        EtherNetradioButton = new QRadioButton(CommunicationSettingDialog);
        EtherNetradioButton->setObjectName(QString::fromUtf8("EtherNetradioButton"));
        EtherNetradioButton->setGeometry(QRect(20, 40, 131, 16));
        USBradioButton = new QRadioButton(CommunicationSettingDialog);
        USBradioButton->setObjectName(QString::fromUtf8("USBradioButton"));
        USBradioButton->setGeometry(QRect(20, 20, 89, 16));
        widget = new QWidget(CommunicationSettingDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 90, 241, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        IPlineEdit = new QLineEdit(widget);
        IPlineEdit->setObjectName(QString::fromUtf8("IPlineEdit"));

        horizontalLayout->addWidget(IPlineEdit);

        widget1 = new QWidget(CommunicationSettingDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 120, 241, 22));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        PortspinBox = new QSpinBox(widget1);
        PortspinBox->setObjectName(QString::fromUtf8("PortspinBox"));
        PortspinBox->setMaximum(65536);
        PortspinBox->setValue(24691);

        horizontalLayout_2->addWidget(PortspinBox);


        retranslateUi(CommunicationSettingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CommunicationSettingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CommunicationSettingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CommunicationSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *CommunicationSettingDialog)
    {
        CommunicationSettingDialog->setWindowTitle(QCoreApplication::translate("CommunicationSettingDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CommunicationSettingDialog", "\350\256\276\345\256\232\350\277\236\346\216\245\346\216\247\345\210\266\345\231\250\347\232\204IP\345\234\260\345\235\200", nullptr));
        EtherNetradioButton->setText(QCoreApplication::translate("CommunicationSettingDialog", "\344\273\245EtherNet\350\277\233\350\241\214\351\200\232\350\256\257", nullptr));
        USBradioButton->setText(QCoreApplication::translate("CommunicationSettingDialog", "\344\273\245USB\350\277\233\350\241\214\351\200\232\350\256\257", nullptr));
        label_2->setText(QCoreApplication::translate("CommunicationSettingDialog", "IP\345\234\260\345\235\200", nullptr));
        IPlineEdit->setText(QCoreApplication::translate("CommunicationSettingDialog", "169.254.168.154", nullptr));
        label_3->setText(QCoreApplication::translate("CommunicationSettingDialog", "\347\253\257\345\217\243\347\274\226\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommunicationSettingDialog: public Ui_CommunicationSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATIONSETTINGDIALOG_H
