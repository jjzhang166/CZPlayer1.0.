/****************************************************************************
** Meta object code from reading C++ file 'downloadlist.h'
**
** Created: Sun Jan 12 21:43:39 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../downloadWidget/downloadlist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadList[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x05,
      52,   41,   13,   13, 0x05,
      88,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     117,  111,   13,   13, 0x08,
     140,   13,   13,   13, 0x08,
     163,   13,   13,   13, 0x08,
     189,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DownloadList[] = {
    "DownloadList\0\0row\0sig_DelCurrentRow(int)\0"
    "musicTitle\0sig_DelCurrentMusicMapItem(QString)\0"
    "sig_PauseDownload(int)\0index\0"
    "slot_TableClicked(int)\0slot_DelCurrentMusic()\0"
    "slot_PauseMusicDownload()\0"
    "slot_StartMusicDownload()\0"
};

void DownloadList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DownloadList *_t = static_cast<DownloadList *>(_o);
        switch (_id) {
        case 0: _t->sig_DelCurrentRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_DelCurrentMusicMapItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sig_PauseDownload((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slot_TableClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slot_DelCurrentMusic(); break;
        case 5: _t->slot_PauseMusicDownload(); break;
        case 6: _t->slot_StartMusicDownload(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DownloadList::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DownloadList::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_DownloadList,
      qt_meta_data_DownloadList, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownloadList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownloadList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownloadList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadList))
        return static_cast<void*>(const_cast< DownloadList*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int DownloadList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DownloadList::sig_DelCurrentRow(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DownloadList::sig_DelCurrentMusicMapItem(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DownloadList::sig_PauseDownload(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
