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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *btnMinimize;
    QPushButton *btnClose;
    QPushButton *btnSettings;
    QPushButton *btnMiniStyle;
    QPushButton *btnSetBackGround;
    QPushButton *btnPlayPreSong;
    QPushButton *btnPlayOrPause;
    QPushButton *btnPlayNextSong;
    QPushButton *btnLocalMusic;
    QStackedWidget *playList;
    QWidget *page;
    QListWidget *localMusicList;
    QWidget *page_3;
    QListWidget *myFavouriteList;
    QWidget *page_2;
    QListWidget *playlistList;
    QWidget *page_4;
    QListWidget *listWidget_4;
    QPushButton *btnShowOrHideList;
    QPushButton *btnMyFavourite;
    QPushButton *btnPlayList;
    QPushButton *btnSelectPlayMode;
    QPushButton *btnVolume;
    QSlider *songSlider;
    QPushButton *btnAddSong;
    QPushButton *btnSearch;
    QLineEdit *searchBar;
    QSlider *volumeSlider;
    QLabel *labPlayState;
    QPushButton *btnAddToCurrentList;
    QLabel *labTime;

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
"	background-image: url(:/icon/resources/icon/minimize.png);\n"
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
"	background-image: url(:/icon/resources/icon/close.png);\n"
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
"	background-image: url(:/icon/resources/icon/settings.png);\n"
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
"	background-image: url(:/icon/resources/icon/miniStyle.png);\n"
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
        btnSetBackGround = new QPushButton(MainWindow);
        btnSetBackGround->setObjectName(QStringLiteral("btnSetBackGround"));
        btnSetBackGround->setGeometry(QRect(710, 10, 32, 32));
        btnSetBackGround->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/skin.png);\n"
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
        btnPlayPreSong = new QPushButton(MainWindow);
        btnPlayPreSong->setObjectName(QStringLiteral("btnPlayPreSong"));
        btnPlayPreSong->setGeometry(QRect(20, 540, 48, 48));
        btnPlayPreSong->setStyleSheet(QLatin1String("QPushButton\n"
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
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"	border-color:rgba(255,255,255,30);\n"
"	border-style:inset;\n"
"	color:rgba(0,0,0,100);\n"
"}\n"
""));
        btnPlayOrPause = new QPushButton(MainWindow);
        btnPlayOrPause->setObjectName(QStringLiteral("btnPlayOrPause"));
        btnPlayOrPause->setGeometry(QRect(80, 540, 48, 48));
        btnPlayOrPause->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
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
        btnPlayNextSong = new QPushButton(MainWindow);
        btnPlayNextSong->setObjectName(QStringLiteral("btnPlayNextSong"));
        btnPlayNextSong->setGeometry(QRect(140, 540, 48, 48));
        btnPlayNextSong->setStyleSheet(QLatin1String("QPushButton\n"
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
        btnLocalMusic = new QPushButton(MainWindow);
        btnLocalMusic->setObjectName(QStringLiteral("btnLocalMusic"));
        btnLocalMusic->setGeometry(QRect(10, 10, 32, 32));
        btnLocalMusic->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/localMusic.png);\n"
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
        playList = new QStackedWidget(MainWindow);
        playList->setObjectName(QStringLiteral("playList"));
        playList->setGeometry(QRect(1, 50, 300, 481));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        localMusicList = new QListWidget(page);
        localMusicList->setObjectName(QStringLiteral("localMusicList"));
        localMusicList->setGeometry(QRect(1, 0, 300, 481));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        localMusicList->setFont(font);
        localMusicList->setContextMenuPolicy(Qt::CustomContextMenu);
        localMusicList->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Comic Sans MS\";\n"
"background-color:transparent;"));
        localMusicList->setFrameShape(QFrame::NoFrame);
        localMusicList->setFrameShadow(QFrame::Raised);
        localMusicList->setLineWidth(1);
        localMusicList->setMidLineWidth(1);
        localMusicList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        localMusicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        playList->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        myFavouriteList = new QListWidget(page_3);
        myFavouriteList->setObjectName(QStringLiteral("myFavouriteList"));
        myFavouriteList->setGeometry(QRect(1, 0, 300, 500));
        myFavouriteList->setFont(font);
        myFavouriteList->setContextMenuPolicy(Qt::CustomContextMenu);
        myFavouriteList->setStyleSheet(QLatin1String("font: 75 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"background-color:transparent;"));
        myFavouriteList->setFrameShape(QFrame::NoFrame);
        myFavouriteList->setFrameShadow(QFrame::Plain);
        myFavouriteList->setLineWidth(0);
        myFavouriteList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        myFavouriteList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        myFavouriteList->setBatchSize(100);
        playList->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        playlistList = new QListWidget(page_2);
        playlistList->setObjectName(QStringLiteral("playlistList"));
        playlistList->setGeometry(QRect(1, 0, 300, 500));
        playlistList->setFont(font);
        playlistList->setContextMenuPolicy(Qt::CustomContextMenu);
        playlistList->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"background-color:transparent;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Comic Sans MS\";\n"
"\n"
"\n"
"}"));
        playlistList->setFrameShape(QFrame::NoFrame);
        playlistList->setFrameShadow(QFrame::Plain);
        playlistList->setLineWidth(0);
        playlistList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        playlistList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        playlistList->setSortingEnabled(false);
        playList->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        listWidget_4 = new QListWidget(page_4);
        listWidget_4->setObjectName(QStringLiteral("listWidget_4"));
        listWidget_4->setGeometry(QRect(1, 0, 300, 500));
        listWidget_4->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_4->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"background-color:transparent;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Comic Sans MS\";\n"
"\n"
"\n"
"}"));
        listWidget_4->setFrameShape(QFrame::NoFrame);
        listWidget_4->setLineWidth(0);
        listWidget_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        playList->addWidget(page_4);
        btnShowOrHideList = new QPushButton(MainWindow);
        btnShowOrHideList->setObjectName(QStringLiteral("btnShowOrHideList"));
        btnShowOrHideList->setGeometry(QRect(260, 10, 32, 32));
        btnShowOrHideList->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
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
        btnMyFavourite = new QPushButton(MainWindow);
        btnMyFavourite->setObjectName(QStringLiteral("btnMyFavourite"));
        btnMyFavourite->setGeometry(QRect(100, 10, 32, 32));
        btnMyFavourite->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/myFavouriteList.png);\n"
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
        btnPlayList = new QPushButton(MainWindow);
        btnPlayList->setObjectName(QStringLiteral("btnPlayList"));
        btnPlayList->setGeometry(QRect(180, 10, 31, 31));
        btnPlayList->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/playList.png);\n"
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
        btnSelectPlayMode = new QPushButton(MainWindow);
        btnSelectPlayMode->setObjectName(QStringLiteral("btnSelectPlayMode"));
        btnSelectPlayMode->setGeometry(QRect(820, 550, 32, 32));
        btnSelectPlayMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
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
        btnVolume = new QPushButton(MainWindow);
        btnVolume->setObjectName(QStringLiteral("btnVolume"));
        btnVolume->setGeometry(QRect(880, 550, 32, 32));
        btnVolume->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
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
        songSlider = new QSlider(MainWindow);
        songSlider->setObjectName(QStringLiteral("songSlider"));
        songSlider->setGeometry(QRect(220, 550, 491, 31));
        songSlider->setCursor(QCursor(Qt::PointingHandCursor));
        songSlider->setStyleSheet(QLatin1String("QSlider::add-page:Horizontal\n"
"{     \n"
"	background-color: rgba(255, 255, 255,100);\n"
"    height:4px;  \n"
"}\n"
"\n"
"QSlider::sub-page:Horizontal   \n"
"{  \n"
"	background-color: rgb(255, 255, 255);\n"
"    height:4px;\n"
"}\n"
"\n"
"QSlider::groove:Horizontal   \n"
"{ \n"
"    background:transparent; \n"
"    height:4px;\n"
"}  \n"
"\n"
"QSlider::handle:Horizontal  \n"
"{ \n"
"    height:16px; \n"
"    width:16px; \n"
"	border-image: url(:/icon/resources/icon/greyDot.png);\n"
"    margin: -6 0px; \n"
"}\n"
"      \n"
""));
        songSlider->setOrientation(Qt::Horizontal);
        btnAddSong = new QPushButton(MainWindow);
        btnAddSong->setObjectName(QStringLiteral("btnAddSong"));
        btnAddSong->setGeometry(QRect(360, 10, 32, 32));
        btnAddSong->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/addSong.png);\n"
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
        btnSearch = new QPushButton(MainWindow);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setGeometry(QRect(620, 10, 32, 32));
        btnSearch->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/icon/resources/icon/search.png);\n"
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
        searchBar = new QLineEdit(MainWindow);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(410, 10, 200, 32));
        searchBar->setCursor(QCursor(Qt::IBeamCursor));
        searchBar->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color: rgba(255, 255, 255,150);\n"
"border-style:outset;\n"
"\n"
"border-width:0px;\n"
"\n"
"border-radius:10px;\n"
"border-color: rgba(0,0,0,100);\n"
"font:bold 14px;\n"
"color:rgba(0,0,0,100);\n"
"padding:6px;\n"
"}"));
        volumeSlider = new QSlider(MainWindow);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(880, 370, 35, 161));
        volumeSlider->setCursor(QCursor(Qt::PointingHandCursor));
        volumeSlider->setStyleSheet(QLatin1String(" QSlider \n"
"{  \n"
"    background-color: rgba(20, 20, 20,200);\n"
"    min-width:5px; \n"
"    max-width:5px;\n"
"    border:15px solid rgba(25, 38, 58,100); \n"
"}\n"
"\n"
"QSlider::add-page:vertical\n"
"{      \n"
"    background-color: rgb(250, 250, 0);\n"
"    width:4px;\n"
"}\n"
"\n"
"QSlider::sub-page:vertical  \n"
"{\n"
"    background-color: rgb(87, 97, 106); \n"
"    width:4px;\n"
"}\n"
"\n"
"QSlider::groove:vertical \n"
"{\n"
"    background:transparent;\n"
"    width:6px;\n"
"}\n"
"\n"
"QSlider::handle:vertical \n"
"{\n"
"    height: 13px;\n"
"    width:13px;\n"
"    margin: -0 -4px; \n"
"	border-image: url(:/icon/resources/icon/yellowDot.png);\n"
"}"));
        volumeSlider->setOrientation(Qt::Vertical);
        volumeSlider->setTickPosition(QSlider::NoTicks);
        labPlayState = new QLabel(MainWindow);
        labPlayState->setObjectName(QStringLiteral("labPlayState"));
        labPlayState->setGeometry(QRect(330, 500, 521, 20));
        labPlayState->setStyleSheet(QLatin1String("font: 75 11pt \"Comic Sans MS\";\n"
"color: rgb(112, 112, 112);"));
        btnAddToCurrentList = new QPushButton(MainWindow);
        btnAddToCurrentList->setObjectName(QStringLiteral("btnAddToCurrentList"));
        btnAddToCurrentList->setGeometry(QRect(750, 550, 32, 32));
        btnAddToCurrentList->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
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
        labTime = new QLabel(MainWindow);
        labTime->setObjectName(QStringLiteral("labTime"));
        labTime->setGeometry(QRect(600, 530, 111, 21));
        labTime->setStyleSheet(QLatin1String("font: 75 italic 11pt \"Comic Sans MS\";\n"
"color: rgb(112, 112, 112);"));

        retranslateUi(MainWindow);

        playList->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PureTouch", nullptr));
        btnMinimize->setText(QString());
        btnClose->setText(QString());
        btnSettings->setText(QString());
        btnMiniStyle->setText(QString());
        btnSetBackGround->setText(QString());
        btnPlayPreSong->setText(QString());
        btnPlayOrPause->setText(QString());
        btnPlayNextSong->setText(QString());
        btnLocalMusic->setText(QString());
        btnShowOrHideList->setText(QString());
        btnMyFavourite->setText(QString());
        btnPlayList->setText(QString());
        btnSelectPlayMode->setText(QString());
        btnVolume->setText(QString());
        btnAddSong->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSearch->setToolTip(QApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
#endif // QT_NO_TOOLTIP
        btnSearch->setText(QString());
#ifndef QT_NO_TOOLTIP
        searchBar->setToolTip(QApplication::translate("MainWindow", "\350\276\223\345\205\245\346\255\214\346\233\262\346\210\226\346\255\214\346\211\213", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        searchBar->setStatusTip(QApplication::translate("MainWindow", "\350\276\223\345\205\245\346\255\214\346\233\262", nullptr));
#endif // QT_NO_STATUSTIP
        labPlayState->setText(QString());
        btnAddToCurrentList->setText(QString());
        labTime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
