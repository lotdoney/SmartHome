/****************************************************************************
** Meta object code from reading C++ file 'air_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AirDialog/air_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'air_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_air_Dialog_t {
    QByteArrayData data[8];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_air_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_air_Dialog_t qt_meta_stringdata_air_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "air_Dialog"
QT_MOC_LITERAL(1, 11, 11), // "writeFinish"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 24), // "on_dialTemp_valueChanged"
QT_MOC_LITERAL(4, 49, 5), // "value"
QT_MOC_LITERAL(5, 55, 17), // "serialDataProcess"
QT_MOC_LITERAL(6, 73, 22), // "on_dialRh_valueChanged"
QT_MOC_LITERAL(7, 96, 13) // "writeTempData"

    },
    "air_Dialog\0writeFinish\0\0"
    "on_dialTemp_valueChanged\0value\0"
    "serialDataProcess\0on_dialRh_valueChanged\0"
    "writeTempData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_air_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void air_Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        air_Dialog *_t = static_cast<air_Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeFinish(); break;
        case 1: _t->on_dialTemp_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->serialDataProcess(); break;
        case 3: _t->on_dialRh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->writeTempData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (air_Dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&air_Dialog::writeFinish)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject air_Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_air_Dialog.data,
      qt_meta_data_air_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *air_Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *air_Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_air_Dialog.stringdata0))
        return static_cast<void*>(const_cast< air_Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int air_Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void air_Dialog::writeFinish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
