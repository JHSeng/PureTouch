#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication mainProgram(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();

    return mainProgram.exec();
}
