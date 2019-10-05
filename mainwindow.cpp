#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "binarysearchtree.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug()<< "Привет";

//    tree.insert(6);//first
//    tree.insert(8);
//    tree.insert(1);
//    tree.insert(3);
//    tree.insert(9);
//    tree.insert(6);//second
//    tree.insert(4);
//    tree.insert(3);
//    tree.insert(8);
//    tree.insert(9);
//    tree.walk();
//    tree.remove(3);
//    tree.walk();
    tree.insert(3);//third
    tree.insert(1);
    tree.insert(0);
    tree.insert(-1);
    tree.insert(9);
    tree.insert(5);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);
    tree.insert(10);
    tree.walk();
    tree.remove(8);
    tree.walk();
}

void MainWindow::on_pushButton_2_clicked()
{
    tree.insert(ui->spinBox->value());
}

void MainWindow::on_pushButton_3_clicked()
{
     bool res = tree.find(ui->spinBox_2->value());
     QMessageBox msgBox;
       msgBox.setText(res?"Найдено":"Не найдено");
       msgBox.exec();
}
