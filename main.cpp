#include "mainwindow.h"
#include "connection.h"

#include <QVariant>
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    qDebug()<<"Available drivers: ";
//    QStringList drivers=QSqlDatabase::drivers();
//    foreach (QString driver, drivers) {
//        qDebug()<<driver;
//    }

//    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("bigblue");
//    db.setDatabaseName("flightdb");
//    db.setUserName("acarlson");
//    db.setPassword("1234");
//    bool ok=db.open();

    if (!createConnection()) return 1;
    QSqlQuery query;
    query.exec("select * from student");
    while (query.next())
    {
        qDebug()<<query.value(0).toInt()<<query.value(1).toString();
    }
    return a.exec();
}
