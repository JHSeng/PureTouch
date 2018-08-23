#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlResult>
#include <QSqlRecord>

static bool CreateConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("music.db");
    if(!db.open())
    {
        qDebug()<<"Database error: "<<db.lastError().text();
        return 1;
    }
    QSqlQuery query(db);
    query.exec(QString("create table HAHAHA (id int primary key,MusicName varchar,FileName varchar,biaoji int)"));
    query.exec(QString("create table I_LIKE_DATA (id int primary key,MusicName varchar,FileName varchar)"));
    query.exec(QString("create table NIMA (id int primary key,MusicName varchar,FileName varchar)"));
    query.exec(QString("create table WALLPAPER_DATA (FileName varchar primary key)"));
    query.exec(QString("create table TRA_DATA (TRA double primary key)"));
    query.exec(QString("create table Bizi_DATA (FileName varchar primary key)"));
    query.exec(QString("create table Toumin_DATA (TouMin double primary key)"));
    return true;
}

#endif // CONNECTION_H
