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

    //以下代码的功能是实现右键菜单

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
    selectPlayMode=new QAction(this);
    selectPlayMode->setIcon(QIcon(":/icon/resources/icon/playMode.png"));
    selectPlayMode->setText(tr("选择播放模式"));
    playInOrder=new QAction(this);
    playInOrder->setIcon(QIcon(":/icon/resources/icon/inOrder.png"));
    playInOrder->setText(tr("顺序播放"));
    playSingleCycle=new QAction(this);
    playSingleCycle->setIcon(QIcon(":/icon/resources/icon/singleCycle.png"));
    playSingleCycle->setText(tr("单曲循环"));
    playShuffle=new QAction(this);
    playShuffle->setIcon(QIcon(":/icon/resources/icon/shuffle.png"));
    playShuffle->setText(tr("随机播放"));
    QMenu *selectPlayModeList=new QMenu(this);
    selectPlayModeList->addAction(playInOrder);
    selectPlayModeList->addAction(playSingleCycle);
    selectPlayModeList->addAction(playShuffle);
    selectPlayMode->setMenu(selectPlayModeList);  //end

    //歌曲信息
    songInfo=new QAction(this);
    songInfo->setIcon(QIcon(":/icon/resources/icon/songInfo.png"));
    songInfo->setText(tr("查看歌曲信息"));  //end

    //背景相关设置
    QSqlQuery wallpaperQuery;
    wallpaperQuery.exec("Select * from WALLPAPER_DATA");
    wallpaperQuery.next();
    QString wallpaperFileName=wallpaperQuery.value(0).toString();
    if (wallpaperFileName=="")
        wallpaper->load(":/background/resources/background/background_1.png");
    else
        wallpaper->load(wallpaperFileName);
    wallpaperQuery.exec("Select * from TRA_DATA");
    wallpaperQuery.next();
    QString values=wallpaperQuery.value(0).toString(); //透明度设置
    if (values=="")
        transparency=1;
    else
        transparency=values.toDouble();
    setWindowOpacity(transparency);
    palette.setBrush(QPalette::Window,QBrush(wallpaper->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(palette);  //end

    //右键菜单功能完成

    //播放器相关设置
    mediaPlayer=new QMediaPlayer(this);
    playList_1=new QMediaPlaylist(this);
    playList_1->setPlaybackMode(QMediaPlaylist::Loop);
    playList_2=new QMediaPlaylist(this);
    playList_2->setPlaybackMode(QMediaPlaylist::Loop);
    playList_3=new QMediaPlaylist(this);
    playList_3->setPlaybackMode(QMediaPlaylist::Loop);  //end

    //UI按钮设置
    ui->btnPlayOrPause->setIconSize(QSize(48,48));
    ui->btnPlayOrPause->setIcon(QIcon(":/icon/resources/icon/play.png"));
    ui->btnShowOrHideList->setIconSize(QSize(32,32));
    ui->btnShowOrHideList->setIcon(QIcon(":/icon/resources/icon/hidePlayList.png"));
    ui->btnSelectPlayMode->setIconSize(QSize(32,32));
    ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/inOrder.png"));
    ui->btnVolume->setIconSize(QSize(32,32));
    ui->btnVolume->setIcon(QIcon(":/icon/resources/icon/volume.png"));
    ui->songSlider->setToolTip(tr("播放进度"));
    ui->btnAddSong->setToolTip(tr("添加歌曲"));
    ui->btnPlayOrPause->setToolTip(tr("播放/暂停"));
    ui->btnPlayNextSong->setToolTip(tr("播放下一首"));
    ui->btnPlayPreSong->setToolTip(tr("播放上一首"));
    ui->btnSettings->setToolTip(tr("设置"));
    ui->btnSetBackGround->setToolTip(tr("设置背景"));
    ui->btnVolume->setToolTip(tr("设置音量"));
    ui->btnSelectPlayMode->setToolTip(tr("顺序播放"));
    ui->btnLocalMusic->setToolTip(tr("本地音乐"));
    ui->btnMyFavourite->setToolTip(tr("我喜欢"));
    ui->btnPlayList->setToolTip(tr("播放列表"));
    ui->btnMiniStyle->setToolTip(tr("切换到迷你模式"));
    ui->btnShowOrHideList->setToolTip(tr("隐藏播放列表"));
    ui->btnClose->setToolTip(tr("关闭"));
    ui->btnMinimize->setToolTip(tr("最小化"));
    ui->volumeSlider->hide();
    ui->volumeSlider->setValue(100);
    ui->songSlider->setValue(0);
    ui->playList->currentIndex(0);
    ui->btnLocalMusic->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(:/icon/resources/icon/localMusic.png);"
            "background-color: rgba(255, 255, 255,100);"
            "border-style:outset;"
            "border-color:rgba(255,255,255,0);"
            "border-radius:4px;"
        "}"
        "QPushButton:hover"
        "{"
            "background-color: rgb(255, 255, 255,100);"
        "}"
        "QPushButton:pressed"
        "{"
            "background-color: rgba(95, 95, 95,100);"
            "border-color:rgba(255,255,255,30);"
            "border-style:inset;"
            "color:rgba(0,0,0,100);"
        "}");
    //end

    //tableModel设置
    model_1=new QSqlTableModel(this);
    model_1->setTable("HAHAHA");
    model_1->select();
    model_2=new QSqlTableModel(this);
    model_2->setTable("I_LIKE_DATA");
    model_2->select();
    model_3=new QSqlTableModel(this);
    model_3->setTable("NIMA");
    model_3->select();  //这段代码写得不明所以，但肯定有用，end

    //信号和槽相关设置,要先写完预设的函数

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePlayState()  //更新当前播放歌曲信息
{
    QString playState=tr("正在播放:  ");
    if (mediaPlayer->isMetaDataAvailable())
    {
        QString musicTitle=mediaPlayer->metaData(QStringLiteral("Title")).toString();
        if (!musicTitle.isEmpty())
            playState+=title;
        else
            playState+=tr("未知歌曲");
        playState+="-";
        QString musicAuthor=mediaPlayer->metaData(QStringLiteral("Author")).toString();
        if (!musicAuthor.isEmpty())
            playState+=musicAuthor;
        else
            playState+=tr("未知作者");
    }
    ui->labPlayState->setText(playState);

}
