#include "mainwindow.h"
#include "miniwindow.h"
#include "about.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication mainProgram(argc, argv);
    MainWindow mainWindow;
    About about;

    mainWindow.show();

    QObject::connect(&mainWindow,SIGNAL(signal_showAbout()),&about,SLOT(showAbout_slot()));

    return mainProgram.exec();
}
