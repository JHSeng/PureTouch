#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlQuery>

static bool creatConnection()
{
    QSqlDatabase dataBase=QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("music.db");
    dataBase.open();
    if (!dataBase.open())
        return false;
    QSqlQuery query;
    query.exec(QString("create table HAHAHA (id int primary key,musicName varchar,fileName varchar,biaoji int)"));
    query.exec(QString("create table I_LIKE_DATA (id int primary key,musicName varchar,fileName varchar)"));
    query.exec(QString("create table NIMA (id int primary key,musicName varchar,fileName varchar)"));
    query.exec(QString("create table WALLPAPER_DATA (fileName varchar primary key)"));
    query.exec(QString("create table TRA_DATA (TRA double primary key)"));
    query.exec(QString("create table Bizi_DATA (fileName varchar primary key)"));
    query.exec(QString("create table Toumin_DATA (TouMin double primary key)"));
    return true;
}

#endif // CONNECTION_H
