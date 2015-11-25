/****************************************************************************
** Meta object code from reading C++ file 'TWindowTest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TWindowTest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TWindowTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TWindowTest_t {
    QByteArrayData data[8];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TWindowTest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TWindowTest_t qt_meta_stringdata_TWindowTest = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 13),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 8),
QT_MOC_LITERAL(4, 36, 6),
QT_MOC_LITERAL(5, 43, 8),
QT_MOC_LITERAL(6, 52, 13),
QT_MOC_LITERAL(7, 66, 13)
    },
    "TWindowTest\0endOfExercice\0\0TResult*\0"
    "exeRes\0nextLine\0previousScore\0"
    "beginExercice\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TWindowTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   32,    2, 0x0a,
       7,    0,   35,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void,

       0        // eod
};

void TWindowTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TWindowTest *_t = static_cast<TWindowTest *>(_o);
        switch (_id) {
        case 0: _t->endOfExercice((*reinterpret_cast< TResult*(*)>(_a[1]))); break;
        case 1: _t->nextLine((*reinterpret_cast< TResult*(*)>(_a[1]))); break;
        case 2: _t->beginExercice(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TWindowTest::*_t)(TResult * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TWindowTest::endOfExercice)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TWindowTest::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TWindowTest.data,
      qt_meta_data_TWindowTest,  qt_static_metacall, 0, 0}
};


const QMetaObject *TWindowTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TWindowTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TWindowTest.stringdata))
        return static_cast<void*>(const_cast< TWindowTest*>(this));
    return QWidget::qt_metacast(_clname);
}

int TWindowTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TWindowTest::endOfExercice(TResult * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
