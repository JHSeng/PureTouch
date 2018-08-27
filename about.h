#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

private slots:
    void showAbout_slot();

private:
    Ui::About *ui;

    QPixmap *wallpaper=new QPixmap;
    double transparency;
    QPalette palette;

};

#endif // ABOUT_H
