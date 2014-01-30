/****************************************************************************
** Meta object code from reading C++ file 'lrcthread.h'
**
** Created: Sun Jan 12 21:43:21 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../thread/lrcthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lrcthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LrcThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   28,   10,   10, 0x08,
      68,   28,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LrcThread[] = {
    "LrcThread\0\0sig_ResolveLrc()\0replay\0"
    "slot_GetMusicXML(QNetworkReply*)\0"
    "slot_GetLrc(QNetworkReply*)\0"
};

void LrcThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LrcThread *_t = static_cast<LrcThread *>(_o);
        switch (_id) {
        case 0: _t->sig_ResolveLrc(); break;
        case 1: _t->slot_GetMusicXML((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->slot_GetLrc((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LrcThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LrcThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_LrcThread,
      qt_meta_data_LrcThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LrcThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LrcThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LrcThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LrcThread))
        return static_cast<void*>(const_cast< LrcThread*>(this));
    return QThread::qt_metacast(_clname);
}

int LrcThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void LrcThread::sig_ResolveLrc()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
