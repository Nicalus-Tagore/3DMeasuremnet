/********************************************************************************
** Form generated from reading UI file 'lj_v7060.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LJ_V7060_H
#define UI_LJ_V7060_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LJ_V7060
{
public:
    QAction *actionNew;
    QAction *actionUSB;
    QAction *actionEntherner;
    QAction *actionCommClose;
    QAction *actionGetVersion;
    QAction *actionCommunicationSetting;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuCommunication;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *LJ_V7060)
    {
        if (LJ_V7060->objectName().isEmpty())
            LJ_V7060->setObjectName(QString::fromUtf8("LJ_V7060"));
        LJ_V7060->resize(769, 595);
        actionNew = new QAction(LJ_V7060);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionUSB = new QAction(LJ_V7060);
        actionUSB->setObjectName(QString::fromUtf8("actionUSB"));
        actionEntherner = new QAction(LJ_V7060);
        actionEntherner->setObjectName(QString::fromUtf8("actionEntherner"));
        actionCommClose = new QAction(LJ_V7060);
        actionCommClose->setObjectName(QString::fromUtf8("actionCommClose"));
        actionGetVersion = new QAction(LJ_V7060);
        actionGetVersion->setObjectName(QString::fromUtf8("actionGetVersion"));
        actionCommunicationSetting = new QAction(LJ_V7060);
        actionCommunicationSetting->setObjectName(QString::fromUtf8("actionCommunicationSetting"));
        centralwidget = new QWidget(LJ_V7060);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LJ_V7060->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LJ_V7060);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 769, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuCommunication = new QMenu(menubar);
        menuCommunication->setObjectName(QString::fromUtf8("menuCommunication"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        LJ_V7060->setMenuBar(menubar);
        statusbar = new QStatusBar(LJ_V7060);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy);
        LJ_V7060->setStatusBar(statusbar);
        toolBar = new QToolBar(LJ_V7060);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        LJ_V7060->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuCommunication->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuCommunication->addAction(actionUSB);
        menuCommunication->addAction(actionEntherner);
        menuCommunication->addAction(actionCommClose);
        menuCommunication->addAction(actionCommunicationSetting);
        menuHelp->addAction(actionGetVersion);

        retranslateUi(LJ_V7060);

        QMetaObject::connectSlotsByName(LJ_V7060);
    } // setupUi

    void retranslateUi(QMainWindow *LJ_V7060)
    {
        LJ_V7060->setWindowTitle(QCoreApplication::translate("LJ_V7060", "MainWindow", nullptr));
#if QT_CONFIG(statustip)
        LJ_V7060->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        actionNew->setText(QCoreApplication::translate("LJ_V7060", "New", nullptr));
        actionUSB->setText(QCoreApplication::translate("LJ_V7060", "USB", nullptr));
        actionEntherner->setText(QCoreApplication::translate("LJ_V7060", "Entherner", nullptr));
        actionCommClose->setText(QCoreApplication::translate("LJ_V7060", "CommClose", nullptr));
        actionGetVersion->setText(QCoreApplication::translate("LJ_V7060", "GetVersion", nullptr));
        actionCommunicationSetting->setText(QCoreApplication::translate("LJ_V7060", "CommunicationSetting", nullptr));
        menuFile->setTitle(QCoreApplication::translate("LJ_V7060", "File", nullptr));
        menuCommunication->setTitle(QCoreApplication::translate("LJ_V7060", "Setting", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("LJ_V7060", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("LJ_V7060", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LJ_V7060: public Ui_LJ_V7060 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LJ_V7060_H
