#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>
#include <QDir>
#include <QMenu>
#include <QPainter>
#include <qmath.h>
#include <QShortcut>
#include <QMessageBox>
#include <QProgressBar>
#include <QProgressDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAutoFillBackground(true);

    //添加音乐到列表，没有加上快捷键
    addToLocalMusic=new QAction(this);
    addToMyFavourite=new QAction(this);
    addToPlaylist=new QAction(this);
    addToLocalMusic->setIcon(QIcon(":/resources/icon/addToLocalMusic.png"));
    addToLocalMusic->setText(tr("添加到本地音乐列表"));
    addToMyFavourite->setIcon(QIcon(":/resources/icon/myFavourite.png"));
    addToMyFavourite->setText(tr("添加到我喜欢"));
    addToPlaylist->setIcon(QIcon(":/resources/icon/playList.png"));
    addToPlaylist->setText(tr("添加到播放列表"));

    QMenu *menu1=new QMenu(this);
    menu1->addAction(addToLocalMusic);
    menu1->addAction(addToMyFavourite);
    menu1->addAction(addToPlaylist);  //end

    //播放器背景设置
    setBackGround=new QAction(this);
    setBackGround_1=new QAction(this);
    setBackGround_2=new QAction(this);
    setBackground_customize=new QAction(this);
    setBackGround->setIcon(QIcon(":/icon/resources/icon/skin.png"));
    setBackGround->setText(tr("设置皮肤"));
    setBackGround_1->setIcon(QIcon(":/icon/resources/icon/background_1.png"));
    setBackGround_1->setText(tr("预设皮肤1"));
    setBackGround_2->setIcon(QIcon(":/icon/resources/icon/background_2.png"));
    setBackGround_2->setText(tr("预设皮肤2"));
    setBackground_customize->setIcon(QIcon(":/icon/resources/icon/customize.png"));
    setBackground_customize->setText(tr("自定义皮肤"));
    QMenu *setBackGroundMenu=new QMenu(this);
    setBackGroundMenu->addAction(setBackGround_1);
    setBackGroundMenu->addAction(setBackGround_2);
    setBackGroundMenu->addAction(setBackground_customize);
    setBackGround->setMenu(setBackGroundMenu);
    ui->btnSetBackGround->setMenu(setBackGroundMenu); //end

    //关于PureTouch
    showAbout=new QAction(this);
    showAbout->setIcon(QIcon(":/icon/resources/icon/about.png"));
    showAbout->setText(tr("关于PureTouch")); //end

    //清除各种播放列表
    clearList->setIcon(QIcon(":/icon/resources/icon/clearList.png"));
    clearList->setText(tr("清除列表"));
    clearAllList->setIcon(QIcon(":/icon/resources/icon/allList.png"));
    clearAllList->setText(tr("清除所有列表"));
    clearLocalMusic->setIcon(QIcon(":/icon/resources/icon/addToLocalMusic.png"));
    clearLocalMusic->setText(tr("清除本地音乐列表"));
    clearMyFavourite->setIcon(QIcon(":/icon/resources/icon/myFavourite.png"));
    clearMyFavourite->setText(tr("清除我喜欢列表"));
    clearPlaylist->setIcon(QIcon(":/icon/resources/icon/playList.png"));
    clearPlaylist->setText(tr("清除播放列表"));
    QMenu *clearSongList=new QMenu(this);
    clearSongList->addAction(clearAllList);
    clearSongList->addAction(clearLocalMusic);
    clearSongList->addAction(clearMyFavourite);
    clearSongList->addAction(clearPlaylist);
    clearList->setMenu(clearSongList);  //end

    //控制歌曲播放
    preSong=new QAction(this);
    preSong->setIcon(QIcon(":/icon/resources/icon/preSong.png"));
    preSong->setText(tr("播放上一首"));
    nextSong=new QAction(this);
    nextSong->setIcon(QIcon(":/icon/resources/icon/nextSong.png"));
    nextSong->setText(tr("播放下一首"));
    playOrPause=new QAction(this);
    playOrPause->setIcon(QIcon(":/icon/resources/icon/play.png"));
    playOrPause->setText(tr("播放/暂停"));  //end

    //选择播放模式

}

MainWindow::~MainWindow()
{
    delete ui;
}
