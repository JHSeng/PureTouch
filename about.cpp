#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->labGithub->setOpenExternalLinks(true);
    setAutoFillBackground(true);
    setWindowFlags(Qt::FramelessWindowHint);

    wallpaper->load(":/background/resources/background/background_3.jpg");
    transparency=1;
    setWindowOpacity(transparency);
    palette.setBrush(QPalette::Window,QBrush(wallpaper->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(palette);
}

About::~About()
{
    delete ui;
}

void About::showAbout_slot()
{
    this->show();
}
