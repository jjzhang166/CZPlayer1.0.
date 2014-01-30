/****************************************************************************
** Meta object code from reading C++ file 'hotkeyssettingspage.h'
**
** Created: Sun Jan 12 21:43:49 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../configPanel/hotkeyssettingspage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hotkeyssettingspage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HotKeysSettingsPage[] = {

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
      21,   20,   20,   20, 0x08,
      40,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HotKeysSettingsPage[] = {
    "HotKeysSettingsPage\0\0slot_BackSetting()\0"
    "slot_EditHotKeys()\0"
};

void HotKeysSettingsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HotKeysSettingsPage *_t = static_cast<HotKeysSettingsPage *>(_o);
        switch (_id) {
        case 0: _t->slot_BackSetting(); break;
        case 1: _t->slot_EditHotKeys(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData HotKeysSettingsPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HotKeysSettingsPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HotKeysSettingsPage,
      qt_meta_data_HotKeysSettingsPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HotKeysSettingsPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HotKeysSettingsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HotKeysSettingsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HotKeysSettingsPage))
        return static_cast<void*>(const_cast< HotKeysSettingsPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int HotKeysSettingsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
