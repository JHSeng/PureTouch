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


private:
    Ui::MiniWindow *ui;
};

#endif // MINIWINDOW_H
