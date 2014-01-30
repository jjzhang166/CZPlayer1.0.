/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Sun Jan 12 21:43:33 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../mainWiget/widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   29,    7,    7, 0x08,
      58,    7,    7,    7, 0x08,
      79,    7,    7,    7, 0x08,
      95,    7,    7,    7, 0x08,
     115,    7,    7,    7, 0x08,
     136,    7,    7,    7, 0x08,
     156,    7,    7,    7, 0x08,
     181,    7,    7,    7, 0x08,
     206,    7,    7,    7, 0x08,
     227,    7,    7,    7, 0x08,
     249,    7,    7,    7, 0x08,
     271,    7,    7,    7, 0x08,
     293,    7,    7,    7, 0x08,
     314,    7,    7,    7, 0x08,
     329,    7,    7,    7, 0x08,
     346,    7,    7,    7, 0x08,
     361,    7,    7,    7, 0x08,
     375,    7,    7,    7, 0x08,
     400,  390,    7,    7, 0x08,
     454,  447,    7,    7, 0x08,
     496,  491,    7,    7, 0x08,
     529,    7,    7,    7, 0x08,
     559,  549,    7,    7, 0x08,
     593,    7,    7,    7, 0x08,
     617,  390,    7,    7, 0x08,
     685,  668,    7,    7, 0x08,
     743,    7,    7,    7, 0x08,
     762,    7,    7,    7, 0x08,
     779,    7,    7,    7, 0x08,
     800,    7,    7,    7, 0x08,
     823,    7,    7,    7, 0x08,
     840,    7,    7,    7, 0x08,
     864,    7,    7,    7, 0x08,
     879,    7,    7,    7, 0x08,
     897,    7,    7,    7, 0x08,
     923,    7,    7,    7, 0x08,
     944,    7,    7,    7, 0x08,
     970,    7,    7,    7, 0x08,
     991,    7,    7,    7, 0x08,
    1012,    7,    7,    7, 0x08,
    1032,    7,    7,    7, 0x08,
    1053,    7,    7,    7, 0x08,
    1068,    7,    7,    7, 0x08,
    1085,    7,    7,    7, 0x08,
    1097,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0sig_ShowMainWidget()\0time\0"
    "slot_UpdateTime(qint64)\0slot_OpenMinWidget()\0"
    "slot_OpenFile()\0slot_AddMusicList()\0"
    "slot_OpenMusicList()\0slot_OpenMusicLrc()\0"
    "slot_OpenMusicDownload()\0"
    "slot_HideMusicDownload()\0slot_HideMusicList()\0"
    "slot_HideMainWidget()\0slot_ShowMusicPanel()\0"
    "slot_ConfigCZPlayer()\0slot_AboutCZPlayer()\0"
    "slot_AboutQt()\0slot_SetPaused()\0"
    "slot_SetStop()\0slot_SetPre()\0"
    "slot_SetNext()\0newState,\0"
    "slot_StateChanged(Phonon::State,Phonon::State)\0"
    "source\0slot_RowChanged(Phonon::MediaSource)\0"
    "row,\0slot_TableDoubleClicked(int,int)\0"
    "slot_ClearSources()\0row,title\0"
    "slot_DelSelectSource(int,QString)\0"
    "slot_AboutMusicFinish()\0"
    "slot_MetaStateChanged(Phonon::State,Phonon::State)\0"
    "activationReason\0"
    "slot_TrayIconActivated(QSystemTrayIcon::ActivationReason)\0"
    "slot_ShowMinSize()\0slot_MinToTray()\0"
    "slot_ShowLrcLocked()\0slot_ShowLrcUnlocked()\0"
    "slot_UnlockLrc()\0slot_CloseAllProgress()\0"
    "slot_TimeOut()\0slot_ResolveLrc()\0"
    "slot_ShortCutsetDisable()\0"
    "slot_ConfigOptions()\0slot_ShowHideMainWidget()\0"
    "slot_MinMainWidget()\0slot_OpenMusicfile()\0"
    "slot_ShowDownload()\0slot_ShowMusicList()\0"
    "slot_ShowLrc()\0slot_PlayPause()\0"
    "slot_Last()\0slot_Next()\0"
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->sig_ShowMainWidget(); break;
        case 1: _t->slot_UpdateTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->slot_OpenMinWidget(); break;
        case 3: _t->slot_OpenFile(); break;
        case 4: _t->slot_AddMusicList(); break;
        case 5: _t->slot_OpenMusicList(); break;
        case 6: _t->slot_OpenMusicLrc(); break;
        case 7: _t->slot_OpenMusicDownload(); break;
        case 8: _t->slot_HideMusicDownload(); break;
        case 9: _t->slot_HideMusicList(); break;
        case 10: _t->slot_HideMainWidget(); break;
        case 11: _t->slot_ShowMusicPanel(); break;
        case 12: _t->slot_ConfigCZPlayer(); break;
        case 13: _t->slot_AboutCZPlayer(); break;
        case 14: _t->slot_AboutQt(); break;
        case 15: _t->slot_SetPaused(); break;
        case 16: _t->slot_SetStop(); break;
        case 17: _t->slot_SetPre(); break;
        case 18: _t->slot_SetNext(); break;
        case 19: _t->slot_StateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 20: _t->slot_RowChanged((*reinterpret_cast< const Phonon::MediaSource(*)>(_a[1]))); break;
        case 21: _t->slot_TableDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 22: _t->slot_ClearSources(); break;
        case 23: _t->slot_DelSelectSource((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 24: _t->slot_AboutMusicFinish(); break;
        case 25: _t->slot_MetaStateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 26: _t->slot_TrayIconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 27: _t->slot_ShowMinSize(); break;
        case 28: _t->slot_MinToTray(); break;
        case 29: _t->slot_ShowLrcLocked(); break;
        case 30: _t->slot_ShowLrcUnlocked(); break;
        case 31: _t->slot_UnlockLrc(); break;
        case 32: _t->slot_CloseAllProgress(); break;
        case 33: _t->slot_TimeOut(); break;
        case 34: _t->slot_ResolveLrc(); break;
        case 35: _t->slot_ShortCutsetDisable(); break;
        case 36: _t->slot_ConfigOptions(); break;
        case 37: _t->slot_ShowHideMainWidget(); break;
        case 38: _t->slot_MinMainWidget(); break;
        case 39: _t->slot_OpenMusicfile(); break;
        case 40: _t->slot_ShowDownload(); break;
        case 41: _t->slot_ShowMusicList(); break;
        case 42: _t->slot_ShowLrc(); break;
        case 43: _t->slot_PlayPause(); break;
        case 44: _t->slot_Last(); break;
        case 45: _t->slot_Next(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
    return _id;
}

// SIGNAL 0
void Widget::sig_ShowMainWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
