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

    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *playList_LocalMusic;
    QMediaPlaylist *playList_MyFavourite;
    QMediaPlaylist *playList_PlayList;

    QSqlTableModel *model_1;
    QSqlTableModel *model_2;
    QSqlTableModel *model_3;

};

#endif // MAINWINDOW_H
