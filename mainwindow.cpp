#include "mainwindow.h"
#include "ui_mainwindow.h"

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


}

MainWindow::~MainWindow()
{
    delete ui;
}
