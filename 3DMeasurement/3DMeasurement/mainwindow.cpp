#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include "errohandle.h"

#include "lj_v7060.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LJ_V7060 *equipment7060 = new LJ_V7060;
    equipment7060->show();
    initBoard();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initBoard()
{
    /*初始化设置*/
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("运行");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("停止");
    //板卡ID设置
    ui->boardID->setMaximum(8);
    ui->boardID->setMinimum(1);
    ui->boardID->setValue(1);
    //运动轴设置
    ui->Axis->setMaximum(8);
    ui->Axis->setMinimum(1);
    ui->Axis->setValue(1);
    //加速度设置
    ui->acceletation->setMaximum(3000);
    ui->acceletation->setMinimum(-3000);
    ui->acceletation->setValue(200);

    //减速度设置
    ui->deceleration->setMaximum(3000);
    ui->deceleration->setMinimum(-3000);
    ui->deceleration->setValue(200);
    //速度设置
    ui->velecity->setMaximum(3000);
    ui->velecity->setMinimum(-3000);
    ui->velecity->setValue(200);
    ui->targetPosition->setMaximum(50000);
    ui->targetPosition->setMinimum(-50000);

}

bool MainWindow::ErrorHandling(i32 error)
{
    ErroHandle errorHandle;
    if(error != 0){
        if (csr & NIMC_MODAL_ERROR_MSG){
            qDebug() <<(csr & NIMC_MODAL_ERROR_MSG);
            do{
                //Get the command ID, resource and the error code of the modal
                //	error from the error stack on the board
                flex_read_error_msg_rtn(ui->boardID->value(),&commandID,&resourceID,&errorCode);
                qDebug() << (csr & NIMC_MODAL_ERROR_MSG);
                //打印错误信息
                errorHandle.nimcDisplayError(errorCode,commandID,resourceID);

                //Read the Communication Status Register
                flex_read_csr_rtn(ui->boardID->value(),&csr);
                qDebug() << (csr & NIMC_MODAL_ERROR_MSG);
            }while(csr & NIMC_MODAL_ERROR_MSG);
        }
        else
        {   // Display regular error
            errorHandle.nimcDisplayError(err,0,0);
        }

        return false;
    }else{
    return true;
    }

}

void MainWindow::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button == ui->buttonBox->button(QDialogButtonBox::Ok)){
        //检查板卡是否处于开机复位状态
        err = flex_read_csr_rtn(ui->boardID->value(),&csr);
        bool ret = ErrorHandling(err);
        if(ret == false){
            return;
        }
        if(csr & NIMC_POWER_UP_RESET)
        {
            QMessageBox::warning(this,"警告","板卡处于复位状态");
            //复位
            //err = flex_initialize_controller(ui->boardID->value(),NULL);
            return;
        }
        //将加速度加载到指定轴
        err = flex_load_rpsps(ui->boardID->value(), ui->Axis->value(), NIMC_ACCELERATION, ui->acceletation->value(), 0xFF);
        ret = ErrorHandling(err);
        if(ret == false){
            return;
        }
        //将减速度加载到指定轴
        err = flex_load_rpsps(ui->boardID->value(), ui->Axis->value(), NIMC_DECELERATION, ui->deceleration->value(), 0xFF);
        ret = ErrorHandling(err);
        if(ret == false){
            return;
        }
        //将速度加载到指定轴
        err = flex_load_rpm(ui->boardID->value(), ui->Axis->value(), ui->velecity->value(), 0xFF);
        ret = ErrorHandling(err);
        if(ret == false){
            return;
        }
        //设置操作模式（可用下拉列表代替）
        //现在设置的是绝对位置模式
        err = flex_set_op_mode(ui->boardID->value(),ui->Axis->value(), NIMC_ABSOLUTE_POSITION);
        ret = ErrorHandling(err);
        if(ret == false){
            return;
        }
        //将目标位置加载到轴上
        err = flex_load_target_pos(ui->boardID->value(), ui->Axis->value(), ui->targetPosition->value(), 0xFF);
        //ErrorHandling(err);
        //启动选定轴
        err = flex_start(ui->boardID->value(), ui->Axis->value(), 0);
        ret = ErrorHandling(err);
        if(ret == false){
            return;
        }
        do{
            //读取当前轴的位置
            err = flex_read_pos_rtn(ui->boardID->value(), ui->Axis->value(),&current_position);
            ret = ErrorHandling(err);
            if(ret == false){
                return;
            }
            //读取通讯状态寄存器
            err = flex_read_csr_rtn(ui->boardID->value(),&csr);
            ret = ErrorHandling(err);
            if(ret == false){
                return;
            }
            if(csr & NIMC_MODAL_ERROR_MSG)
            {
                //停止电机
                flex_stop_motion(ui->boardID->value(),ui->Axis->value(), NIMC_DECEL_STOP,0);
                err = (csr & NIMC_MODAL_ERROR_MSG);
                ret = ErrorHandling(err);
                if(ret == false){
                    return;
                }
            }

        }while ( ! (axisStatus & (NIMC_MOVE_COMPLETE_BIT | NIMC_AXIS_OFF_BIT )));
        ui->progressBar->setValue(current_position);
        return;

    }else if(button == ui->buttonBox->button(QDialogButtonBox::Cancel)){
        //停止电机
        flex_stop_motion(ui->boardID->value(), ui->Axis->value(), NIMC_DECEL_STOP, 0);
    }

}
