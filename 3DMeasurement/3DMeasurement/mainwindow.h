#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "Include/flexmotn.h"
#include "Include/NIMCExample.h"
#include "Include/nimcBasicTypes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
//    u8 boardID;
//    u8 axis;
//    f64 acceleration;
//    f64 deceleration;
//    f64 velocity;
    u16 csr = 0;//通讯状态寄存器
    u16 axisStatus;
    i32 current_position;
    i32 err = -1;

    //Variables for modal error handling
    u16 commandID;  // The commandID of the function
    u16 resourceID;	// The resource ID
    i32 errorCode;	// Error code
private:
    void initBoard();
    bool ErrorHandling(i32 error);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
