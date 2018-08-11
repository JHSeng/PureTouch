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
};

#endif // MAINWINDOW_H
