/****************************************************************************
** Meta object code from reading C++ file 'musicdownload.h'
**
** Created: Sun Jan 12 21:43:37 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../downloadWidget/musicdownload.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicdownload.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MusicDownload[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      47,   36,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MusicDownload[] = {
    "MusicDownload\0\0slot_DownloadMusic()\0"
    "musicTitle\0slot_DelCurrentMapItem(QString)\0"
};

void MusicDownload::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MusicDownload *_t = static_cast<MusicDownload *>(_o);
        switch (_id) {
        case 0: _t->slot_DownloadMusic(); break;
        case 1: _t->slot_DelCurrentMapItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MusicDownload::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MusicDownload::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MusicDownload,
      qt_meta_data_MusicDownload, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MusicDownload::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MusicDownload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MusicDownload::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MusicDownload))
        return static_cast<void*>(const_cast< MusicDownload*>(this));
    return QWidget::qt_metacast(_clname);
}

int MusicDownload::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
