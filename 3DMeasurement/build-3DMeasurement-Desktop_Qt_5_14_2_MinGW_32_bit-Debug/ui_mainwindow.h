/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *boardID;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *Axis;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *targetPosition;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLCDNumber *current_position;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSpinBox *velecity;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpinBox *acceletation;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QSpinBox *deceleration;
    QDialogButtonBox *buttonBox;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(858, 606);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 40, 821, 231));
        formLayoutWidget = new QWidget(widget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 791, 71));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        boardID = new QSpinBox(formLayoutWidget);
        boardID->setObjectName(QString::fromUtf8("boardID"));
        boardID->setFont(font);

        horizontalLayout->addWidget(boardID);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        Axis = new QSpinBox(formLayoutWidget);
        Axis->setObjectName(QString::fromUtf8("Axis"));
        Axis->setFont(font);

        horizontalLayout_2->addWidget(Axis);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        targetPosition = new QSpinBox(formLayoutWidget);
        targetPosition->setObjectName(QString::fromUtf8("targetPosition"));
        targetPosition->setFont(font);
        targetPosition->setMinimum(-50000);
        targetPosition->setMaximum(50000);

        horizontalLayout_3->addWidget(targetPosition);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        current_position = new QLCDNumber(formLayoutWidget);
        current_position->setObjectName(QString::fromUtf8("current_position"));
        current_position->setFont(font);
        current_position->setAcceptDrops(false);
        current_position->setProperty("value", QVariant(0.000000000000000));
        current_position->setProperty("intValue", QVariant(0));

        horizontalLayout_5->addWidget(current_position);


        horizontalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_6->addWidget(label_5);

        velecity = new QSpinBox(formLayoutWidget);
        velecity->setObjectName(QString::fromUtf8("velecity"));
        velecity->setFont(font);

        horizontalLayout_6->addWidget(velecity);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_7->addWidget(label_6);

        acceletation = new QSpinBox(formLayoutWidget);
        acceletation->setObjectName(QString::fromUtf8("acceletation"));
        acceletation->setFont(font);

        horizontalLayout_7->addWidget(acceletation);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_8->addWidget(label_7);

        deceleration = new QSpinBox(formLayoutWidget);
        deceleration->setObjectName(QString::fromUtf8("deceleration"));
        deceleration->setFont(font);

        horizontalLayout_8->addWidget(deceleration);


        horizontalLayout_7->addLayout(horizontalLayout_8);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_7);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(570, 180, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(230, 130, 301, 31));
        progressBar->setMinimum(-50000);
        progressBar->setMaximum(50000);
        progressBar->setValue(0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 858, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Board ID", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Axis", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Target Position", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Current Position ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Velocity(RPM)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Acceleration(RPS/S)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Deceleration(RPS/S)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
