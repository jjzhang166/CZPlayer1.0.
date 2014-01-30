/****************************************************************************
** Meta object code from reading C++ file 'minmusicwidget.h'
**
** Created: Sun Jan 12 21:43:31 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../minWidget/minmusicwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'minmusicwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MinMusicWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      30,   15,   15,   15, 0x05,
      45,   15,   15,   15, 0x05,
      59,   15,   15,   15, 0x05,
      73,   15,   15,   15, 0x05,
      87,   15,   15,   15, 0x05,
     115,   15,   15,   15, 0x05,
     130,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     151,   15,   15,   15, 0x08,
     166,   15,   15,   15, 0x08,
     183,   15,   15,   15, 0x08,
     198,   15,   15,   15, 0x08,
     212,   15,   15,   15, 0x08,
     227,   15,   15,   15, 0x08,
     243,   15,   15,   15, 0x08,
     265,   15,   15,   15, 0x08,
     285,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MinMusicWidget[] = {
    "MinMusicWidget\0\0sig_MinPlay()\0"
    "sig_MinPause()\0sig_MinStop()\0sig_MinNext()\0"
    "sig_MinLast()\0sig_OpenFileButtonClicked()\0"
    "sig_MusicLrc()\0sig_ShowMusicPanel()\0"
    "slot_SetPlay()\0slot_SetPaused()\0"
    "slot_SetStop()\0slot_SetPre()\0"
    "slot_SetNext()\0slot_OpenFile()\0"
    "slot_OpenMainWidget()\0slot_OpenMusicLrc()\0"
    "slot_HideMinWidget()\0"
};

void MinMusicWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MinMusicWidget *_t = static_cast<MinMusicWidget *>(_o);
        switch (_id) {
        case 0: _t->sig_MinPlay(); break;
        case 1: _t->sig_MinPause(); break;
        case 2: _t->sig_MinStop(); break;
        case 3: _t->sig_MinNext(); break;
        case 4: _t->sig_MinLast(); break;
        case 5: _t->sig_OpenFileButtonClicked(); break;
        case 6: _t->sig_MusicLrc(); break;
        case 7: _t->sig_ShowMusicPanel(); break;
        case 8: _t->slot_SetPlay(); break;
        case 9: _t->slot_SetPaused(); break;
        case 10: _t->slot_SetStop(); break;
        case 11: _t->slot_SetPre(); break;
        case 12: _t->slot_SetNext(); break;
        case 13: _t->slot_OpenFile(); break;
        case 14: _t->slot_OpenMainWidget(); break;
        case 15: _t->slot_OpenMusicLrc(); break;
        case 16: _t->slot_HideMinWidget(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MinMusicWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MinMusicWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MinMusicWidget,
      qt_meta_data_MinMusicWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MinMusicWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MinMusicWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MinMusicWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MinMusicWidget))
        return static_cast<void*>(const_cast< MinMusicWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MinMusicWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MinMusicWidget::sig_MinPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MinMusicWidget::sig_MinPause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MinMusicWidget::sig_MinStop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MinMusicWidget::sig_MinNext()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MinMusicWidget::sig_MinLast()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MinMusicWidget::sig_OpenFileButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MinMusicWidget::sig_MusicLrc()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MinMusicWidget::sig_ShowMusicPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
