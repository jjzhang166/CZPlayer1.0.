/****************************************************************************
** Meta object code from reading C++ file 'musiclist.h'
**
** Created: Tue Jan 14 12:08:09 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../musicList/musiclist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musiclist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MusicList[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      41,   31,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   10,   10,   10, 0x08,
      95,   10,   10,   10, 0x08,
     124,  118,   10,   10, 0x08,
     147,   10,   10,   10, 0x08,
     173,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MusicList[] = {
    "MusicList\0\0sig_PlayListClean()\0row,title\0"
    "sig_RowSelected(int,QString)\0"
    "slot_ClearAllMusicList()\0"
    "slot_DelCurrentMusic()\0index\0"
    "slot_TableClicked(int)\0slot_LocateCurrentMusic()\0"
    "slot_SaveList()\0"
};

void MusicList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MusicList *_t = static_cast<MusicList *>(_o);
        switch (_id) {
        case 0: _t->sig_PlayListClean(); break;
        case 1: _t->sig_RowSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->slot_ClearAllMusicList(); break;
        case 3: _t->slot_DelCurrentMusic(); break;
        case 4: _t->slot_TableClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slot_LocateCurrentMusic(); break;
        case 6: _t->slot_SaveList(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MusicList::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MusicList::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_MusicList,
      qt_meta_data_MusicList, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MusicList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MusicList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MusicList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MusicList))
        return static_cast<void*>(const_cast< MusicList*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int MusicList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MusicList::sig_PlayListClean()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MusicList::sig_RowSelected(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
