#include "mainwindow.h"
#include "randombst.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    RandomBST random;
    random.insert(7);
    random.insert(8);
    random.insert(9);
    random.insert(3);
    random.insert(1);
    random.insert(10);
    random.insert(2);
    random.walk();
    random.remove(1);
    random.walk();
    return a.exec();
}
