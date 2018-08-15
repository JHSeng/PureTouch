#include "miniwindow.h"
#include "ui_miniwindow.h"

#include <QPixmap>
#include <QPalette>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QShortcut>
#include <QFileDialog>

MiniWindow::MiniWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MiniWindow)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.next();
    QString fileName=query.value(0).toString();
    if (fileName=="")
        wallpaper.load(":/background/resources/background/background_3.jpg");
    else
        wallpaper.load(fileName);
    pal.setBrush(QPalette::Window,QBrush(wallpaper.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    query.exec("select * from Toumin_DATA");
    query.next();
    QString Temp=query.value(0).toString();
    if (Temp=="")
        TouMin=1.0;
    else
        TouMin=Temp.toDouble();
    setWindowOpacity(TouMin);
    ui->btnPlayOrPause->setIconSize(QSize(48,48));
    ui->btnPlayOrPause->setIcon(QIcon(":/icon/resources/icon/mediaPlay.png"));
    ui->btnPreSong->setToolTip(tr("上一首"));
    ui->btnPlayOrPause->setToolTip(tr("播放"));
    ui->btnNextSong->setToolTip(tr("下一首"));
    ui->btnClose->setToolTip(tr("关闭"));
    ui->btnMinimize->setToolTip(tr("最小化"));
    ui->btnNormalStyle->setToolTip(tr("返回主窗口"));
    ui->songSlider->setToolTip(tr("播放进度"));

    mediaPlayer=new QMediaPlayer(this);
    playList=new QMediaPlaylist(this);
    playList->setPlaybackMode(QMediaPlaylist::Loop);

    playOrPause=new QAction(this);
    playNextSong=new QAction(this);
    playPreSong=new QAction(this);
    playOrPause->setIcon(QIcon(":/icon/resources/icon/play.png"));
    playNextSong->setIcon(QIcon(":/icon/resources/icon/nextSong.png"));
    playPreSong->setIcon(QIcon(":/icon/resources/icon/preSong.png"));
    playOrPause->setText(tr("播放/暂停"));
    playNextSong->setText(tr("下一首"));
    playPreSong->setText(tr("上一首"));
    //信号和槽设置，对应原115行
    ui->btnSelectPlayMode->setIconSize(QSize(32,32));
    ui->btnSelectPlayMode->setIcon(QIcon(":/icon/resources/icon/inOrder.png"));
    ui->btnSelectPlayMode->setToolTip(tr("顺序播放"));
    ui->btnSongSource->setIconSize(QSize(32,32));
    ui->btnSongSource->setIcon(QIcon(":/icon/resources/icon/addedToPlayList.png"));
    ui->btnSongSource->setToolTip(tr("本地音乐列表"));
}

MiniWindow::~MiniWindow()
{
    delete ui;
}

void MiniWindow::setPlaylist(QMediaPlaylist *list, int row, int position, int volume, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode playmodel, int i)
{
    playList=list;
    mediaPlayer->setPlaylist(playList);
    playList->setCurrentIndex(row);
    mediaPlayer->setPosition(position);
    mediaPlayer->setVolume(volume);
    if (state==QMediaPlayer::PlayingState)
        mediaPlayer->play();
    playList->setPlaybackMode(playmodel);
    if (i==0)
    {
        ui->btnSongSource->setIcon(QIcon(":/icon/resources/icon/addedToPlayList.png"));
        ui->btnSongSource->setToolTip(tr("本地音乐列表"));
    }
    else if (i==1)
    {
        ui->btnSongSource->setIcon(QIcon(":/icon/resources/icon/liked.png"));
        ui->btnSongSource->setToolTip(tr("我喜欢"));
    }
    else if (i==2)
    {
        ui->btnSongSource->setIcon(QIcon(":/icon/resources/icon/playList.png"));
        ui->btnSongSource->setToolTip(tr("播放队列"));
    }
}

void MiniWindow::mousePressEvent(QMouseEvent *event)
{
    offset=event->globalPos()-pos();
    event->accept();
}

void MiniWindow::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalPos()-offset);
    event->accept();
}

void MiniWindow::mouseReleaseEvent(QMouseEvent *event)
{
    offset=QPoint();
    event->accept();
}

void MiniWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit Data(playList->currentIndex(),mediaPlayer->position(),playList,mediaPlayer->state(),playList->playbackMode());
    mediaPlayer->pause();
    accept();
}

void MiniWindow::updateSongInfo()
{
    QString Text;
    if (mediaPlayer->isMetaDataAvailable())
    {
        QString title=mediaPlayer->metaData(QStringLiteral("Title")).toString();
        if (!title.isEmpty())
            Text=title;
        else
            Text+=tr("未知歌曲");
        Text+="-";
        QString author=mediaPlayer->metaData(QStringLiteral("Author")).toString();
        if (!author.isEmpty())
            Text+=author;
        else
            Text+=tr("未知歌手");
    }
    ui->labPlayState->setText(Text);
}

void MiniWindow::on_btnClose_clicked()
{
    QCoreApplication::quit();
}

void MiniWindow::on_btnNormalStyle_clicked()
{
    emit Data(playList->currentIndex(),mediaPlayer->position(),playList,mediaPlayer->state(),playList->playbackMode());
    mediaPlayer->pause();
    accept();
}

void MiniWindow::on_btnMinimize_clicked()
{
    showMinimized();
}
