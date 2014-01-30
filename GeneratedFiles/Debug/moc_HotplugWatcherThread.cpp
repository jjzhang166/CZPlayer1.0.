/****************************************************************************
** Meta object code from reading C++ file 'HotplugWatcherThread.h'
**
** Created: Sun Jan 12 21:43:06 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../thread/HotplugWatcherThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HotplugWatcherThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HotplugWatcherThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   22,   21,   21, 0x0a,
      52,   22,   21,   21, 0x0a,
      80,   22,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HotplugWatcherThread[] = {
    "HotplugWatcherThread\0\0dev\0"
    "slot_DeviceAdded(QString)\0"
    "slot_DeviceRemoved(QString)\0"
    "slot_DeviceChanged(QString)\0"
};

void HotplugWatcherThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HotplugWatcherThread *_t = static_cast<HotplugWatcherThread *>(_o);
        switch (_id) {
        case 0: _t->slot_DeviceAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->slot_DeviceRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->slot_DeviceChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HotplugWatcherThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HotplugWatcherThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_HotplugWatcherThread,
      qt_meta_data_HotplugWatcherThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HotplugWatcherThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HotplugWatcherThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HotplugWatcherThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HotplugWatcherThread))
        return static_cast<void*>(const_cast< HotplugWatcherThread*>(this));
    return QThread::qt_metacast(_clname);
}

int HotplugWatcherThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
