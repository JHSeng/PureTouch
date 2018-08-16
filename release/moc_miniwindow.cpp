/****************************************************************************
** Meta object code from reading C++ file 'miniwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../miniwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'miniwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MiniWindow_t {
    QByteArrayData data[22];
    char stringdata0[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MiniWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MiniWindow_t qt_meta_stringdata_MiniWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MiniWindow"
QT_MOC_LITERAL(1, 11, 4), // "Data"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 3), // "row"
QT_MOC_LITERAL(4, 21, 8), // "position"
QT_MOC_LITERAL(5, 30, 15), // "QMediaPlaylist*"
QT_MOC_LITERAL(6, 46, 4), // "list"
QT_MOC_LITERAL(7, 51, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(8, 71, 5), // "state"
QT_MOC_LITERAL(9, 77, 28), // "QMediaPlaylist::PlaybackMode"
QT_MOC_LITERAL(10, 106, 5), // "model"
QT_MOC_LITERAL(11, 112, 19), // "on_btnClose_clicked"
QT_MOC_LITERAL(12, 132, 25), // "on_btnNormalStyle_clicked"
QT_MOC_LITERAL(13, 158, 22), // "on_btnMinimize_clicked"
QT_MOC_LITERAL(14, 181, 25), // "on_btnPlayOrPause_clicked"
QT_MOC_LITERAL(15, 207, 22), // "on_btnNextSong_clicked"
QT_MOC_LITERAL(16, 230, 21), // "on_btnPreSong_clicked"
QT_MOC_LITERAL(17, 252, 16), // "playOrPause_slot"
QT_MOC_LITERAL(18, 269, 17), // "playNextSong_slot"
QT_MOC_LITERAL(19, 287, 16), // "playPreSong_slot"
QT_MOC_LITERAL(20, 304, 28), // "on_btnSelectPlayMode_clicked"
QT_MOC_LITERAL(21, 333, 24) // "playBackModeChanged_slot"

    },
    "MiniWindow\0Data\0\0row\0position\0"
    "QMediaPlaylist*\0list\0QMediaPlayer::State\0"
    "state\0QMediaPlaylist::PlaybackMode\0"
    "model\0on_btnClose_clicked\0"
    "on_btnNormalStyle_clicked\0"
    "on_btnMinimize_clicked\0on_btnPlayOrPause_clicked\0"
    "on_btnNextSong_clicked\0on_btnPreSong_clicked\0"
    "playOrPause_slot\0playNextSong_slot\0"
    "playPreSong_slot\0on_btnSelectPlayMode_clicked\0"
    "playBackModeChanged_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MiniWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    0,   91,    2, 0x08 /* Private */,
      18,    0,   92,    2, 0x08 /* Private */,
      19,    0,   93,    2, 0x08 /* Private */,
      20,    0,   94,    2, 0x08 /* Private */,
      21,    1,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 9,    3,    4,    6,    8,   10,

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
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void MiniWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MiniWindow *_t = static_cast<MiniWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Data((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QMediaPlaylist*(*)>(_a[3])),(*reinterpret_cast< QMediaPlayer::State(*)>(_a[4])),(*reinterpret_cast< QMediaPlaylist::PlaybackMode(*)>(_a[5]))); break;
        case 1: _t->on_btnClose_clicked(); break;
        case 2: _t->on_btnNormalStyle_clicked(); break;
        case 3: _t->on_btnMinimize_clicked(); break;
        case 4: _t->on_btnPlayOrPause_clicked(); break;
        case 5: _t->on_btnNextSong_clicked(); break;
        case 6: _t->on_btnPreSong_clicked(); break;
        case 7: _t->playOrPause_slot(); break;
        case 8: _t->playNextSong_slot(); break;
        case 9: _t->playPreSong_slot(); break;
        case 10: _t->on_btnSelectPlayMode_clicked(); break;
        case 11: _t->playBackModeChanged_slot((*reinterpret_cast< QMediaPlaylist::PlaybackMode(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
        case 11:
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
            using _t = void (MiniWindow::*)(int , int , QMediaPlaylist * , QMediaPlayer::State , QMediaPlaylist::PlaybackMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniWindow::Data)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MiniWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MiniWindow.data,
      qt_meta_data_MiniWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MiniWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MiniWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MiniWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MiniWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MiniWindow::Data(int _t1, int _t2, QMediaPlaylist * _t3, QMediaPlayer::State _t4, QMediaPlaylist::PlaybackMode _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
