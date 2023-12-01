/****************************************************************************
** Meta object code from reading C++ file 'calculadora.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "calculadora.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculadora.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calculadora_t {
    QByteArrayData data[8];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculadora_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculadora_t qt_meta_stringdata_Calculadora = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Calculadora"
QT_MOC_LITERAL(1, 12, 10), // "slotBoton1"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "slotBoton2"
QT_MOC_LITERAL(4, 35, 10), // "slotBoton3"
QT_MOC_LITERAL(5, 46, 12), // "slotBotonMas"
QT_MOC_LITERAL(6, 59, 14), // "slotBotonIgual"
QT_MOC_LITERAL(7, 74, 10) // "slotDigito"

    },
    "Calculadora\0slotBoton1\0\0slotBoton2\0"
    "slotBoton3\0slotBotonMas\0slotBotonIgual\0"
    "slotDigito"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculadora[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Calculadora::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Calculadora *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotBoton1(); break;
        case 1: _t->slotBoton2(); break;
        case 2: _t->slotBoton3(); break;
        case 3: _t->slotBotonMas(); break;
        case 4: _t->slotBotonIgual(); break;
        case 5: _t->slotDigito(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Calculadora::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Calculadora.data,
    qt_meta_data_Calculadora,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculadora::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculadora::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculadora.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::Calculadora"))
        return static_cast< Ui::Calculadora*>(this);
    return QDialog::qt_metacast(_clname);
}

int Calculadora::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
