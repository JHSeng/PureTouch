#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
//    db.setHostName("jhseng");
//    db.setUserName("jhseng");
//    db.setPassword("1234");
    if (!db.open())
    {
        QMessageBox::critical(0,"cannot open database",
                              "Unable to establish a database connection.",
                              QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;
    query.exec("create table student (id int primary key, " //创造表
               "name varchar(20))");
    query.exec("insert into student values(0, 'LiMing')");
    query.exec("insert into student values(1, 'LiuTao')");
    query.exec("insert into student values(2, 'WangHong')"); //插入数据

    //明天再搞

    return true;
}

#endif // CONNECTION_H
