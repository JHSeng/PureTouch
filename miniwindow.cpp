#include "miniwindow.h"
#include "ui_miniwindow.h"

MiniWindow::MiniWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MiniWindow)
{
    ui->setupUi(this);
}

MiniWindow::~MiniWindow()
{
    delete ui;
}

void MiniWindow::setPlaylist(QMediaPlaylist *list, int row, int position, int volume, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode playmodel, int i)
{

}
