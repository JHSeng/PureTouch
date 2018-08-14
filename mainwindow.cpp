#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "miniwindow.h"

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
#include <QFileDialog>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    miniwindow=new MiniWindow();
    miniwindow->setWindowFlags(Qt::FramelessWindowHint);
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
    playList_LocalMusic=new QMediaPlaylist(this);
    playList_LocalMusic->setPlaybackMode(QMediaPlaylist::Loop);
    playList_MyFavourite=new QMediaPlaylist(this);
    playList_MyFavourite->setPlaybackMode(QMediaPlaylist::Loop);
    playList_PlayList=new QMediaPlaylist(this);
    playList_PlayList->setPlaybackMode(QMediaPlaylist::Loop);  //end

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
    ui->playList->setCurrentIndex(0);
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

    connect(mediaPlayer,&QMediaPlayer::metaDataAvailableChanged,this,&MainWindow::updatePlayState);
    connect(mediaPlayer,&QMediaPlayer::positionChanged,this,&MainWindow::updatePlayPosition);
    connect(mediaPlayer,&QMediaPlayer::durationChanged,this,&MainWindow::updatePlayDuration);
    connect(ui->songSlider,&QSlider::sliderMoved,mediaPlayer,&QMediaPlayer::setPosition);
    connect(playList_LocalMusic,&QMediaPlaylist::currentIndexChanged,this,&MainWindow::updateLocalMusicList);
    connect(playList_MyFavourite,&QMediaPlaylist::currentIndexChanged,this,&MainWindow::updateMyFavouriteList);
    connect(playList_PlayList,&QMediaPlaylist::currentIndexChanged,this,&MainWindow::updatePlaylistList);
    connect(addToLocalMusic,&QAction::triggered,this,&MainWindow::addToLocalMusic_slot);
    connect(addToMyFavourite,&QAction::triggered,this,&MainWindow::addToMyFavourite_slot);
    connect(addToPlaylist,&QAction::triggered,this,&MainWindow::addToPlaylist_slot);
    connect(setBackGround_1,&QAction::triggered,this,&MainWindow::setBackGround_1_slot);
    connect(setBackGround_2,&QAction::triggered,this,&MainWindow::setBackGround_2_slot);
    connect(setBackground_customize,&QAction::triggered,this,&MainWindow::setBackground_customize_slot);
    connect(clearLocalMusic,&QAction::triggered,this,&MainWindow::clearLocalMusic_slot);
    connect(clearMyFavourite,&QAction::triggered,this,&MainWindow::clearMyFavourite_slot);
    connect(clearPlaylist,&QAction::triggered,this,&MainWindow::clearPlaylist_slot);
    connect(clearAllList,&QAction::triggered,this,&MainWindow::clearAllList_slot);
    connect(preSong,&QAction::triggered,this,&MainWindow::preSong_slot);
    connect(nextSong,&QAction::triggered,this,&MainWindow::nextSong_slot);
    connect(playOrPause,&QAction::triggered,this,&MainWindow::playOrPause_slot);
    connect(playInOrder,&QAction::triggered,this,&MainWindow::playInOrder_slot);
    connect(playShuffle,&QAction::triggered,this,&MainWindow::playShuffle_slot);
    connect(playSingleCycle,&QAction::triggered,this,&MainWindow::playSingleCycle_slot);
    connect(ui->volumeSlider,&QSlider::valueChanged,this,&MainWindow::changeVolume);
    connect(mediaPlayer,&QMediaPlayer::stateChanged,this,&MainWindow::musicStateChange);
    //第332行实现miniStyle的信号和槽
    connect(songInfo,&QAction::triggered,this,&MainWindow::songInfo_slot);
    connect(playList_LocalMusic,&QMediaPlaylist::playbackModeChanged,this,&MainWindow::PlaylistModel_slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

static QString Time(qint64 time)
{
    qint64 seconds=time/100;
    const qint64 minutes=seconds/60;
    seconds-=minutes*60;
    return QStringLiteral("%1:%2").arg(minutes,2,10,QLatin1Char('0')).arg(seconds,2,10,QLatin1Char('0'));
}

void MainWindow::updatePlayState()  //更新当前播放歌曲信息
{
    QString playState=tr("正在播放: ");
    if (mediaPlayer->isMetaDataAvailable())
    {
        QString musicTitle=mediaPlayer->metaData(QStringLiteral("Title")).toString();
        if (!musicTitle.isEmpty())
            playState+=musicTitle;
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
    if (mediaPlayer->playlist()==playList_MyFavourite)
    {
        ui->btnAddToCurrentList->setIcon(QIcon(":/icon/resources/icon/liked.png"));
        ui->btnAddToCurrentList->setToolTip(tr("已经喜欢"));
    }
    else if (mediaPlayer->playlist()==playList_PlayList)
    {
        ui->btnAddToCurrentList->setIcon(QIcon(":/icon/resources/icon/addedToPlayList.png"));
        ui->btnAddToCurrentList->setToolTip(tr("已在播放列表"));
    }
    else
    {
        QSqlQuery query;
        query.exec("select * from HAHAHA");
        model_1->setTable("HAHAHA");
        model_1->select();
        int row=playList_LocalMusic->currentIndex();
        int flag=model_1->data(model_1->index(row,3)).toInt();
        if (flag)
        {
            ui->btnAddToCurrentList->setIcon(QIcon(":/icon/resources/icon/liked.png"));
            ui->btnAddToCurrentList->setToolTip(tr("已经喜欢"));
        }
        else
        {
            ui->btnAddToCurrentList->setIcon(QIcon(":/icon/resources/icon/addToMyFavourite.png"));
            ui->btnAddToCurrentList->setToolTip(tr("添加到我喜欢"));
        }
    }
}

void MainWindow::updatePlayPosition(qint64 position) //更新播放位置
{
    ui->songSlider->setValue(position);
    ui->labTime->setText(Time(position)+"/"+Time(mediaPlayer->duration()));
}

void MainWindow::updatePlayDuration(qint64 duration) //更新播放进度
{
    ui->songSlider->setRange(0,duration);
    ui->songSlider->setEnabled(duration>0);
    ui->songSlider->setPageStep(duration/10);
}

void MainWindow::setBtnLocalMusicLightUp() //使本地歌曲按钮变亮
{
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
    ui->btnMyFavourite->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(::/icon/resources/icon/myFavouriteList.png);"
            "background-color: rgba(255, 255, 255,0);"
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
    ui->btnPlayList->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(:/icon/resources/icon/playList.png);"
            "background-color: rgba(255, 255, 255,0);"
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
}

void MainWindow::setBtnMyFavouriteLightUp() //使我喜欢按钮变亮
{
    ui->btnLocalMusic->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(:/icon/resources/icon/localMusic.png);"
            "background-color: rgba(255, 255, 255,0);"
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
    ui->btnMyFavourite->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(::/icon/resources/icon/myFavouriteList.png);"
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
    ui->btnPlayList->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(:/icon/resources/icon/playList.png);"
            "background-color: rgba(255, 255, 255,0);"
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
}

void MainWindow::setBtnPlaylistLightUp() //使播放列表按钮变亮
{
    ui->btnLocalMusic->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(:/icon/resources/icon/localMusic.png);"
            "background-color: rgba(255, 255, 255,0);"
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
    ui->btnMyFavourite->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(::/icon/resources/icon/myFavouriteList.png);"
            "background-color: rgba(255, 255, 255,0);"
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
    ui->btnPlayList->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(:/icon/resources/icon/playList.png);"
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
}

void MainWindow::setNoBtnLightUp() //使三个按钮变暗
{
    ui->btnLocalMusic->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(:/icon/resources/icon/localMusic.png);"
            "background-color: rgba(255, 255, 255,0);"
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
    ui->btnMyFavourite->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(::/icon/resources/icon/myFavouriteList.png);"
            "background-color: rgba(255, 255, 255,0);"
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
    ui->btnPlayList->setStyleSheet(
        "QPushButton"
        "{"
            "background-image: url(:/icon/resources/icon/playList.png);"
            "background-color: rgba(255, 255, 255,0);"
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
}

void MainWindow::updateLocalMusicList(int value)
{
    ui->localMusicList->item(value)->setSelected(true);
}

void MainWindow::updateMyFavouriteList(int value)
{
    ui->myFavouriteList->item(value)->setSelected(true);
}

void MainWindow::updatePlaylistList(int value)
{
    ui->playlistList->item(value)->setSelected(true);
}

void MainWindow::changeVolume(int value)
{
    if (value==0)
        ui->btnVolume->setIcon(QIcon(":/icon/resources/icon/muteVolume.png"));
    else
        ui->btnVolume->setIcon(QIcon(":/icon/resources/icon/volume.png"));
    mediaPlayer->setVolume(value);
}

void MainWindow::on_btnLocalMusic_clicked()
{
    ui->playList->setCurrentIndex(0);
    setBtnLocalMusicLightUp();
}

void MainWindow::on_btnMyFavourite_clicked()
{
    ui->playList->setCurrentIndex(1);
    setBtnMyFavouriteLightUp();
}

void MainWindow::on_btnPlayList_clicked()
{
    ui->playList->setCurrentIndex(2);
    setBtnPlaylistLightUp();
}

void MainWindow::songInfo_slot()
{
    int row;
    QString strPlayState=ui->labPlayState->text();
    QString author=strPlayState.split("-").last();
    QString musicName=strPlayState.remove("-"+author).split(": ").last();
    QString time=ui->labTime->text().split("/").last();
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        row=playList_LocalMusic->currentIndex();

        model_1->setTable("HAHAHA");
        model_1->select();
        QString filePath=model_1->data(model_1->index(row,2)).toString();
        QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名: %1  \n"
                                                 "作者: %2  \n"
                                                 "时间: %3  \n"
                                                 "文件路径: %4\n").arg(musicName).arg(author).arg(time).arg(filePath));
    }
    else if (mediaPlayer->playlist()==playList_MyFavourite)
    {
        row=playList_MyFavourite->currentIndex();
        model_2->setTable("I_LIKE_DATA");
        model_2->select();
        QString filePath=model_2->data(model_2->index(row,2)).toString();
        QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名: %1  \n"
                                                 "作者: %2  \n"
                                                 "时间: %3  \n"
                                                 "文件路径: %4\n").arg(musicName).arg(author).arg(time).arg(filePath));
    }
    else
    {
        row=playList_PlayList->currentIndex();
        model_3->setTable("NIMA");
        model_3->select();
        QString filePath=model_3->data(model_3->index(row,2)).toString();
        QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名: %1  \n"
                                                 "作者: %2  \n"
                                                 "时间: %3  \n"
                                                 "文件路径: %4\n").arg(musicName).arg(author).arg(time).arg(filePath));
    }
}

void MainWindow::clearLocalMusic_slot()
{
    int value=QMessageBox::information(this,tr("清除本地音乐列表"),tr("确定清除本地音乐列表?                              ."),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if (value==QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("select * from HAHAHA");
        query.exec("delect from HAHAHA");
        ui->localMusicList->clear();
        playList_LocalMusic->clear();
    }
}

void MainWindow::clearMyFavourite_slot() //这个函数的数据库操作不是很懂
{
    int value=QMessageBox::information(this,tr("清除我喜欢列表"),tr("确定清除我喜欢列表?                              ."),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if (value==QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("select * from I_LIKE_DATA");
        query.exec("delete from I_LIKE_DATA");
        query.exec("select * from HAHAHA");
        query.prepare(QString("update HAHAHA set biaoji = ? where biaoji = 1"));
        query.bindValue(0,0);
        query.exec();
        ui->myFavouriteList->clear();
        playList_MyFavourite->clear();
    }
}

void MainWindow::clearPlaylist_slot()
{
    int value=QMessageBox::information(this,tr("清除播放列表"),tr("确定清除播放列表?                              ."),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if (value==QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("select * from NIMA");
        query.exec("delete from NIMA");
        ui->playlistList->clear();
        playList_PlayList->clear();
    }
}

void MainWindow::clearAllList_slot()
{
    int value=QMessageBox::information(this,tr("清除所有列表"),tr("确定清除所有列表?                              ."),QMessageBox::Yes|QMessageBox::No);
    if (value==QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("delete from HAHAHA");
        query.exec("delete from I_LIKE_DATA");
        query.exec("delete from NIMA");
        ui->localMusicList->clear();
        ui->myFavouriteList->clear();
        ui->playlistList->clear();
        playList_LocalMusic->clear();
        playList_MyFavourite->clear();
        playList_PlayList->clear();
    }
}

void MainWindow::addToLocalMusic_slot()
{
    ui->playList->setCurrentIndex(0);
    setBtnLocalMusicLightUp();
    QSqlQuery query;
    query.exec("select * from HAHAHA");
    QStringList list=QFileDialog::getOpenFileNames(this,tr("文件"),"D:/",tr("音频文件(*.mp3)"));
    if (!list.isEmpty())
    {
        QProgressDialog *progressDialog=new QProgressDialog(this);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(100);
        progressDialog->resize(500,200);
        progressDialog->setWindowTitle(tr("添加歌曲"));
        progressDialog->setLabelText(tr("添加中                              ."));
        progressDialog->setCancelButtonText(tr("关闭"));
        progressDialog->setRange(0,list.size()-1);
        for (int i=0;i<list.size();i++)
        {
            QListWidgetItem *item=new QListWidgetItem;
            item->setIcon(QIcon(":/icon/resources/icon/addedToPlayList.png"));
            QString path=QDir::toNativeSeparators(list.at(i));
            progressDialog->setValue(i);
            if (i==list.size()-1)
                progressDialog->close();
            if (progressDialog->wasCanceled())
                progressDialog->close();
            if (!path.isEmpty())
            {
                playList_LocalMusic->addMedia(QUrl::fromLocalFile(path));
                QString name=path.split("\\").last();
                name.remove(QString(".mp3"));
                item->setText(QString("%1").arg(name));
                ui->localMusicList->addItem(item);
                query.exec(QString("insert into HAHAHA values (%1,'%2','%3',%4)").arg(qrand()%10000).arg(name).arg(path).arg(0));
            }
        }
    }
}

void MainWindow::addToMyFavourite_slot()
{
    ui->playList->setCurrentIndex(1);
    setBtnMyFavouriteLightUp();
    QSqlQuery query;
    query.exec("select *from I_LIKE_DATA");
    QStringList list=QFileDialog::getOpenFileNames(this,tr("所有文件"),"D:/",tr("音频文件(*.mp3)"));
    if (!list.isEmpty())
    {
        QProgressDialog *progressDialog=new QProgressDialog(this);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->resize(500,200);
        progressDialog->setMinimumDuration(100);
        progressDialog->setWindowTitle(tr("添加歌曲"));
        progressDialog->setLabelText(tr("添加中                              ."));
        progressDialog->setCancelButtonText(tr("关闭"));
        progressDialog->setRange(0,list.size()-1);
        for (int i=0;i<list.size();i++)
        {
            QListWidgetItem *item=new QListWidgetItem;
            item->setIcon(QIcon(":/icon/resources/icon/myFavouriteList.png"));
            QString path=QDir::toNativeSeparators(list.at(i));
            progressDialog->setValue(i);
            if (i==list.size()-1)
                progressDialog->close();
            if (progressDialog->wasCanceled())
                progressDialog->close();
            if (!path.isEmpty())
            {
                playList_MyFavourite->addMedia(QUrl::fromLocalFile(path));
                QString name=path.split("\\").last();
                name.remove(QString(".mp3"));
                item->setText(QString("%1").arg(name));
                ui->myFavouriteList->addItem(item);
                query.exec(QString("insert into I_LIKE_DATA values (%1,'%2','%3')").arg(qrand()%10000).arg(name).arg(path));
            }
        }
    }
}

void MainWindow::addToPlaylist_slot()
{
    ui->playList->setCurrentIndex(2);
    setBtnPlaylistLightUp();
    QSqlQuery query;
    query.exec("select *from NIMA");
    QStringList list=QFileDialog::getOpenFileNames(this,tr("所有文件"),"D:/",tr("音频文件(*.mp3)"));
    if(!list.isEmpty())
    {
        QProgressDialog *progressDialog=new QProgressDialog(this);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(100);
        progressDialog->resize(500,200);
        progressDialog->setWindowTitle("添加歌曲");
        progressDialog->setLabelText("添加中                              .");
        progressDialog->setCancelButtonText(tr("关闭"));
        progressDialog->setRange(0,list.size()-1);
        for (int i=0;i<list.size();i++)
        {
            QListWidgetItem *item=new QListWidgetItem;
            item->setIcon(QIcon(":/icon/resources/icon/addMusic.png"));
            QString path=QDir::toNativeSeparators(list.at(i));
            progressDialog->setValue(i);
            if (i==list.size()-1)
                progressDialog->close();
            if (progressDialog->wasCanceled())
                progressDialog->close();
            if (!path.isEmpty())
            {
                playList_PlayList->addMedia(QUrl::fromLocalFile(path));
                QString name=path.split("\\").last();
                name.remove(QString(".mp3"));
                item->setText(QString("%1").arg(name));
                ui->playlistList->addItem(item);
                query.exec(QString("insert into NIMA values (%1,'%2','%3')").arg(qrand()%10000).arg(name).arg(path));
            }
        }
    }
}

void MainWindow::setBackGround_1_slot()
{
    QString fileName=":/background/resources/background/background_1.png";
    QSqlQuery query;
    query.exec("delete from WALLPAPER_DATA");
    query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(fileName));
    wallpaper->load(fileName);
    palette.setBrush(QPalette::Window,QBrush(wallpaper->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(palette);
}

void MainWindow::setBackGround_2_slot()
{
    QString fileName=":/background/resources/background/background_2.jpg";
    QSqlQuery query;
    query.exec("delete from WALLPAPER_DATA");
    query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(fileName));
    wallpaper->load(fileName);
    palette.setBrush(QPalette::Window,QBrush(wallpaper->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(palette);
}

void MainWindow::setBackground_customize_slot()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("文件"),"D:/",tr("图片文件(*jpg *png)"));
    if (fileName!="")
    {
        QSqlQuery query;
        query.exec("delete from WALLPAPER_DATA");
        query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(fileName));
        wallpaper->load(fileName);
        palette.setBrush(QPalette::Window,QBrush(wallpaper->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
        setPalette(palette);
    }
}

void MainWindow::preSong_slot()
{
    int currentIndex;
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        currentIndex=playList_LocalMusic->currentIndex();
        ui->playList->setCurrentIndex(0);
        setBtnLocalMusicLightUp();
        if (--currentIndex<0)
            currentIndex=0;
        playList_LocalMusic->setCurrentIndex(currentIndex);
    }
    else if (mediaPlayer->playlist()==playList_MyFavourite)
    {
        currentIndex=playList_MyFavourite->currentIndex();
        ui->playList->setCurrentIndex(1);
        setBtnMyFavouriteLightUp();
        if (--currentIndex<0)
            currentIndex=0;
        playList_MyFavourite->setCurrentIndex(currentIndex);
    }
    else if (mediaPlayer->playlist()==playList_PlayList)
    {
        currentIndex=playList_PlayList->currentIndex();
        ui->playList->setCurrentIndex(2);
        setBtnPlaylistLightUp();
        if (--currentIndex<0)
            currentIndex=0;
        playList_PlayList->setCurrentIndex(currentIndex);
    }
    mediaPlayer->play();
}

void MainWindow::nextSong_slot()
{
    int currentIndex;
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        currentIndex=playList_LocalMusic->currentIndex();
        ui->playList->setCurrentIndex(0);
        setBtnLocalMusicLightUp();
        if (++currentIndex==playList_LocalMusic->mediaCount())
            currentIndex=0;
        playList_LocalMusic->setCurrentIndex(currentIndex);
    }
    else if (mediaPlayer->playlist()==playList_MyFavourite)
    {
        currentIndex=playList_MyFavourite->currentIndex();
        ui->playList->setCurrentIndex(1);
        setBtnMyFavouriteLightUp();
        if (++currentIndex==playList_MyFavourite->mediaCount())
            currentIndex=0;
        playList_MyFavourite->setCurrentIndex(currentIndex);
    }
    else if (mediaPlayer->playlist()==playList_PlayList)
    {
        currentIndex=playList_PlayList->currentIndex();
        ui->playList->setCurrentIndex(2);
        setBtnPlaylistLightUp();
        if (++currentIndex==playList_PlayList->mediaCount())
            currentIndex=0;
        playList_PlayList->setCurrentIndex(currentIndex);
    }
    mediaPlayer->play();
}

void MainWindow::playOrPause_slot() //右键菜单
{
    if (mediaPlayer->state()==QMediaPlayer::PlayingState)
        mediaPlayer->pause();
    else
        mediaPlayer->play();
}

void MainWindow::playInOrder_slot()
{
    ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/inOrder.png"));
    ui->btnSelectPlayMode->setToolTip(tr("顺序播放"));
    playList_LocalMusic->setPlaybackMode(QMediaPlaylist::Loop);
    playList_MyFavourite->setPlaybackMode(QMediaPlaylist::Loop);
    playList_PlayList->setPlaybackMode(QMediaPlaylist::Loop);
}

void MainWindow::playShuffle_slot()
{
    ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/shuffle.png"));
    ui->btnSelectPlayMode->setToolTip((tr("随机播放")));
    playList_LocalMusic->setPlaybackMode(QMediaPlaylist::Random);
    playList_MyFavourite->setPlaybackMode(QMediaPlaylist::Random);
    playList_PlayList->setPlaybackMode(QMediaPlaylist::Random);
}

void MainWindow::playSingleCycle_slot()
{
    ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/singleCycle.png"));
    ui->btnSelectPlayMode->setToolTip((tr("单曲循环")));
    playList_LocalMusic->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    playList_MyFavourite->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    playList_PlayList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}

void MainWindow::musicStateChange(QMediaPlayer::State state)
{
    if (state==QMediaPlayer::PlayingState)
    {
        ui->btnPlayOrPause->setIcon(QIcon(":/icon/resources/icon/mediaPause.png"));
        ui->btnPlayOrPause->setToolTip(tr("暂停"));
    }
    else
    {
        ui->btnPlayOrPause->setIcon(QIcon(":/icon/resources/icon/mediaPlay.png"));
        ui->btnPlayOrPause->setToolTip(tr("播放"));
    }
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    menu=new QMenu(this);
    menu->addAction(addToLocalMusic);
    menu->addAction(addToMyFavourite);
    menu->addAction(addToPlaylist);
    menu->addAction(preSong);
    menu->addAction(nextSong);
    menu->addAction(playOrPause);
    menu->addAction(clearPlaylist);
    menu->addAction(selectPlayMode);
    menu->addAction(setBackGround);
    menu->addAction(clearList);
    menu->addAction(songInfo);
    menu->exec(QCursor::pos());
}

void MainWindow::Action1_slot()
{
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        if (ui->localMusicList->item(playList_LocalMusic->currentIndex())->isSelected())
        {
            if (mediaPlayer->state()==QMediaPlayer::PlayingState)
                mediaPlayer->pause();
            else
                mediaPlayer->play();
        }
        else
        {
            playList_LocalMusic->setCurrentIndex(ui->localMusicList->currentIndex().row());
            mediaPlayer->play();
        }
    }
    else
    {
        mediaPlayer->setPlaylist(playList_LocalMusic);
        playList_LocalMusic->setCurrentIndex(ui->localMusicList->currentIndex().row());
        mediaPlayer->play();
    }
}

void MainWindow::Action2_slot()
{
    model_1->setTable("HAHAHA");
    model_1->select();
    int row=ui->localMusicList->currentIndex().row();
    int flag=model_1->data(model_1->index(row,3)).toInt();
    if (flag==0)
    {
        QString Text=ui->localMusicList->item(row)->text();
        QListWidgetItem *ITEMM=new QListWidgetItem;
        ITEMM->setIcon(QIcon(":/icon/resources/icon/addToMyFavourite.png"));
        ITEMM->setText(QString("%1").arg(Text));
        ui->myFavouriteList->addItem(ITEMM);
        QSqlQuery query;
        playList_MyFavourite->addMedia(playList_LocalMusic->media(row));
        model_1->setTable("HAHAHA");
        model_1->select();
        QString musicName=model_1->data(model_1->index(row,1)).toString();
        QString fileName=model_1->data(model_1->index(row,2)).toString();
        model_1->setData(model_1->index(row,3),1);
        model_1->submitAll();
        query.exec("select * from I_LIKE_DATA");
        query.exec(QString("insert into I_LIKE_DATA values (%1,'%2',%3)").arg(qrand()%10000).arg(musicName).arg(fileName));
        setBtnMyFavouriteLightUp();
        if (mediaPlayer->playlist()==playList_LocalMusic)
        {
            if (playList_LocalMusic->currentIndex()==row)
            {
                ui->btnAddToCurrentList->setIcon(QIcon(":/icon/resources/icon/liked.png"));
                ui->btnAddToCurrentList->setToolTip(tr("我喜欢"));
            }
        }
    }
    else
        QMessageBox::information(this,tr("提示"),tr("该歌曲已添加                              ."),QMessageBox::Yes);
}

void MainWindow::Action3_slot()
{
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        int Row=playList_LocalMusic->currentIndex();
        int row=ui->localMusicList->currentIndex().row();
        if (row<Row)
        {
            int Position;
            if (mediaPlayer->state()==QMediaPlayer::PlayingState)
                Position=mediaPlayer->position();
            playList_LocalMusic->setCurrentIndex(0);
            ui->localMusicList->takeItem(row);
            playList_LocalMusic->removeMedia(row,row);
            model_1->setTable("HAHAHA");
            model_1->select();
            model_1->removeRow(row);
            model_1->submitAll();
            mediaPlayer->setPlaylist(playList_LocalMusic);
            playList_LocalMusic->setCurrentIndex(Row-1);
            mediaPlayer->setPosition(Position);
            ui->songSlider->setValue(Position);
            mediaPlayer->play();
        }
        else
        {
            ui->localMusicList->takeItem(row);
            playList_LocalMusic->removeMedia(row,row);
            model_1->setTable("HAHAHA");
            model_1->select();
            model_1->removeRow(row);
            model_1->submitAll();
        }
    }
    else
    {
        int row=ui->localMusicList->currentIndex().row();
        ui->localMusicList->takeItem(row);
        playList_LocalMusic->removeMedia(row,row);
        model_1->setTable("HAHAHA");
        model_1->select();
        model_1->removeRow(row);
        model_1->submitAll();
    }
}

void MainWindow::Action4_slot()
{
    int row=ui->localMusicList->currentIndex().row();
    QString Text=ui->localMusicList->item(row)->text();
    QListWidgetItem *ITEMM=new QListWidgetItem;
    ITEMM->setIcon(QIcon(":/icon/resources/icon/addMusic.png"));
    ITEMM->setToolTip(QString("%1").arg(Text));
    ui->playlistList->addItem(ITEMM);
    model_1->setTable("HAHAHA");
    model_1->select();
    playList_PlayList->addMedia(playList_LocalMusic->media(row));
    QSqlQuery query;
    QString musicName=model_1->data(model_1->index(row,1)).toString();
    QString fileName=model_1->data(model_1->index(row,2)).toString();
    query.exec("select * from NIMA");
    query.exec(QString("insert into NIMA values (%1,'%2','%3')").arg(qrand()%10000).arg(musicName).arg(fileName));
    ui->playList->setCurrentIndex(2);
    setBtnPlaylistLightUp();
}

void MainWindow::Action5_slot()
{
    int row=ui->localMusicList->currentIndex().row();
    QString temp=ui->localMusicList->currentIndex().data().toString();
    QString musicName=temp.split(" - ").last();
    QString author=temp.remove(" - "+musicName);
    model_1->setTable("HAHAHA");
    model_1->select();
    QString fileName=model_1->data(model_1->index(row,2)).toString();
    QString time;
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        //原本这里是row=playList_LocalMusic->currentIndex()，感觉有错
        if (row==playList_LocalMusic->currentIndex())
            time=Time(mediaPlayer->duration());
        else
            time="00:00";
    }
    else
        time="00:00";
    QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名 : %1  \n"
                                             "作者 : %2 \n"
                                             "时长 : %3\n "
                                             "文件路径 : %4\n").arg(musicName).arg(author).arg(time).arg(fileName));

}

void MainWindow::Action1_2_slot()
{
    if (mediaPlayer->playlist()==playList_MyFavourite)
    {
        if (ui->myFavouriteList->item(playList_MyFavourite->currentIndex())->isSelected())
        {
            if (mediaPlayer->state()==QMediaPlayer::PlayingState)
                mediaPlayer->pause();
            else
                mediaPlayer->play();
        }
        else
        {
            playList_MyFavourite->setCurrentIndex(ui->myFavouriteList->currentIndex().row());
            mediaPlayer->play();
        }
    }
    else
    {
        mediaPlayer->setPlaylist(playList_MyFavourite);
        playList_MyFavourite->setCurrentIndex(ui->myFavouriteList->currentIndex().row());
        mediaPlayer->play();
    }
}

void MainWindow::Action2_2_slot()
{
    QString musicName=ui->myFavouriteList->currentItem()->text();
    if (mediaPlayer->playlist()==playList_MyFavourite)
    {
        int Row=playList_MyFavourite->currentIndex();
        int row=ui->myFavouriteList->currentIndex().row();
        if (row<Row)
        {
            int Position;
            if (mediaPlayer->state()==QMediaPlayer::PlayingState)
                Position=mediaPlayer->position();
            playList_MyFavourite->setCurrentIndex(0);
            ui->myFavouriteList->takeItem(row);
            playList_MyFavourite->removeMedia(row,row);
            model_2->setTable("I_LIKE_DATA");
            model_2->select();
            model_2->removeRow(row);
            model_2->submitAll();
            mediaPlayer->setPlaylist(playList_MyFavourite);
            playList_MyFavourite->setCurrentIndex(Row-1);
            mediaPlayer->setPosition(Position);
            ui->songSlider->setValue(Position);
            mediaPlayer->play();
        }
        else
        {
            ui->myFavouriteList->takeItem(row);
            playList_MyFavourite->removeMedia(row,row);
            model_2->setTable("I_LIKE_DATA");
            model_2->select();
            model_2->removeRow(row);
            model_2->submitAll();
        }
    }
    else
    {
        int row=ui->myFavouriteList->currentIndex().row();
        ui->myFavouriteList->takeItem(row);
        playList_MyFavourite->removeMedia(row,row);
        model_2->setTable("I_LIKE_DATA");
        model_2->select();
        model_2->removeRow(row);
        model_2->submitAll();
    }
    QSqlQuery query;
    query.exec("select * from HAHAHA");
    query.prepare(QString("update HAHAHA set biaoji = ? where MusicName = '%1' ").arg(musicName));
    query.bindValue(0,0);
    query.exec();
}

void MainWindow::Action3_2_slot()
{
    int row=ui->myFavouriteList->currentIndex().row();
    QString Text=ui->myFavouriteList->item(row)->text();
    QListWidgetItem *ITEMM=new QListWidgetItem;
    ITEMM->setIcon(QIcon(":/icon/resources/icon/addMusic.png"));
    ITEMM->setText(QString("%1").arg(Text));
    ui->playlistList->addItem(ITEMM);
    model_2->setTable("I_LIKE_DATA");
    model_2->select();
    playList_PlayList->addMedia(playList_MyFavourite->media(row));
    QSqlQuery query;
    QString musicName=model_2->data(model_2->index(row,1)).toString();
    QString fileName=model_2->data(model_2->index(row,2)).toString();
    query.exec("select * from NIMA");
    query.exec(QString("insert into NIMA values (%1,'%2','%3')").arg(qrand()%10000).arg(musicName).arg(fileName));
    ui->playList->setCurrentIndex(2);
    setBtnPlaylistLightUp();
}

void MainWindow::Action4_2_slot()
{
    int row=ui->myFavouriteList->currentIndex().row();
    QString temp=ui->myFavouriteList->currentIndex().data().toString();
    QString musicName=temp.split(" - ").last();
    QString author=temp.remove(" - "+musicName);
    model_2->setTable("I_LIKE_DATA");
    model_2->select();
    QString fileName=model_2->data(model_2->index(row,2)).toString();
    QString time;
    if (mediaPlayer->playlist()==playList_MyFavourite)
    {
        //原本这里是row=playList_MyFavourite->currentIndex()，感觉有错
        if (row==playList_MyFavourite->currentIndex())
            time=Time(mediaPlayer->duration());
        else
            time="00:00";
    }
    else
        time="00:00";
    QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名: %1  \n"
                                             "作者: %2 \n"
                                             "时长: %3 \n"
                                          "文件路径: %4\n").arg(musicName).arg(author).arg(time).arg(fileName));
}

void MainWindow::Action1_3_slot()
{
    if (mediaPlayer->playlist()==playList_PlayList)
    {
        if (ui->playlistList->item(playList_PlayList->currentIndex())->isSelected())
        {
            if (mediaPlayer->state()==QMediaPlayer::PlayingState)
                mediaPlayer->pause();
            else
                mediaPlayer->play();
        }
        else
        {
            playList_PlayList->setCurrentIndex(ui->playlistList->currentIndex().row());
            mediaPlayer->play();
        }
    }
    else
    {
        mediaPlayer->setPlaylist(playList_PlayList);
        playList_PlayList->setCurrentIndex(ui->playlistList->currentIndex().row());
        mediaPlayer->play();
    }
}

void MainWindow::Action2_3_slot()
{
    if (mediaPlayer->playlist()==playList_PlayList)
    {
        int Row=playList_PlayList->currentIndex();
        int row=ui->playlistList->currentIndex().row();
        if (row<Row)
        {
            int Position;
            if (mediaPlayer->state()==QMediaPlayer::PlayingState)
                Position=mediaPlayer->position();
            playList_PlayList->setCurrentIndex(0);
            ui->playlistList->takeItem(row);
            playList_PlayList->removeMedia(row,row);
            model_3->setTable("NIMA");
            model_3->select();
            model_3->removeRow(row);
            model_3->submitAll();
            mediaPlayer->setPlaylist(playList_PlayList);
            playList_PlayList->setCurrentIndex(Row-1);
            mediaPlayer->setPosition(Position);
            ui->songSlider->setValue(Position);
            mediaPlayer->play();
        }
        else
        {
            ui->playlistList->takeItem(row);
            playList_PlayList->removeMedia(row,row);
            model_3->setTable("NIMA");
            model_3->select();
            model_3->removeRow(row);
            model_3->submitAll();
        }
    }
    else
    {
        int row=ui->playlistList->currentIndex().row();
        ui->playlistList->takeItem(row);
        playList_PlayList->removeMedia(row,row);
        model_3->setTable("NIMA");
        model_3->select();
        model_3->removeRow(row);
        model_3->submitAll();
    }
}

void MainWindow::Action3_3_slot()
{
    int row=ui->playlistList->currentIndex().row();
    QString temp=ui->playlistList->currentIndex().data().toString();
    QString musicName=temp.split(" - ").last();
    QString author=temp.remove(" - "+musicName);
    model_3->setTable("NIMA");
    model_3->select();
    QString fileName=model_3->data(model_3->index(row,2)).toString();
    QString time;
    if (mediaPlayer->playlist()==playList_PlayList)
    {
        //这里原本是row=playList_PlayList->currentIndex()，感觉有错
        if (row==playList_PlayList->currentIndex())
            time=Time(mediaPlayer->duration());
        else
            time="00:00";
    }
    else
        time="00:00";
    QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名: %1  \n"
                                             "作者: %2 \n"
                                             "时长: %3 \n"
                                             "文件路径: %4\n").arg(musicName).arg(author).arg(time).arg(fileName));

}

void MainWindow::Action_slot()
{
    int row=ui->searchList->currentIndex().row();
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        if (load[row]==playList_LocalMusic->currentIndex())
        {
            if (mediaPlayer->state()==QMediaPlayer::PlayingState)
                mediaPlayer->pause();
            else
                mediaPlayer->play();
        }
        else
        {
            playList_LocalMusic->setCurrentIndex(load[row]);
            mediaPlayer->play();
            ui->localMusicList->item(load[row])->setSelected(true);
        }
    }
    else
    {
        mediaPlayer->setPlaylist(playList_LocalMusic);
        playList_LocalMusic->setCurrentIndex(load[row]);
        mediaPlayer->play();
    }
}

void MainWindow::Action_1_slot()
{
    model_1->setTable("HAHAHA");
    model_1->select();
    int row=ui->searchList->currentIndex().row();
    int flag=model_1->data(model_1->index(load[row],3)).toInt();
    if (flag==0)
    {
        QString Text=ui->localMusicList->item(load[row])->text();
        QListWidgetItem *itemm=new QListWidgetItem;
        itemm->setIcon(QIcon(":/icon/resources/icon/addToMyFavourite.png"));
        itemm->setText(QString("%1").arg(Text));
        ui->myFavouriteList->addItem(itemm);
        QSqlQuery query;
        playList_MyFavourite->addMedia(playList_LocalMusic->media(load[row]));
        model_1->setTable("HAHAHA");
        model_1->select();
        QString musicName=model_1->data(model_1->index(load[row],1)).toString();
        QString fileName=model_1->data(model_1->index(load[row],2)).toString();
        model_1->setData(model_1->index(load[row],3),1);
        model_1->submitAll();
        query.exec("select * from I_LIKE_DATA");
        query.exec(QString("insert into I_LIKE_DATA values (%1,'%2','%3')").arg(qrand()%10000).arg(musicName).arg(fileName));
        ui->playList->setCurrentIndex(1);
        setBtnMyFavouriteLightUp();
        if (mediaPlayer->playlist()==playList_LocalMusic)
        {
            if (playList_LocalMusic->currentIndex()==load[row])
            {
                ui->btnAddToCurrentList->setIcon(QIcon(":/icon/resources/icon/liked.png"));
                ui->btnAddToCurrentList->setToolTip(tr("已经喜欢"));
            }
        }
    }
    else
        QMessageBox::information(this,tr("提示"),tr("该歌曲已添加                              ."),QMessageBox::Yes);
}

void MainWindow::Action_2_slot()
{
    int row=ui->searchList->currentIndex().row();
    QString Text=ui->localMusicList->item(load[row])->text();
    QListWidgetItem *itemm=new QListWidgetItem;
    itemm->setIcon(QIcon(":/icon/resources/icon/addMusic.png"));
    itemm->setText(QString("%1").arg(Text));
    model_1->setTable("HAHAHA");
    model_1->select();
    playList_PlayList->addMedia(playList_LocalMusic->media(load[row]));
    QSqlQuery query;
    QString musicName=model_1->data(model_1->index(load[row],1)).toString();
    QString fileName=model_1->data(model_1->index(load[row],2)).toString();
    query.exec("select * from NIMA");
    query.exec(QString("insert into NIMA values (%1,'%2','%3')").arg(qrand()%10000).arg(musicName).arg(fileName));
    ui->playList->setCurrentIndex(2);
    setBtnPlaylistLightUp();
}

void MainWindow::Action_3_slot()
{
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        int Row=playList_LocalMusic->currentIndex();
        int row=ui->searchList->currentIndex().row();
        if (load[row]<Row)
        {
            int Position;
            if (mediaPlayer->state()==QMediaPlayer::PlayingState)
                Position=mediaPlayer->position();
            playList_LocalMusic->setCurrentIndex(0);
            ui->localMusicList->takeItem(load[row]);
            ui->searchList->takeItem(row);
            playList_LocalMusic->removeMedia(load[row],load[row]);
            model_1->setTable("HAHAHA");
            model_1->select();
            model_1->removeRow(load[row]);
            model_1->submitAll();
            mediaPlayer->setPlaylist(playList_LocalMusic);
            playList_LocalMusic->setCurrentIndex(Row-1);
            mediaPlayer->setPosition(Position);
            ui->songSlider->setValue(Position);
            mediaPlayer->play();
        }
        else
        {
            ui->searchList->takeItem(row);
            ui->localMusicList->takeItem(load[row]);
            playList_LocalMusic->removeMedia(load[row],load[row]);
            model_1->setTable("HAHAHA");
            model_1->select();
            model_1->removeRow(load[row]);
            model_1->submitAll();
        }
    }
    else
    {
        int row=ui->searchList->currentIndex().row();
        ui->searchList->takeItem(row);
        ui->localMusicList->takeItem(load[row]);
        playList_LocalMusic->removeMedia(load[row],load[row]);
        model_1->setTable("HAHAHA");
        model_1->select();
        model_1->removeRow(load[row]);
        model_1->submitAll();
    }
}

void MainWindow::Action_4_slot()
{
    int row=ui->searchList->currentIndex().row();
    QString temp=ui->searchList->currentIndex().data().toString();
    QString musicName=temp.split(" - ").last();
    QString author=temp.remove(" - "+musicName);
    model_1->setTable("HAHAHA");
    model_1->select();
    QString fileName=model_1->data(model_1->index(load[row],2)).toString();
    QString time;
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        //原来的感觉这里有错，原来的是load[row]=playList_LocalMusic->currentIndex()
        if (load[row]==playList_LocalMusic->currentIndex())
            time=Time(mediaPlayer->duration());
        else
            time="00:00";
    }
    else
        time="00:00";
    QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名: %1  \n"
                                             "作者: %2 \n"
                                             "时长: %3 \n"
                                             "文件路径: %4\n").arg(musicName).arg(author).arg(time).arg(fileName));
}


void MainWindow::on_btnPlayOrPause_clicked()
{
    if (mediaPlayer->state()==QMediaPlayer::PlayingState)
    {
        ui->btnPlayOrPause->setIcon(QIcon(":/icon/resources/icon/mediaPlay.png"));
        ui->btnPlayOrPause->setToolTip(tr("播放"));
        mediaPlayer->pause();
    }
    else
    {
        ui->btnPlayOrPause->setIcon(QIcon(":/icon/resources/icon/mediaPause.png"));
        ui->btnPlayOrPause->setToolTip(tr("暂停"));
        mediaPlayer->play();
    }
}

void MainWindow::on_btnPlayNextSong_clicked()
{
    int currentIndex;
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        currentIndex=playList_LocalMusic->currentIndex();
        ui->playList->setCurrentIndex(0);
        setBtnLocalMusicLightUp();
        if (++currentIndex==playList_LocalMusic->mediaCount())
            currentIndex=0;
        playList_LocalMusic->setCurrentIndex(currentIndex);
    }
    else if (mediaPlayer->playlist()==playList_MyFavourite)
    {
        currentIndex=playList_MyFavourite->currentIndex();
        ui->playList->setCurrentIndex(1);
        setBtnMyFavouriteLightUp();
        if (++currentIndex==playList_MyFavourite->mediaCount())
            currentIndex=0;
        playList_MyFavourite->setCurrentIndex(currentIndex);
    }
    else if (mediaPlayer->playlist()==playList_PlayList)
    {
        currentIndex=playList_PlayList->currentIndex();
        ui->playList->setCurrentIndex(2);
        setBtnPlaylistLightUp();
        if (++currentIndex==playList_PlayList->mediaCount())
            currentIndex=0;
        playList_PlayList->setCurrentIndex(currentIndex);
    }
    mediaPlayer->play();
}

void MainWindow::on_btnPlayPreSong_clicked()
{
    int currentIndex;
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        currentIndex=playList_LocalMusic->currentIndex();
        ui->playList->setCurrentIndex(0);
        setBtnLocalMusicLightUp();
        if (--currentIndex<0)
            currentIndex=0;
        playList_LocalMusic->setCurrentIndex(currentIndex);
    }
    else if (mediaPlayer->playlist()==playList_MyFavourite)
    {
        currentIndex=playList_MyFavourite->currentIndex();
        ui->playList->setCurrentIndex(1);
        setBtnMyFavouriteLightUp();
        if (--currentIndex<0)
            currentIndex=0;
        playList_MyFavourite->setCurrentIndex(currentIndex);
    }
    else if (mediaPlayer->playlist()==playList_PlayList)
    {
        currentIndex=playList_PlayList->currentIndex();
        ui->playList->setCurrentIndex(2);
        setBtnPlaylistLightUp();
        if (--currentIndex<0)
            currentIndex=0;
        playList_PlayList->setCurrentIndex(currentIndex);
    }
    mediaPlayer->play();
}

void MainWindow::on_btnShowOrHideList_clicked()
{
    if (ui->playList->isHidden())
    {
        ui->btnShowOrHideList->setIcon(QIcon(":/icon/resources/icon/hidePlayList.png"));
        ui->btnShowOrHideList->setToolTip(tr("隐藏播放列表"));
        ui->playList->show();
        ui->btnLocalMusic->show();
        ui->btnMyFavourite->show();
        ui->btnPlayList->show();
        ui->labPlayState->move(QPoint(330,500));
        ui->btnShowOrHideList->move(QPoint(260,10));
    }
    else
    {
        ui->btnShowOrHideList->setIcon(QIcon(":/icon/resources/icon/showPlayList.png"));
        ui->btnShowOrHideList->setToolTip(tr("显示播放列表"));
        ui->playList->hide();
        ui->btnLocalMusic->hide();
        ui->btnMyFavourite->hide();
        ui->btnPlayList->hide();
        ui->labPlayState->move(QPoint(200,500));
        ui->btnShowOrHideList->move(QPoint(20,10));
    }
}

void MainWindow::on_btnSelectPlayMode_clicked()
{
    if (playList_LocalMusic->playbackMode()==QMediaPlaylist::Loop)
    {
        ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/shuffle.png"));
        ui->btnSelectPlayMode->setToolTip(tr("随机播放"));
        playList_LocalMusic->setPlaybackMode(QMediaPlaylist::Random);
        playList_MyFavourite->setPlaybackMode(QMediaPlaylist::Random);
        playList_PlayList->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if (playList_LocalMusic->playbackMode()==QMediaPlaylist::Random)
    {
        ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/singleCycle.png"));
        ui->btnSelectPlayMode->setToolTip(tr("单曲循环"));
        playList_LocalMusic->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playList_MyFavourite->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playList_PlayList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
    else if (playList_LocalMusic->playbackMode()==QMediaPlaylist::CurrentItemInLoop)
    {
        ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/inOrder.png"));
        ui->btnSelectPlayMode->setToolTip(tr("顺序播放"));
        playList_LocalMusic->setPlaybackMode(QMediaPlaylist::Loop);
        playList_MyFavourite->setPlaybackMode(QMediaPlaylist::Loop);
        playList_PlayList->setPlaybackMode(QMediaPlaylist::Loop);
    }
}

void MainWindow::on_localMusicList_doubleClicked(const QModelIndex &index)
{
    mediaPlayer->setPlaylist(playList_LocalMusic);
    playList_LocalMusic->setCurrentIndex(ui->localMusicList->currentIndex().row());
    mediaPlayer->play();
}

void MainWindow::on_myFavouriteList_doubleClicked(const QModelIndex &index)
{
    mediaPlayer->setPlaylist(playList_MyFavourite);
    playList_MyFavourite->setCurrentIndex(ui->myFavouriteList->currentIndex().row());
    mediaPlayer->play();
}

void MainWindow::on_playlistList_doubleClicked(const QModelIndex &index)
{
    mediaPlayer->setPlaylist(playList_PlayList);
    playList_PlayList->setCurrentIndex(ui->playlistList->currentIndex().row());
    mediaPlayer->play();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    offset=event->globalPos()-pos();
    event->accept();
    ui->volumeSlider->hide();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalPos()-offset);
    event->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    offset=QPoint();
    event->accept();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    hide();
    int index;
    if (mediaPlayer->playlist()==playList_LocalMusic)
        index=0;
    else if (mediaPlayer->playlist()==playList_MyFavourite)
        index=1;
    else
        index=2;
    miniwindow->setPlaylist(mediaPlayer->playlist(),mediaPlayer->playlist()->currentIndex(),mediaPlayer->position(),mediaPlayer->volume(),mediaPlayer->state(),playList_LocalMusic->playbackMode(),index);
    mediaPlayer->pause();
    if (miniwindow->exec()==MiniWindow::Accepted)
        show();
}

void MainWindow::on_btnMinimize_clicked()
{
    showMinimized();
}

void MainWindow::on_btnClose_clicked()
{
    close();
}

void MainWindow::on_btnVolume_clicked()
{
    if (ui->volumeSlider->isHidden())
        ui->volumeSlider->show();
    else
        ui->volumeSlider->hide();
}

//播放列表右键菜单
void MainWindow::on_localMusicList_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem *curItem=ui->localMusicList->itemAt(pos);
    if (curItem==NULL)
        return;
    QMenu *Menu=new QMenu(this);
    QAction *Action1=new QAction(this);
    QAction *Action2=new QAction(this);
    QAction *Action3=new QAction(this);
    QAction *Action4=new QAction(this);
    QAction *Action5=new QAction(this);
    Action1->setIcon(QIcon(":/icon/resources/icon/mediaPlaySmall.png"));
    Action1->setToolTip(tr("播放/暂停"));
    Action2->setIcon(QIcon(":/icon/resources/icon/addToMyFavourite.png"));
    Action2->setToolTip(tr("添加到我喜欢"));
    Action4->setIcon(QIcon(":/icon/resources/icon/addedToPlayList.png"));
    Action4->setToolTip(tr("添加到播放列表"));
    Action3->setIcon(QIcon(":/icon/resources/icon/delete.png"));
    Action3->setText(tr("删除"));
    Action5->setIcon(QIcon(":/icon/resources/icon/songInfo.png"));
    Action5->setText(tr("歌曲信息"));
    Menu->addAction(Action1);
    Menu->addAction(Action2);
    Menu->addAction(Action4);
    Menu->addAction(Action5);
    Menu->addAction(Action3);
    connect(Action1,&QAction::triggered,this,&MainWindow::Action1_slot);
    connect(Action2,&QAction::triggered,this,&MainWindow::Action2_slot);
    connect(Action3,&QAction::triggered,this,&MainWindow::Action3_slot);
    connect(Action4,&QAction::triggered,this,&MainWindow::Action4_slot);
    connect(Action5,&QAction::triggered,this,&MainWindow::Action5_slot);
    Menu->exec(QCursor::pos());
    delete Menu;
    delete Action1;
    delete Action2;
    delete Action3;
    delete Action4;
    delete Action5;
}

void MainWindow::on_myFavouriteList_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem *curItem=ui->myFavouriteList->itemAt(pos);
    if (curItem==NULL)
        return;
    QMenu *Menu1=new QMenu(this);
    QAction *Action1_2=new QAction(this);
    QAction *Action2_2=new QAction(this);
    QAction *Action3_2=new QAction(this);
    QAction *Action4_2=new QAction(this);
    Action1_2->setIcon(QIcon(":/icon/resources/icon/mediaPlaySmall.png"));
    Action1_2->setToolTip(tr("播放/暂停"));
    Action3_2->setIcon(QIcon(":/icon/resources/icon/playList.png"));
    Action3_2->setToolTip(tr("添加至播放队列"));
    Action2_2->setIcon(QIcon(":/icon/resources/icon/delete.png"));
    Action2_2->setToolTip(tr("移除"));
    Action4_2->setIcon(QIcon(":/icon/resources/icon/songInfo.png"));
    Action4_2->setToolTip(tr("歌曲信息"));
    Menu1->addAction(Action1_2);
    Menu1->addAction(Action3_2);
    Menu1->addAction(Action4_2);
    Menu1->addAction(Action2_2);
    connect(Action1_2,&QAction::triggered,this,&MainWindow::Action1_2_slot);
    connect(Action2_2,&QAction::triggered,this,&MainWindow::Action2_2_slot);
    connect(Action3_2,&QAction::triggered,this,&MainWindow::Action3_2_slot);
    connect(Action4_2,&QAction::triggered,this,&MainWindow::Action4_2_slot);
    Menu1->exec(QCursor::pos());
    delete Menu1;
    delete Action1_2;
    delete Action2_2;
    delete Action3_2;
    delete Action4_2;
}

void MainWindow::on_playlistList_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem *curItem=ui->playlistList->itemAt(pos);
    if (curItem==NULL)
        return;
    QMenu *Menu=new QMenu(this);
    QAction *Action1_3=new QAction(this);
    QAction *Action2_3=new QAction(this);
    QAction *Action3_3=new QAction(this);
    Action1_3->setIcon(QIcon(":/icon/resources/icon/mediaPlaySmall.png"));
    Action1_3->setText(tr("播放/暂停"));
    Action2_3->setIcon(QIcon(":/icon/resources/icon/delete.png"));
    Action2_3->setText(tr("移除"));
    Action3_3->setIcon(QIcon(":/icon/resources/icon/songInfo.png"));
    Action3_3->setText(tr("歌曲信息"));
    connect(Action1_3,&QAction::triggered,this,&MainWindow::Action1_3_slot);
    connect(Action2_3,&QAction::triggered,this,&MainWindow::Action2_3_slot);
    connect(Action3_3,&QAction::triggered,this,&MainWindow::Action3_3_slot);
    Menu->exec(QCursor::pos());
    delete Menu;
    delete Action1_3;
    delete Action2_3;
    delete Action3_3;
}

void MainWindow::on_btnMiniStyle_clicked()
{
    hide();
    int index;
    if (mediaPlayer->playlist()==playList_LocalMusic)
        index=0;
    else if (mediaPlayer->playlist()==playList_MyFavourite)
        index=1;
    else
        index=2;
    miniwindow->setPlaylist(mediaPlayer->playlist(),mediaPlayer->playlist()->currentIndex(),mediaPlayer->position(),mediaPlayer->volume(),mediaPlayer->state(),playList_LocalMusic->playbackMode(),index);
    mediaPlayer->pause();
    if (miniwindow->exec()==MiniWindow::Accepted)
        show();
}

void MainWindow::Data_slot(int row, int position, QMediaPlaylist *list, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode model)
{
    playList_LocalMusic->setPlaybackMode(model);
    playList_MyFavourite->setPlaybackMode(model);
    playList_PlayList->setPlaybackMode(model);
    if (list==playList_LocalMusic)
    {
        playList_LocalMusic->setCurrentIndex(row);
        mediaPlayer->setPosition(position);
        if (state==QMediaPlayer::PlayingState)
            mediaPlayer->play();
    }
    else if (list==playList_MyFavourite)
    {
        playList_MyFavourite->setCurrentIndex(row);
        mediaPlayer->setPosition(position);
        if (state==QMediaPlayer::PlayingState)
            mediaPlayer->play();
    }
    else
    {
        playList_PlayList->setCurrentIndex(row);
        mediaPlayer->setPosition(position);
        if (state==QMediaPlayer::PlayingState)
            mediaPlayer->play();
    }
}

void MainWindow::on_btnAddToCurrentList_clicked()
{
    if (mediaPlayer->playlist()==playList_LocalMusic)
    {
        int row=playList_LocalMusic->currentIndex();
        model_1->setTable("HAHAHA");
        model_1->select();
        int flag=model_1->data(model_1->index(row,3)).toInt();
        if (flag==0)
        {
            ui->btnAddToCurrentList->setIcon(QIcon(":/icon/resources/icon/liked.png"));
            ui->btnAddToCurrentList->setToolTip(tr("我喜欢"));
            int row=playList_LocalMusic->currentIndex();
            QString Text=ui->localMusicList->item(row)->text();
            QListWidgetItem *ITEM=new QListWidgetItem;
            ITEM->setIcon(QIcon(":/icon/resources/icon/addToMyFavourite.png"));
            ITEM->setText(QString("%1").arg(Text));
            ui->myFavouriteList->addItem(ITEM);
            playList_MyFavourite->addMedia(playList_LocalMusic->media(row));
            QSqlQuery query;
            model_1->setTable("HAHAHA");
            model_1->select();
            QString musicName=model_1->data(model_1->index(row,1)).toString();
            QString fileName=model_1->data(model_1->index(row,2)).toString();
            model_1->setData(model_1->index(row,3),1);
            model_1->submitAll();
            query.exec("select * from I_LIKE_DATA");
            query.exec(QString("insert into I_LIKE_DATA values (%1,'%2','%3')").arg(qrand()%10000).arg(musicName).arg(fileName));
        }
    }
}

void MainWindow::on_btnSearch_clicked()
{
    QString text=ui->searchBar->text();
    if (text!="")
    {
        load.clear();
        ui->searchList->clear();
        std::string MusicName=ui->searchBar->text().toStdString();
        const char *MusicName1=MusicName.c_str();
        ui->playList->setCurrentIndex(3);
        int Count=ui->localMusicList->count();
        setNoBtnLightUp();
        for (int i=0;i<Count;i++)
        {
            QString Text=ui->localMusicList->item(i)->text();
            QString Name=Text.split("- ").last();
            std::string Name1=Name.toStdString();
            const char *Name2=Name1.c_str();
            QString author=Text.remove(" - "+Name);
            std::string author1=author.toStdString();
            const char *author2=author1.c_str();
            if (strstr(Name2,MusicName1) || strstr(author2,MusicName1))
            {
                QString Text=ui->localMusicList->item(i)->text();
                QListWidgetItem *item20=new QListWidgetItem;
                item20->setIcon(QIcon(":/icon/resources/icon/search.png"));
                item20->setText(Text);
                ui->searchList->addItem(item20);
                load.push_back(i);
            }
        }
        ui->searchBar->clear();
    }
}

void MainWindow::on_searchList_doubleClicked(const QModelIndex &index)
{
    mediaPlayer->setPlaylist(playList_LocalMusic);
    playList_LocalMusic->setCurrentIndex(load[ui->searchList->currentIndex().row()]);
    mediaPlayer->play();
}

void MainWindow::on_searchList_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem *item20=ui->searchList->itemAt(pos);
    if (item20==NULL)
        return;
    QMenu *menu20=new QMenu(this);
    QAction *Action=new QAction(this);
    QAction *Action1=new QAction(this);
    QAction *Action2=new QAction(this);
    QAction *Action3=new QAction(this);
    QAction *Action4=new QAction(this);
    Action->setIcon(QIcon(":/icon/resources/icon/mediaPlaySmall.png"));
    Action->setText(tr("播放/暂停"));
    Action1->setIcon(QIcon(":/icon/resources/icon/addToMyFavourite.png"));
    Action1->setText(tr("添加到我喜欢"));
    Action2->setIcon(QIcon(":/icon/resources/icon/playList.png"));
    Action2->setText(tr("添加到播放队列"));
    Action3->setIcon(QIcon(":/icon/resources/icon/delete.png"));
    Action3->setText(tr("删除歌曲"));
    Action4->setIcon(QIcon(":/icon/resources/icon/songInfo.png"));
    Action4->setText(tr("歌曲信息"));
    connect(Action,&QAction::triggered,this,&MainWindow::Action_slot);
    connect(Action1,&QAction::triggered,this,&MainWindow::Action1_slot);
    connect(Action2,&QAction::triggered,this,&MainWindow::Action2_slot);
    connect(Action3,&QAction::triggered,this,&MainWindow::Action3_slot);
    connect(Action4,&QAction::triggered,this,&MainWindow::Action4_slot);
    menu20->addAction(Action);
    menu20->addAction(Action1);
    menu20->addAction(Action2);
    menu20->addAction(Action4);
    menu20->addAction(Action3);
    menu20->exec(QCursor::pos());
    delete Action;
    delete Action1;
    delete Action2;
    delete Action3;
    delete Action4;
    delete menu20;
}

void MainWindow::on_searchBar_returnPressed()
{
    QString text=ui->searchBar->text();
    if (text!="")
    {
        load.clear();
        ui->searchList->clear();
        std::string musicName=ui->searchBar->text().toStdString();
        const char *musicName1=musicName.c_str();
        ui->playList->setCurrentIndex(3);
        int count=ui->localMusicList->count();
        setNoBtnLightUp();
        for (int i=0;i<count;i++)
        {
            QString Text=ui->localMusicList->item(i)->text();
            QString Name=Text.split("- ").last();
            std::string Name1=Name.toStdString();
            const char *Name2=Name1.c_str();
            QString author=Text.remove(" - "+Name);
            std::string author1=author.toStdString();
            const char *author2=author1.c_str();
            qDebug()<<Name;
            qDebug()<<author;
            if (strstr(Name2,musicName1) || strstr(author2,musicName1))
            {
                QString Text=ui->localMusicList->item(i)->text();
                QListWidgetItem *item=new QListWidgetItem;
                item->setIcon(QIcon(":/icon/resources/icon/search.png"));
                item->setText(Text);
                ui->searchList->addItem(item);
                load.push_back(i);
            }
        }
        ui->searchBar->clear();
    }
}

void MainWindow::PlaylistModel_slot(QMediaPlaylist::PlaybackMode model)
{
    //原函数这里绝对有bug
    if (model==QMediaPlaylist::Loop)
    {
        ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/inOrder.png"));
        ui->btnSelectPlayMode->setToolTip(tr("顺序播放"));
        playList_LocalMusic->setPlaybackMode(QMediaPlaylist::Loop);
    }
    else if (model==QMediaPlaylist::Random)
    {
        ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/shuffle.png"));
        ui->btnSelectPlayMode->setToolTip(tr("随机播放"));
        playList_LocalMusic->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if (model==QMediaPlaylist::CurrentItemInLoop)
    {
        ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/singleCycle.png"));
        ui->btnSelectPlayMode->setToolTip(tr("单曲循环"));
        playList_LocalMusic->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
}
