#ifndef MINIWINDOW_H
#define MINIWINDOW_H

#include <QDialog>
#include <QPoint>
#include <QMouseEvent>
#include <QPixmap>
#include <QPalette>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QAction>

#include "mainwindow.h"

namespace Ui {
class MiniWindow;
}

class MiniWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MiniWindow(QWidget *parent = 0);
    ~MiniWindow();

    void setPlaylist(QMediaPlaylist *list,int row,int position,int volume,QMediaPlayer::State state,QMediaPlaylist::PlaybackMode playmodel,int i);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void updateSongInfo();
    void updateSongPosition(qint64 position);
    void updateSongDuration(qint64 duration);
    void playStateChange(QMediaPlayer::State state);
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void on_btnClose_clicked();

    void on_btnNormalStyle_clicked();

    void on_btnMinimize_clicked();

    void on_btnPlayOrPause_clicked();

    void on_btnNextSong_clicked();

    void on_btnPreSong_clicked();

    void playOrPause_slot();

    void playNextSong_slot();

    void playPreSong_slot();

    void on_btnSelectPlayMode_clicked();

    void playBackModeChanged_slot(QMediaPlaylist::PlaybackMode model);

private:
    Ui::MiniWindow *ui;

    double TouMin;

    QAction *playOrPause;
    QAction *playNextSong;
    QAction *playPreSong;

    QPixmap wallpaper;
    QPalette pal;
    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *playList;
    QMenu *menu;
    QPoint offset;

signals:
    void Data(int row,int position,QMediaPlaylist *list,QMediaPlayer::State state,QMediaPlaylist::PlaybackMode model);

};

#endif // MINIWINDOW_H
