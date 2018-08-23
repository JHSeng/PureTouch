#include "mainwindow.h"
#include "miniwindow.h"
#include "about.h"
#include "connection.h"

#include <QApplication>
#include <QTime>
#include <QVariant>

int main(int argc, char *argv[])
{
    if (!CreateConnection()) return 1;
    QApplication mainProgram(argc, argv);
    MainWindow mainWindow;
    About about;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QObject::connect(&mainWindow,SIGNAL(signal_showAbout()),&about,SLOT(showAbout_slot()));

    mainWindow.setWindowIcon(QIcon(":/icon/resources/icon/PureTouchIcon3.ico"));
    mainWindow.setWindowTitle(QObject::tr("PureTouch"));
    mainWindow.setWindowFlags(Qt::FramelessWindowHint);
    mainWindow.show();

    return mainProgram.exec();
}
