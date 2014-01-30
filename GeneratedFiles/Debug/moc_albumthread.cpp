/****************************************************************************
** Meta object code from reading C++ file 'albumthread.h'
**
** Created: Sun Jan 12 21:43:25 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../thread/albumthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'albumthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AlbumThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   13,   12,   12, 0x08,
      59,   13,   12,   12, 0x08,
      99,   12,   12,   12, 0x08,
     115,   12,   12,   12, 0x08,
     150,  137,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AlbumThread[] = {
    "AlbumThread\0\0replay\0"
    "slot_GetMusicAlbumJson(QNetworkReply*)\0"
    "slot_GetMusicAlbumJson2(QNetworkReply*)\0"
    "slot_GetAlbum()\0slot_ReplayFinished()\0"
    "networkError\0slot_ReplyError(QNetworkReply::NetworkError)\0"
};

void AlbumThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AlbumThread *_t = static_cast<AlbumThread *>(_o);
        switch (_id) {
        case 0: _t->slot_GetMusicAlbumJson((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->slot_GetMusicAlbumJson2((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->slot_GetAlbum(); break;
        case 3: _t->slot_ReplayFinished(); break;
        case 4: _t->slot_ReplyError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AlbumThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AlbumThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_AlbumThread,
      qt_meta_data_AlbumThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AlbumThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AlbumThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AlbumThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AlbumThread))
        return static_cast<void*>(const_cast< AlbumThread*>(this));
    return QThread::qt_metacast(_clname);
}

int AlbumThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
