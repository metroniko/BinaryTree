#include "mainwindow.h"
#include "linearhashtable.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LinearHashTable table(7);
    table.insert(3,"три");
    table.insert(1, "один");
    table.insert(8, "восемь");
    table.insert(15, "пятнадцать");

    qDebug()<<table.contain(3);
    qDebug()<<table.contain(1);
    qDebug()<<table.contain(8);
    table.remove(8);
    qDebug()<<table.contain(8);
    qDebug()<<table.contain(15);
    qDebug()<<table.contain(14);
    table.print();
//    table.print();
//    table.get(15);
    return 0;
}
