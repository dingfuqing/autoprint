/****************************************************************************
** Meta object code from reading C++ file 'datamanagedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../datamanagedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datamanagedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataManageDialog_t {
    QByteArrayData data[14];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataManageDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataManageDialog_t qt_meta_stringdata_DataManageDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DataManageDialog"
QT_MOC_LITERAL(1, 17, 28), // "on_DeletepushButton_released"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 27), // "on_DeletepushButton_pressed"
QT_MOC_LITERAL(4, 75, 28), // "on_UpdatepushButton_released"
QT_MOC_LITERAL(5, 104, 27), // "on_UpdatepushButton_pressed"
QT_MOC_LITERAL(6, 132, 28), // "on_InsertpushButton_released"
QT_MOC_LITERAL(7, 161, 27), // "on_InsertpushButton_pressed"
QT_MOC_LITERAL(8, 189, 27), // "on_QuerypushButton_released"
QT_MOC_LITERAL(9, 217, 26), // "on_QuerypushButton_pressed"
QT_MOC_LITERAL(10, 244, 17), // "ShowTypetableView"
QT_MOC_LITERAL(11, 262, 24), // "on_TypetableView_clicked"
QT_MOC_LITERAL(12, 287, 5), // "index"
QT_MOC_LITERAL(13, 293, 24) // "on_TypetableView_pressed"

    },
    "DataManageDialog\0on_DeletepushButton_released\0"
    "\0on_DeletepushButton_pressed\0"
    "on_UpdatepushButton_released\0"
    "on_UpdatepushButton_pressed\0"
    "on_InsertpushButton_released\0"
    "on_InsertpushButton_pressed\0"
    "on_QuerypushButton_released\0"
    "on_QuerypushButton_pressed\0ShowTypetableView\0"
    "on_TypetableView_clicked\0index\0"
    "on_TypetableView_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataManageDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      13,    1,   81,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void, QMetaType::QModelIndex,   12,

       0        // eod
};

void DataManageDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataManageDialog *_t = static_cast<DataManageDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_DeletepushButton_released(); break;
        case 1: _t->on_DeletepushButton_pressed(); break;
        case 2: _t->on_UpdatepushButton_released(); break;
        case 3: _t->on_UpdatepushButton_pressed(); break;
        case 4: _t->on_InsertpushButton_released(); break;
        case 5: _t->on_InsertpushButton_pressed(); break;
        case 6: _t->on_QuerypushButton_released(); break;
        case 7: _t->on_QuerypushButton_pressed(); break;
        case 8: _t->ShowTypetableView(); break;
        case 9: _t->on_TypetableView_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_TypetableView_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataManageDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DataManageDialog.data,
      qt_meta_data_DataManageDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataManageDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataManageDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataManageDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DataManageDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
