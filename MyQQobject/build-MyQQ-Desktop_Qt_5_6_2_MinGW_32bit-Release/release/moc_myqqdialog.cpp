/****************************************************************************
** Meta object code from reading C++ file 'myqqdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyQQ/myqqdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myqqdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyQQDialog_t {
    QByteArrayData data[14];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQQDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQQDialog_t qt_meta_stringdata_MyQQDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyQQDialog"
QT_MOC_LITERAL(1, 11, 18), // "on_pb_test_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "slot_ReadyData"
QT_MOC_LITERAL(4, 46, 5), // "char*"
QT_MOC_LITERAL(5, 52, 16), // "slot_LoginCommit"
QT_MOC_LITERAL(6, 69, 4), // "name"
QT_MOC_LITERAL(7, 74, 8), // "password"
QT_MOC_LITERAL(8, 83, 19), // "slot_RegisterCommit"
QT_MOC_LITERAL(9, 103, 15), // "solt_RegisterRs"
QT_MOC_LITERAL(10, 119, 3), // "buf"
QT_MOC_LITERAL(11, 123, 4), // "nlen"
QT_MOC_LITERAL(12, 128, 12), // "solt_LoginRs"
QT_MOC_LITERAL(13, 141, 17) // "solt_ForceOffline"

    },
    "MyQQDialog\0on_pb_test_clicked\0\0"
    "slot_ReadyData\0char*\0slot_LoginCommit\0"
    "name\0password\0slot_RegisterCommit\0"
    "solt_RegisterRs\0buf\0nlen\0solt_LoginRs\0"
    "solt_ForceOffline"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQQDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    2,   50,    2, 0x08 /* Private */,
       5,    2,   55,    2, 0x08 /* Private */,
       8,    2,   60,    2, 0x08 /* Private */,
       9,    2,   65,    2, 0x08 /* Private */,
      12,    2,   70,    2, 0x08 /* Private */,
      13,    2,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,   10,   11,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,   10,   11,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,   10,   11,

       0        // eod
};

void MyQQDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyQQDialog *_t = static_cast<MyQQDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pb_test_clicked(); break;
        case 1: _t->slot_ReadyData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->slot_LoginCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->slot_RegisterCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->solt_RegisterRs((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->solt_LoginRs((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->solt_ForceOffline((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MyQQDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MyQQDialog.data,
      qt_meta_data_MyQQDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyQQDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQQDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyQQDialog.stringdata0))
        return static_cast<void*>(const_cast< MyQQDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MyQQDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
