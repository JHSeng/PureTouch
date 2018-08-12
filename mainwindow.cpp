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
#include <QFileDialog>

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

    //信号和槽相关设置,要先写完预设的函数

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
