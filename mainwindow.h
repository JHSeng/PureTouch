#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QAction>
#include <QList>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPixmap>
#include <QPalette>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QSqlTableModel>
#include <QSystemTrayIcon>

#include "miniwindow.h"

class QMediaPlayer;
class QMediaPlaylist;
class QMenu;
class QAction;
class QSqlTableModel;
class MiniWindow;
class Form;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updatePlayState();
    void updatePlayPosition(qint64 position);
    void updatePlayDuration(qint64 duration);
    void setBtnLocalMusicLightUp();
    void setBtnMyFavouriteLightUp();
    void setBtnPlaylistLightUp();
    void setNoBtnLightUp();
    void updateLocalMusicList(int value);
    void updateMyFavouriteList(int value);
    void updatePlaylistList(int value);
    void changeVolume(int value);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private slots:
    void on_btnLocalMusic_clicked();
    void on_btnMyFavourite_clicked();
    void on_btnPlayList_clicked();
    void songInfo_slot(); //查看歌曲信息
    void clearLocalMusic_slot(); //清除本地音乐列表
    void clearMyFavourite_slot();
    void clearPlaylist_slot();
    void clearAllList_slot();
    void addToLocalMusic_slot(); //添加到本地音乐列表
    void addToMyFavourite_slot();
    void addToPlaylist_slot();
    void setBackGround_1_slot(); //更换背景为默认背景1
    void setBackGround_2_slot();
    void setBackground_customize_slot();
    void showAbout_slot();
    void preSong_slot(); //右键菜单 播放上一首
    void nextSong_slot();
    void playOrPause_slot(); //右键菜单里的
    void playInOrder_slot();
    void playShuffle_slot();
    void playSingleCycle_slot();
    void musicStateChange(QMediaPlayer::State state);
    void contextMenuEvent(QContextMenuEvent *event); //播放列表右键菜单
    void Action1_slot();
    void Action2_slot();
    void Action3_slot();
    void Action4_slot();
    void Action5_slot();
    void Action1_2_slot();
    void Action2_2_slot();
    void Action3_2_slot();
    void Action4_2_slot();
    void Action1_3_slot();
    void Action2_3_slot();
    void Action3_3_slot();
    void Action_slot();
    void Action_1_slot();
    void Action_2_slot();
    void Action_3_slot();
    void Action_4_slot();

    void on_btnPlayOrPause_clicked();

    void on_btnPlayNextSong_clicked();

    void on_btnPlayPreSong_clicked();

    void on_btnShowOrHideList_clicked();

    void on_btnSelectPlayMode_clicked();

    //双击列表播放歌曲
    void on_localMusicList_doubleClicked(const QModelIndex &index);

    void on_myFavouriteList_doubleClicked(const QModelIndex &index);

    void on_playlistList_doubleClicked(const QModelIndex &index);

    void on_btnMinimize_clicked();

    void on_btnClose_clicked();

    void on_btnVolume_clicked();

    void on_localMusicList_customContextMenuRequested(const QPoint &pos);

    void on_myFavouriteList_customContextMenuRequested(const QPoint &pos);

    void on_playlistList_customContextMenuRequested(const QPoint &pos);

    void on_btnMiniStyle_clicked();

    void Data_slot(int row,int position,QMediaPlaylist *list,QMediaPlayer::State state,QMediaPlaylist::PlaybackMode model);


    void on_btnAddToCurrentList_clicked();

    void on_btnSearch_clicked();

    void on_searchList_doubleClicked(const QModelIndex &index);

    void on_searchList_customContextMenuRequested(const QPoint &pos);

    void on_searchBar_returnPressed();

    void PlaylistModel_slot(QMediaPlaylist::PlaybackMode model);

    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

    void hideSysTrayIcon_slot();

private:
    Ui::MainWindow *ui;

    QAction *addToLocalMusic=new QAction(this);
    QAction *addToMyFavourite=new QAction(this);
    QAction *addToPlaylist=new QAction(this);
    QAction *setBackGround=new QAction(this);
    QAction *setBackGround_1=new QAction(this);
    QAction *setBackGround_2=new QAction(this);
    QAction *setBackground_customize=new QAction(this);
    QAction *showAbout=new QAction(this);
    QAction *clearList=new QAction(this);
    QAction *clearAllList=new QAction(this);
    QAction *clearLocalMusic=new QAction(this);
    QAction *clearMyFavourite=new QAction(this);
    QAction *clearPlaylist=new QAction(this);
    QAction *preSong=new QAction(this);
    QAction *nextSong=new QAction(this);
    QAction *playOrPause=new QAction(this);
    QAction *selectPlayMode=new QAction(this);
    QAction *playInOrder=new QAction(this);
    QAction *playSingleCycle=new QAction(this);
    QAction *playShuffle=new QAction(this);
    QAction *songInfo=new QAction(this);

    QPixmap *wallpaper=new QPixmap;
    double transparency;
    QPalette palette;
    QPoint offset;

    QMediaPlayer *mediaPlayer=new QMediaPlayer(this);
    QMediaPlaylist *playList_LocalMusic=new QMediaPlaylist(this);
    QMediaPlaylist *playList_MyFavourite=new QMediaPlaylist(this);
    QMediaPlaylist *playList_PlayList=new QMediaPlaylist(this);

    QSqlTableModel *model_1=new QSqlTableModel(this);
    QSqlTableModel *model_2=new QSqlTableModel(this);
    QSqlTableModel *model_3=new QSqlTableModel(this);

    MiniWindow *miniwindow=NULL;

//    QMenu *menu;
    QList<int>load;
    QSystemTrayIcon *systemTrayIcon=new QSystemTrayIcon(this);

signals:
    void signal_showAbout();
    void signal_hideSysTrayIcon();
};

#endif // MAINWINDOW_H
