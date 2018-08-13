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

#include "miniwindow.h"

class QMediaPlayer;
class QMediaPlaylist;
class QMenu;
class QAction;
class QSqlTableModel;
class MiniWindow;

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

private:
    Ui::MainWindow *ui;

    QAction *addToLocalMusic;
    QAction *addToMyFavourite;
    QAction *addToPlaylist;
    QAction *setBackGround;
    QAction *setBackGround_1;
    QAction *setBackGround_2;
    QAction *setBackground_customize;
    QAction *showAbout;
    QAction *clearList;
    QAction *clearAllList;
    QAction *clearLocalMusic;
    QAction *clearMyFavourite;
    QAction *clearPlaylist;
    QAction *preSong;
    QAction *nextSong;
    QAction *playOrPause;
    QAction *selectPlayMode;
    QAction *playInOrder;
    QAction *playSingleCycle;
    QAction *playShuffle;
    QAction *songInfo;

    QPixmap *wallpaper;
    double transparency;
    QPalette palette;
    QPoint offset;

    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *playList_LocalMusic;
    QMediaPlaylist *playList_MyFavourite;
    QMediaPlaylist *playList_PlayList;

    QSqlTableModel *model_1;
    QSqlTableModel *model_2;
    QSqlTableModel *model_3;

    MiniWindow *miniwindow=NULL;

    QMenu *menu;

signals:
    void signal_showAbout();
};

#endif // MAINWINDOW_H
