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
};

#endif // MAINWINDOW_H
