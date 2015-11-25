/****************************************************************************
** Meta object code from reading C++ file 'Tline.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Tline.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TLine_t {
    QByteArrayData data[9];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TLine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TLine_t qt_meta_stringdata_TLine = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 9),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 8),
QT_MOC_LITERAL(4, 26, 10),
QT_MOC_LITERAL(5, 37, 11),
QT_MOC_LITERAL(6, 49, 12),
QT_MOC_LITERAL(7, 62, 6),
QT_MOC_LITERAL(8, 69, 19)
    },
    "TLine\0endedLine\0\0TResult*\0lineResult\0"
    "startedLine\0typingAnswer\0answer\0"
    "preventBadSelection\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TLine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06,
       5,    0,   37,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   38,    2, 0x0a,
       8,    0,   41,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void TLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TLine *_t = static_cast<TLine *>(_o);
        switch (_id) {
        case 0: _t->endedLine((*reinterpret_cast< TResult*(*)>(_a[1]))); break;
        case 1: _t->startedLine(); break;
        case 2: _t->typingAnswer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->preventBadSelection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TLine::*_t)(TResult * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TLine::endedLine)) {
                *result = 0;
            }
        }
        {
            typedef void (TLine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TLine::startedLine)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject TLine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TLine.data,
      qt_meta_data_TLine,  qt_static_metacall, 0, 0}
};


const QMetaObject *TLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TLine.stringdata))
        return static_cast<void*>(const_cast< TLine*>(this));
    return QWidget::qt_metacast(_clname);
}

int TLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TLine::endedLine(TResult * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TLine::startedLine()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
