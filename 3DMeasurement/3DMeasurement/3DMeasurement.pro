QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DeviceData.cpp \
    communicationsettingdialog.cpp \
    errohandle.cpp \
    lj_v7060.cpp \
    main.cpp \
    mainwindow.cpp \
    openethernetdialog.cpp

HEADERS += \
    DeviceData.h \
    ErrorString.h \
    Include/MotnCnst.h \
    Include/NIMCExampleData.h \
    Include/flexcomp.h \
    Include/flexmotn.h \
    Include/nimcBasicTypes.h \
    Resource.h \
    communicationsettingdialog.h \
    errohandle.h \
    lj_v7060.h \
    mainwindow.h \
    openethernetdialog.h

FORMS += \
    communicationsettingdialog.ui \
    lj_v7060.ui \
    mainwindow.ui \
    openethernetdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
#添加运动控制卡库
win32: LIBS += -L$$PWD/lib/ -lFlexMS32

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

#添加LJ-V7060库#win32:
#LIBS += -LC:\Users\59592\Desktop\3DMeasurement\3DMeasurement -lLJV7_IF
LIBS += -L$$PWD/ -lLJV7_IF
INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

RESOURCES += \
    Resource/resource.qrc
