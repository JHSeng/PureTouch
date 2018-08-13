/********************************************************************************
** Form generated from reading UI file 'miniwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIWINDOW_H
#define UI_MINIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_MiniWindow
{
public:
    QPushButton *btnMinimize;
    QPushButton *btnClose;
    QPushButton *btnPreSong;
    QPushButton *btnPlayOrPause;
    QSlider *songSlider;
    QPushButton *btnNextSong;
    QPushButton *btnNormalStyle;

    void setupUi(QDialog *MiniWindow)
    {
        if (MiniWindow->objectName().isEmpty())
            MiniWindow->setObjectName(QStringLiteral("MiniWindow"));
        MiniWindow->resize(501, 133);
        btnMinimize = new QPushButton(MiniWindow);
        btnMinimize->setObjectName(QStringLiteral("btnMinimize"));
        btnMinimize->setGeometry(QRect(420, 0, 32, 32));
        btnMinimize->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/minimize.png);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border-style:outset;\n"
"	border-color:rgba(255,255,255,0);\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(255, 255, 255,100);\n"
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
        btnClose = new QPushButton(MiniWindow);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(460, 0, 32, 32));
        btnClose->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/close.png);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border-style:outset;\n"
"	border-color:rgba(255,255,255,0);\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(255, 255, 255,100);\n"
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
        btnPreSong = new QPushButton(MiniWindow);
        btnPreSong->setObjectName(QStringLiteral("btnPreSong"));
        btnPreSong->setGeometry(QRect(130, 70, 48, 48));
        btnPreSong->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/playPreSong.png);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border-style:outset;\n"
"	border-color:rgba(255,255,255,0);\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(255, 255, 255,100);\n"
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
        btnPlayOrPause = new QPushButton(MiniWindow);
        btnPlayOrPause->setObjectName(QStringLiteral("btnPlayOrPause"));
        btnPlayOrPause->setGeometry(QRect(230, 70, 48, 48));
        btnPlayOrPause->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        songSlider = new QSlider(MiniWindow);
        songSlider->setObjectName(QStringLiteral("songSlider"));
        songSlider->setGeometry(QRect(40, 50, 431, 22));
        songSlider->setCursor(QCursor(Qt::PointingHandCursor));
        songSlider->setStyleSheet(QString::fromUtf8("\n"
"    QSlider::add-page:Horizontal\n"
"     {     \n"
"background-color: rgba(255, 255, 255,100);\n"
"        height:4px;  \n"
"     } \n"
"     QSlider::sub-page:Horizontal   \n"
"    {  \n"
"background-color: rgb(255, 255, 255);\n"
"        height:4px;\n"
"     }\n"
"    QSlider::groove:Horizontal   \n"
"    { \n"
"        background:transparent; \n"
"        height:4px;\n"
"    }  \n"
"    QSlider::handle:Horizontal  \n"
"    { \n"
"        height:16px; \n"
"        width:16px; \n"
"	\n"
"	border-image: url(:/image/image/\345\234\206\345\275\242 (9).png);\n"
"  margin: -6 0px; \n"
"    }\n"
"      \n"
""));
        songSlider->setOrientation(Qt::Horizontal);
        btnNextSong = new QPushButton(MiniWindow);
        btnNextSong->setObjectName(QStringLiteral("btnNextSong"));
        btnNextSong->setGeometry(QRect(330, 70, 48, 48));
        btnNextSong->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/playNextSong.png);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border-style:outset;\n"
"	border-color:rgba(255,255,255,0);\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(255, 255, 255,100);\n"
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
        btnNormalStyle = new QPushButton(MiniWindow);
        btnNormalStyle->setObjectName(QStringLiteral("btnNormalStyle"));
        btnNormalStyle->setGeometry(QRect(0, 0, 48, 48));
        btnNormalStyle->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/PureTouchIcon3.ico);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border-style:outset;\n"
"	border-color:rgba(255,255,255,0);\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(255, 255, 255,100);\n"
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
        btnNormalStyle->setIconSize(QSize(256, 256));

        retranslateUi(MiniWindow);

        QMetaObject::connectSlotsByName(MiniWindow);
    } // setupUi

    void retranslateUi(QDialog *MiniWindow)
    {
        MiniWindow->setWindowTitle(QApplication::translate("MiniWindow", "Dialog", nullptr));
        btnMinimize->setText(QString());
        btnClose->setText(QString());
        btnPreSong->setText(QString());
        btnPlayOrPause->setText(QString());
        btnNextSong->setText(QString());
        btnNormalStyle->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MiniWindow: public Ui_MiniWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIWINDOW_H
