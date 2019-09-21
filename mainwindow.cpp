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
    BinarySearchTree tree;
    tree.insert(6);
    tree.insert(1);
    tree.insert(8);
    tree.insert(3);
    tree.insert(9);
    qDebug()<<tree.find(10);

}
