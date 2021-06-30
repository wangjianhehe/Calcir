#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QIcon>//图标头文件

#include <cmath>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("齿轮分度圆计算器");
    this->setWindowIcon(QIcon("D:/qt_file/helloworld/icon.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString tmpNum1, tmpNum2;
    bool ok1, ok2,ok3,ok4;
    double m1 = 0, z1 = 0, R1 = 0, D1 = 0;
    // 获取输入m,z
    QString m = ui->lineEdit_3->text();
    QString z = ui->lineEdit_4->text();
    QString D = ui->lineEdit->text();
    QString R = ui->lineEdit_2->text();
    // 转化
    m1 = m.toFloat(&ok1);
    z1 = z.toFloat(&ok2);
    D1 = D.toFloat(&ok3);
    R1 = R.toFloat(&ok4);
    //所有数据都没有
    if (!ok1&&!ok2&&!ok3&&!ok4) {
       QMessageBox::information(NULL, "提示", "输入有误，请输入正确的数值！", QMessageBox::Yes , QMessageBox::Yes);
        return;
    }
    //有m和z，计算R和D
    if (ok1&&ok2&&!ok3&&!ok4) {
        // 进行计算
        D1 = m1 * z1;
        R1 = 0.5*D1;

        // 将数据回填到另外一个输入框当中
        tmpNum1.setNum(D1);
        ui->lineEdit->setText(tmpNum1);
        tmpNum2.setNum(R1);
        ui->lineEdit_2->setText(tmpNum2);
    }
    //有R，计算D
    if (!ok1&&!ok2&&!ok3&&ok4) {
        // 进行计算
        D1 = 2*R1;

        // 将数据回填到另外一个输入框当中
        tmpNum1.setNum(D1);
        ui->lineEdit->setText(tmpNum1);
    }

    //有D，计算R
    if (!ok1&&!ok2&&ok3&&!ok4) {
        // 进行计算
        R1 = 0.5*D1;

        // 将数据回填到另外一个输入框当中
        tmpNum1.setNum(R1);
        ui->lineEdit_2->setText(tmpNum1);
    }
    //有D和z，计算R和m
    if (!ok1&&ok2&&ok3&&!ok4) {
        // 进行计算
        R1 = 0.5*D1;
        m1 = D1/z1;

        // 将数据回填到另外一个输入框当中
        tmpNum1.setNum(R1);
        ui->lineEdit_2->setText(tmpNum1);
        tmpNum2.setNum(m1);
        ui->lineEdit_3->setText(tmpNum2);
    }
    //有D和m，计算R和z
    if (ok1&&!ok2&&ok3&&!ok4) {
        // 进行计算
        R1 = 0.5*D1;
        z1 = D1/m1;

        // 将数据回填到另外一个输入框当中
        tmpNum1.setNum(R1);
        ui->lineEdit_2->setText(tmpNum1);
        tmpNum2.setNum(z1);
        ui->lineEdit_4->setText(tmpNum2);
    }
    //有R和m，计算D和z
    if (ok1&&!ok2&&!ok3&&ok4) {
        // 进行计算
        D1 = 2*R1;
        z1 = D1/m1;

        // 将数据回填到另外一个输入框当中
        tmpNum1.setNum(D1);
        ui->lineEdit->setText(tmpNum1);
        tmpNum2.setNum(z1);
        ui->lineEdit_4->setText(tmpNum2);
    }
    //有R和z，计算D和m
    if (!ok1&&ok2&&!ok3&&ok4) {
        // 进行计算
        D1 = 2*R1;
        m1 = D1/z1;

        // 将数据回填到另外一个输入框当中
        tmpNum1.setNum(D1);
        ui->lineEdit->setText(tmpNum1);
        tmpNum2.setNum(m1);
        ui->lineEdit_3->setText(tmpNum2);
    }
    //R和D重复给出
    if (ok3&&ok4) {
       QMessageBox::information(NULL, "提示", "输入有误，半径和直径不能同时提供，请输入正确的数值！", QMessageBox::Yes , QMessageBox::Yes);
        return;
    }
    //不能同时提供（齿数、模数）和（半径、直径）两组数据
    if (ok1&&ok2&&(ok3||ok4)) {
       QMessageBox::information(NULL, "提示", "输入有误，不能同时提供（齿数、模数）和（半径、直径）两组数据，请输入正确的数值！", QMessageBox::Yes , QMessageBox::Yes);
        return;
    }
    //只提供m和z中的一个数据
    if (((!ok1&&ok2)||(ok1&&!ok2))&&!ok3&&!ok4) {
       QMessageBox::information(NULL, "提示", "输入有误，只提供齿数或模数无法计算，请输入正确的数值！", QMessageBox::Yes , QMessageBox::Yes);
        return;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(0);
    ui->lineEdit_2->setText(0);
    ui->lineEdit_3->setText(0);
    ui->lineEdit_4->setText(0);
}
