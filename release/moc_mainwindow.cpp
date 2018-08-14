/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[77];
    char stringdata0[1474];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "signal_showAbout"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 24), // "on_btnLocalMusic_clicked"
QT_MOC_LITERAL(4, 54, 25), // "on_btnMyFavourite_clicked"
QT_MOC_LITERAL(5, 80, 22), // "on_btnPlayList_clicked"
QT_MOC_LITERAL(6, 103, 13), // "songInfo_slot"
QT_MOC_LITERAL(7, 117, 20), // "clearLocalMusic_slot"
QT_MOC_LITERAL(8, 138, 21), // "clearMyFavourite_slot"
QT_MOC_LITERAL(9, 160, 18), // "clearPlaylist_slot"
QT_MOC_LITERAL(10, 179, 17), // "clearAllList_slot"
QT_MOC_LITERAL(11, 197, 20), // "addToLocalMusic_slot"
QT_MOC_LITERAL(12, 218, 21), // "addToMyFavourite_slot"
QT_MOC_LITERAL(13, 240, 18), // "addToPlaylist_slot"
QT_MOC_LITERAL(14, 259, 20), // "setBackGround_1_slot"
QT_MOC_LITERAL(15, 280, 20), // "setBackGround_2_slot"
QT_MOC_LITERAL(16, 301, 28), // "setBackground_customize_slot"
QT_MOC_LITERAL(17, 330, 12), // "preSong_slot"
QT_MOC_LITERAL(18, 343, 13), // "nextSong_slot"
QT_MOC_LITERAL(19, 357, 16), // "playOrPause_slot"
QT_MOC_LITERAL(20, 374, 16), // "playInOrder_slot"
QT_MOC_LITERAL(21, 391, 16), // "playShuffle_slot"
QT_MOC_LITERAL(22, 408, 20), // "playSingleCycle_slot"
QT_MOC_LITERAL(23, 429, 16), // "musicStateChange"
QT_MOC_LITERAL(24, 446, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(25, 466, 5), // "state"
QT_MOC_LITERAL(26, 472, 16), // "contextMenuEvent"
QT_MOC_LITERAL(27, 489, 18), // "QContextMenuEvent*"
QT_MOC_LITERAL(28, 508, 5), // "event"
QT_MOC_LITERAL(29, 514, 12), // "Action1_slot"
QT_MOC_LITERAL(30, 527, 12), // "Action2_slot"
QT_MOC_LITERAL(31, 540, 12), // "Action3_slot"
QT_MOC_LITERAL(32, 553, 12), // "Action4_slot"
QT_MOC_LITERAL(33, 566, 12), // "Action5_slot"
QT_MOC_LITERAL(34, 579, 14), // "Action1_2_slot"
QT_MOC_LITERAL(35, 594, 14), // "Action2_2_slot"
QT_MOC_LITERAL(36, 609, 14), // "Action3_2_slot"
QT_MOC_LITERAL(37, 624, 14), // "Action4_2_slot"
QT_MOC_LITERAL(38, 639, 14), // "Action1_3_slot"
QT_MOC_LITERAL(39, 654, 14), // "Action2_3_slot"
QT_MOC_LITERAL(40, 669, 14), // "Action3_3_slot"
QT_MOC_LITERAL(41, 684, 11), // "Action_slot"
QT_MOC_LITERAL(42, 696, 13), // "Action_1_slot"
QT_MOC_LITERAL(43, 710, 13), // "Action_2_slot"
QT_MOC_LITERAL(44, 724, 13), // "Action_3_slot"
QT_MOC_LITERAL(45, 738, 13), // "Action_4_slot"
QT_MOC_LITERAL(46, 752, 25), // "on_btnPlayOrPause_clicked"
QT_MOC_LITERAL(47, 778, 26), // "on_btnPlayNextSong_clicked"
QT_MOC_LITERAL(48, 805, 25), // "on_btnPlayPreSong_clicked"
QT_MOC_LITERAL(49, 831, 28), // "on_btnShowOrHideList_clicked"
QT_MOC_LITERAL(50, 860, 28), // "on_btnSelectPlayMode_clicked"
QT_MOC_LITERAL(51, 889, 31), // "on_localMusicList_doubleClicked"
QT_MOC_LITERAL(52, 921, 11), // "QModelIndex"
QT_MOC_LITERAL(53, 933, 5), // "index"
QT_MOC_LITERAL(54, 939, 32), // "on_myFavouriteList_doubleClicked"
QT_MOC_LITERAL(55, 972, 29), // "on_playlistList_doubleClicked"
QT_MOC_LITERAL(56, 1002, 22), // "on_btnMinimize_clicked"
QT_MOC_LITERAL(57, 1025, 19), // "on_btnClose_clicked"
QT_MOC_LITERAL(58, 1045, 20), // "on_btnVolume_clicked"
QT_MOC_LITERAL(59, 1066, 44), // "on_localMusicList_customConte..."
QT_MOC_LITERAL(60, 1111, 3), // "pos"
QT_MOC_LITERAL(61, 1115, 45), // "on_myFavouriteList_customCont..."
QT_MOC_LITERAL(62, 1161, 42), // "on_playlistList_customContext..."
QT_MOC_LITERAL(63, 1204, 23), // "on_btnMiniStyle_clicked"
QT_MOC_LITERAL(64, 1228, 9), // "Data_slot"
QT_MOC_LITERAL(65, 1238, 3), // "row"
QT_MOC_LITERAL(66, 1242, 8), // "position"
QT_MOC_LITERAL(67, 1251, 15), // "QMediaPlaylist*"
QT_MOC_LITERAL(68, 1267, 4), // "list"
QT_MOC_LITERAL(69, 1272, 28), // "QMediaPlaylist::PlaybackMode"
QT_MOC_LITERAL(70, 1301, 5), // "model"
QT_MOC_LITERAL(71, 1307, 30), // "on_btnAddToCurrentList_clicked"
QT_MOC_LITERAL(72, 1338, 20), // "on_btnSearch_clicked"
QT_MOC_LITERAL(73, 1359, 27), // "on_searchList_doubleClicked"
QT_MOC_LITERAL(74, 1387, 40), // "on_searchList_customContextMe..."
QT_MOC_LITERAL(75, 1428, 26), // "on_searchBar_returnPressed"
QT_MOC_LITERAL(76, 1455, 18) // "PlaylistModel_slot"

    },
    "MainWindow\0signal_showAbout\0\0"
    "on_btnLocalMusic_clicked\0"
    "on_btnMyFavourite_clicked\0"
    "on_btnPlayList_clicked\0songInfo_slot\0"
    "clearLocalMusic_slot\0clearMyFavourite_slot\0"
    "clearPlaylist_slot\0clearAllList_slot\0"
    "addToLocalMusic_slot\0addToMyFavourite_slot\0"
    "addToPlaylist_slot\0setBackGround_1_slot\0"
    "setBackGround_2_slot\0setBackground_customize_slot\0"
    "preSong_slot\0nextSong_slot\0playOrPause_slot\0"
    "playInOrder_slot\0playShuffle_slot\0"
    "playSingleCycle_slot\0musicStateChange\0"
    "QMediaPlayer::State\0state\0contextMenuEvent\0"
    "QContextMenuEvent*\0event\0Action1_slot\0"
    "Action2_slot\0Action3_slot\0Action4_slot\0"
    "Action5_slot\0Action1_2_slot\0Action2_2_slot\0"
    "Action3_2_slot\0Action4_2_slot\0"
    "Action1_3_slot\0Action2_3_slot\0"
    "Action3_3_slot\0Action_slot\0Action_1_slot\0"
    "Action_2_slot\0Action_3_slot\0Action_4_slot\0"
    "on_btnPlayOrPause_clicked\0"
    "on_btnPlayNextSong_clicked\0"
    "on_btnPlayPreSong_clicked\0"
    "on_btnShowOrHideList_clicked\0"
    "on_btnSelectPlayMode_clicked\0"
    "on_localMusicList_doubleClicked\0"
    "QModelIndex\0index\0on_myFavouriteList_doubleClicked\0"
    "on_playlistList_doubleClicked\0"
    "on_btnMinimize_clicked\0on_btnClose_clicked\0"
    "on_btnVolume_clicked\0"
    "on_localMusicList_customContextMenuRequested\0"
    "pos\0on_myFavouriteList_customContextMenuRequested\0"
    "on_playlistList_customContextMenuRequested\0"
    "on_btnMiniStyle_clicked\0Data_slot\0row\0"
    "position\0QMediaPlaylist*\0list\0"
    "QMediaPlaylist::PlaybackMode\0model\0"
    "on_btnAddToCurrentList_clicked\0"
    "on_btnSearch_clicked\0on_searchList_doubleClicked\0"
    "on_searchList_customContextMenuRequested\0"
    "on_searchBar_returnPressed\0"
    "PlaylistModel_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      62,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  324,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  325,    2, 0x08 /* Private */,
       4,    0,  326,    2, 0x08 /* Private */,
       5,    0,  327,    2, 0x08 /* Private */,
       6,    0,  328,    2, 0x08 /* Private */,
       7,    0,  329,    2, 0x08 /* Private */,
       8,    0,  330,    2, 0x08 /* Private */,
       9,    0,  331,    2, 0x08 /* Private */,
      10,    0,  332,    2, 0x08 /* Private */,
      11,    0,  333,    2, 0x08 /* Private */,
      12,    0,  334,    2, 0x08 /* Private */,
      13,    0,  335,    2, 0x08 /* Private */,
      14,    0,  336,    2, 0x08 /* Private */,
      15,    0,  337,    2, 0x08 /* Private */,
      16,    0,  338,    2, 0x08 /* Private */,
      17,    0,  339,    2, 0x08 /* Private */,
      18,    0,  340,    2, 0x08 /* Private */,
      19,    0,  341,    2, 0x08 /* Private */,
      20,    0,  342,    2, 0x08 /* Private */,
      21,    0,  343,    2, 0x08 /* Private */,
      22,    0,  344,    2, 0x08 /* Private */,
      23,    1,  345,    2, 0x08 /* Private */,
      26,    1,  348,    2, 0x08 /* Private */,
      29,    0,  351,    2, 0x08 /* Private */,
      30,    0,  352,    2, 0x08 /* Private */,
      31,    0,  353,    2, 0x08 /* Private */,
      32,    0,  354,    2, 0x08 /* Private */,
      33,    0,  355,    2, 0x08 /* Private */,
      34,    0,  356,    2, 0x08 /* Private */,
      35,    0,  357,    2, 0x08 /* Private */,
      36,    0,  358,    2, 0x08 /* Private */,
      37,    0,  359,    2, 0x08 /* Private */,
      38,    0,  360,    2, 0x08 /* Private */,
      39,    0,  361,    2, 0x08 /* Private */,
      40,    0,  362,    2, 0x08 /* Private */,
      41,    0,  363,    2, 0x08 /* Private */,
      42,    0,  364,    2, 0x08 /* Private */,
      43,    0,  365,    2, 0x08 /* Private */,
      44,    0,  366,    2, 0x08 /* Private */,
      45,    0,  367,    2, 0x08 /* Private */,
      46,    0,  368,    2, 0x08 /* Private */,
      47,    0,  369,    2, 0x08 /* Private */,
      48,    0,  370,    2, 0x08 /* Private */,
      49,    0,  371,    2, 0x08 /* Private */,
      50,    0,  372,    2, 0x08 /* Private */,
      51,    1,  373,    2, 0x08 /* Private */,
      54,    1,  376,    2, 0x08 /* Private */,
      55,    1,  379,    2, 0x08 /* Private */,
      56,    0,  382,    2, 0x08 /* Private */,
      57,    0,  383,    2, 0x08 /* Private */,
      58,    0,  384,    2, 0x08 /* Private */,
      59,    1,  385,    2, 0x08 /* Private */,
      61,    1,  388,    2, 0x08 /* Private */,
      62,    1,  391,    2, 0x08 /* Private */,
      63,    0,  394,    2, 0x08 /* Private */,
      64,    5,  395,    2, 0x08 /* Private */,
      71,    0,  406,    2, 0x08 /* Private */,
      72,    0,  407,    2, 0x08 /* Private */,
      73,    1,  408,    2, 0x08 /* Private */,
      74,    1,  411,    2, 0x08 /* Private */,
      75,    0,  414,    2, 0x08 /* Private */,
      76,    1,  415,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   60,
    QMetaType::Void, QMetaType::QPoint,   60,
    QMetaType::Void, QMetaType::QPoint,   60,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 67, 0x80000000 | 24, 0x80000000 | 69,   65,   66,   68,   25,   70,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void, QMetaType::QPoint,   60,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 69,   70,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_showAbout(); break;
        case 1: _t->on_btnLocalMusic_clicked(); break;
        case 2: _t->on_btnMyFavourite_clicked(); break;
        case 3: _t->on_btnPlayList_clicked(); break;
        case 4: _t->songInfo_slot(); break;
        case 5: _t->clearLocalMusic_slot(); break;
        case 6: _t->clearMyFavourite_slot(); break;
        case 7: _t->clearPlaylist_slot(); break;
        case 8: _t->clearAllList_slot(); break;
        case 9: _t->addToLocalMusic_slot(); break;
        case 10: _t->addToMyFavourite_slot(); break;
        case 11: _t->addToPlaylist_slot(); break;
        case 12: _t->setBackGround_1_slot(); break;
        case 13: _t->setBackGround_2_slot(); break;
        case 14: _t->setBackground_customize_slot(); break;
        case 15: _t->preSong_slot(); break;
        case 16: _t->nextSong_slot(); break;
        case 17: _t->playOrPause_slot(); break;
        case 18: _t->playInOrder_slot(); break;
        case 19: _t->playShuffle_slot(); break;
        case 20: _t->playSingleCycle_slot(); break;
        case 21: _t->musicStateChange((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 22: _t->contextMenuEvent((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        case 23: _t->Action1_slot(); break;
        case 24: _t->Action2_slot(); break;
        case 25: _t->Action3_slot(); break;
        case 26: _t->Action4_slot(); break;
        case 27: _t->Action5_slot(); break;
        case 28: _t->Action1_2_slot(); break;
        case 29: _t->Action2_2_slot(); break;
        case 30: _t->Action3_2_slot(); break;
        case 31: _t->Action4_2_slot(); break;
        case 32: _t->Action1_3_slot(); break;
        case 33: _t->Action2_3_slot(); break;
        case 34: _t->Action3_3_slot(); break;
        case 35: _t->Action_slot(); break;
        case 36: _t->Action_1_slot(); break;
        case 37: _t->Action_2_slot(); break;
        case 38: _t->Action_3_slot(); break;
        case 39: _t->Action_4_slot(); break;
        case 40: _t->on_btnPlayOrPause_clicked(); break;
        case 41: _t->on_btnPlayNextSong_clicked(); break;
        case 42: _t->on_btnPlayPreSong_clicked(); break;
        case 43: _t->on_btnShowOrHideList_clicked(); break;
        case 44: _t->on_btnSelectPlayMode_clicked(); break;
        case 45: _t->on_localMusicList_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 46: _t->on_myFavouriteList_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 47: _t->on_playlistList_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 48: _t->on_btnMinimize_clicked(); break;
        case 49: _t->on_btnClose_clicked(); break;
        case 50: _t->on_btnVolume_clicked(); break;
        case 51: _t->on_localMusicList_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 52: _t->on_myFavouriteList_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 53: _t->on_playlistList_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 54: _t->on_btnMiniStyle_clicked(); break;
        case 55: _t->Data_slot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QMediaPlaylist*(*)>(_a[3])),(*reinterpret_cast< QMediaPlayer::State(*)>(_a[4])),(*reinterpret_cast< QMediaPlaylist::PlaybackMode(*)>(_a[5]))); break;
        case 56: _t->on_btnAddToCurrentList_clicked(); break;
        case 57: _t->on_btnSearch_clicked(); break;
        case 58: _t->on_searchList_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 59: _t->on_searchList_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 60: _t->on_searchBar_returnPressed(); break;
        case 61: _t->PlaylistModel_slot((*reinterpret_cast< QMediaPlaylist::PlaybackMode(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        case 55:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlaylist* >(); break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlaylist::PlaybackMode >(); break;
            }
            break;
        case 61:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlaylist::PlaybackMode >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_showAbout)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 62)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 62;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 62)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 62;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_showAbout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
