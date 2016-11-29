/****************************************************************************
** Meta object code from reading C++ file 'AddressFinder.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AddressFinder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddressFinder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddressFinder[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      35,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddressFinder[] = {
    "AddressFinder\0\0QAction_Triggered()\0"
    "QPushButton_Clicked()\0"
};

void AddressFinder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddressFinder *_t = static_cast<AddressFinder *>(_o);
        switch (_id) {
        case 0: _t->QAction_Triggered(); break;
        case 1: _t->QPushButton_Clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AddressFinder::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddressFinder::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AddressFinder,
      qt_meta_data_AddressFinder, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddressFinder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddressFinder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddressFinder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddressFinder))
        return static_cast<void*>(const_cast< AddressFinder*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AddressFinder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
