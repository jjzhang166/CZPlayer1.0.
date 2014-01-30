/****************************************************************************
** Meta object code from reading C++ file 'downloadthread.h'
**
** Created: Sun Jan 12 21:43:23 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../thread/downloadthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   63,   15,   15, 0x08,
     103,   15,   15,   15, 0x08,
     119,   15,   15,   15, 0x08,
     143,  141,   15,   15, 0x08,
     182,   15,   15,   15, 0x08,
     205,  201,   15,   15, 0x08,
     232,  201,   15,   15, 0x08,
     274,  261,   15,   15, 0x08,
     319,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DownloadThread[] = {
    "DownloadThread\0\0musicTitle\0"
    "sig_DelCurrentMusicMapItem(QString)\0"
    "replay\0slot_GetMusicXML(QNetworkReply*)\0"
    "slot_GetMusic()\0slot_ReplayFinished()\0"
    ",\0slot_UpdateDataProgress(qint64,qint64)\0"
    "slot_GetNetSpeed()\0row\0"
    "slot_DelCurrentThread(int)\0"
    "slot_PauseMusicDownload(int)\0networkError\0"
    "slot_ReplyError(QNetworkReply::NetworkError)\0"
    "slot_NetWorkInterrupt()\0"
};

void DownloadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DownloadThread *_t = static_cast<DownloadThread *>(_o);
        switch (_id) {
        case 0: _t->sig_DelCurrentMusicMapItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slot_GetMusicXML((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->slot_GetMusic(); break;
        case 3: _t->slot_ReplayFinished(); break;
        case 4: _t->slot_UpdateDataProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 5: _t->slot_GetNetSpeed(); break;
        case 6: _t->slot_DelCurrentThread((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slot_PauseMusicDownload((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slot_ReplyError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 9: _t->slot_NetWorkInterrupt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DownloadThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DownloadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DownloadThread,
      qt_meta_data_DownloadThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownloadThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownloadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownloadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadThread))
        return static_cast<void*>(const_cast< DownloadThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DownloadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DownloadThread::sig_DelCurrentMusicMapItem(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
