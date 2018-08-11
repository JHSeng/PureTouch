/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *btnMinimize;
    QPushButton *btnClose;
    QPushButton *btnSettings;
    QPushButton *btnMiniStyle;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(955, 595);
        btnMinimize = new QPushButton(MainWindow);
        btnMinimize->setObjectName(QStringLiteral("btnMinimize"));
        btnMinimize->setGeometry(QRect(860, 10, 32, 32));
        btnMinimize->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/resources/icon/minimize.png);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border-style:outset;\n"
"	border-color:rgba(255,255,255,0);\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgba(255, 255, 255,100);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"	border-color:rgba(255,255,255,30);\n"
"	border-style:inset;\n"
"	color:rgba(0,0,0,100);\n"
"}\n"
""));
        btnClose = new QPushButton(MainWindow);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(910, 10, 32, 32));
        btnClose->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/resources/icon/close.png);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border-style:outset;\n"
"	border-color:rgba(255,255,255,0);\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgba(255, 255, 255,100);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"	border-color:rgba(255,255,255,30);\n"
"	border-style:inset;\n"
"	color:rgba(0,0,0,100);\n"
"}\n"
""));
        btnSettings = new QPushButton(MainWindow);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        btnSettings->setGeometry(QRect(810, 10, 32, 32));
        btnSettings->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/resources/icon/settings.png);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border-style:outset;\n"
"	border-color:rgba(255,255,255,0);\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgba(255, 255, 255,100);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"	border-color:rgba(255,255,255,30);\n"
"	border-style:inset;\n"
"	color:rgba(0,0,0,100);\n"
"}\n"
""));
        btnMiniStyle = new QPushButton(MainWindow);
        btnMiniStyle->setObjectName(QStringLiteral("btnMiniStyle"));
        btnMiniStyle->setGeometry(QRect(760, 10, 32, 32));
        btnMiniStyle->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/resources/icon/miniStyle.png);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border-style:outset;\n"
"	border-color:rgba(255,255,255,0);\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgba(255, 255, 255,100);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"	border-color:rgba(255,255,255,30);\n"
"	border-style:inset;\n"
"	color:rgba(0,0,0,100);\n"
"}\n"
""));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PureTouch", nullptr));
        btnMinimize->setText(QString());
        btnClose->setText(QString());
        btnSettings->setText(QString());
        btnMiniStyle->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
