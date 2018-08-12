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
    QByteArrayData data[16];
    char stringdata0[313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_btnLocalMusic_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "on_btnMyFavourite_clicked"
QT_MOC_LITERAL(4, 63, 22), // "on_btnPlayList_clicked"
QT_MOC_LITERAL(5, 86, 13), // "songInfo_slot"
QT_MOC_LITERAL(6, 100, 20), // "clearLocalMusic_slot"
QT_MOC_LITERAL(7, 121, 21), // "clearMyFavourite_slot"
QT_MOC_LITERAL(8, 143, 18), // "clearPlaylist_slot"
QT_MOC_LITERAL(9, 162, 17), // "clearAllList_slot"
QT_MOC_LITERAL(10, 180, 20), // "addToLocalMusic_slot"
QT_MOC_LITERAL(11, 201, 21), // "addToMyFavourite_slot"
QT_MOC_LITERAL(12, 223, 18), // "addToPlaylist_slot"
QT_MOC_LITERAL(13, 242, 20), // "setBackGround_1_slot"
QT_MOC_LITERAL(14, 263, 20), // "setBackGround_2_slot"
QT_MOC_LITERAL(15, 284, 28) // "setBackground_customize_slot"

    },
    "MainWindow\0on_btnLocalMusic_clicked\0"
    "\0on_btnMyFavourite_clicked\0"
    "on_btnPlayList_clicked\0songInfo_slot\0"
    "clearLocalMusic_slot\0clearMyFavourite_slot\0"
    "clearPlaylist_slot\0clearAllList_slot\0"
    "addToLocalMusic_slot\0addToMyFavourite_slot\0"
    "addToPlaylist_slot\0setBackGround_1_slot\0"
    "setBackGround_2_slot\0setBackground_customize_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnLocalMusic_clicked(); break;
        case 1: _t->on_btnMyFavourite_clicked(); break;
        case 2: _t->on_btnPlayList_clicked(); break;
        case 3: _t->songInfo_slot(); break;
        case 4: _t->clearLocalMusic_slot(); break;
        case 5: _t->clearMyFavourite_slot(); break;
        case 6: _t->clearPlaylist_slot(); break;
        case 7: _t->clearAllList_slot(); break;
        case 8: _t->addToLocalMusic_slot(); break;
        case 9: _t->addToMyFavourite_slot(); break;
        case 10: _t->addToPlaylist_slot(); break;
        case 11: _t->setBackGround_1_slot(); break;
        case 12: _t->setBackGround_2_slot(); break;
        case 13: _t->setBackground_customize_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
