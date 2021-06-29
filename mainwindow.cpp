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
    bool ok1, ok2;
    double m1 = 0, z1 = 0, R = 0, D = 0;
    // 获取输入m,z
    QString m = ui->lineEdit_3->text();
    QString z = ui->lineEdit_4->text();
    // 转化
    m1 = m.toFloat(&ok1);
    if (!ok1) {
       QMessageBox::information(NULL, "提示", "输入有误，请输入正确的模数值！", QMessageBox::Yes , QMessageBox::Yes);
        return;
    }
    z1 = z.toFloat(&ok2);
    if (!ok2) {
       QMessageBox::information(NULL, "提示", "输入有误，请输入正确的齿数值！", QMessageBox::Yes , QMessageBox::Yes);
        return;
    }
    // 进行计算
    D = m1 * z1;
    R = 0.5*D;

    // 将数据回填到另外一个输入框当中
    tmpNum1.setNum(D);
    ui->lineEdit->setText(tmpNum1);
    tmpNum2.setNum(R);
    ui->lineEdit_2->setText(tmpNum2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(0);
    ui->lineEdit_2->setText(0);
    ui->lineEdit_3->setText(0);
    ui->lineEdit_4->setText(0);
}
