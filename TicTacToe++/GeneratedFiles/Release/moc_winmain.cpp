/****************************************************************************
** Meta object code from reading C++ file 'winmain.h'
**
** Created: Wed Jan 5 16:42:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../winmain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'winmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_winMain[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      19,    8,    8,    8, 0x0a,
      31,    8,    8,    8, 0x0a,
      41,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_winMain[] = {
    "winMain\0\0newGame()\0aboutGame()\0aboutQt()\0"
    "btnPressed()\0"
};

const QMetaObject winMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_winMain,
      qt_meta_data_winMain, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &winMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *winMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *winMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_winMain))
        return static_cast<void*>(const_cast< winMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int winMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newGame(); break;
        case 1: aboutGame(); break;
        case 2: aboutQt(); break;
        case 3: btnPressed(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
