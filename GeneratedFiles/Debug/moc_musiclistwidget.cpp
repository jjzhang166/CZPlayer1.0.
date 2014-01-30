/****************************************************************************
** Meta object code from reading C++ file 'musiclistwidget.h'
**
** Created: Tue Jan 14 12:08:07 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../musicList/musiclistwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musiclistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MusicListWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      32,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   16,   16,   16, 0x08,
      76,   16,   16,   16, 0x08,
      95,   16,   16,   16, 0x08,
     116,   16,   16,   16, 0x08,
     137,   16,   16,   16, 0x08,
     153,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MusicListWidget[] = {
    "MusicListWidget\0\0sig_AddMusic()\0"
    "sig_AddMusicList()\0slot_OnClickedAddMusic()\0"
    "slot_SearchMusic()\0slot_LineEditFocus()\0"
    "slot_BackMusicList()\0slot_AddMusic()\0"
    "slot_AddMusicList()\0"
};

void MusicListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MusicListWidget *_t = static_cast<MusicListWidget *>(_o);
        switch (_id) {
        case 0: _t->sig_AddMusic(); break;
        case 1: _t->sig_AddMusicList(); break;
        case 2: _t->slot_OnClickedAddMusic(); break;
        case 3: _t->slot_SearchMusic(); break;
        case 4: _t->slot_LineEditFocus(); break;
        case 5: _t->slot_BackMusicList(); break;
        case 6: _t->slot_AddMusic(); break;
        case 7: _t->slot_AddMusicList(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MusicListWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MusicListWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MusicListWidget,
      qt_meta_data_MusicListWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MusicListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MusicListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MusicListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MusicListWidget))
        return static_cast<void*>(const_cast< MusicListWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MusicListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MusicListWidget::sig_AddMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MusicListWidget::sig_AddMusicList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
