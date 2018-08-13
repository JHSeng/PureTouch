#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->labGithub->setOpenExternalLinks(true);
}

About::~About()
{
    delete ui;
}

void About::showAbout_slot()
{
    this->show();
}
