#-------------------------------------------------
#
# Project created by QtCreator 2013-06-21T19:40:14
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += phonon
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(qxtglobalshortcut/qxtglobalshortcut.pri)
TARGET = CZPlayer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    musiclist.cpp \
    musiclrc.cpp \
    nofocusdelegate.cpp \
    musicdownload.cpp \
    downloadlist.cpp \
    downloadthread.cpp \
    albumthread.cpp \
    minmusicwidget.cpp \
    musiclistwidget.cpp \
    czplayerconfig.cpp \
    configdialog.cpp \
    generalsettingspage.cpp \
    downloadsettingspage.cpp \
    hotkeyssettingspage.cpp \
    lrcsettingspage.cpp \
    proxysettingspage.cpp \
    hotkeystablewidget.cpp \
    lrcdemo.cpp \
    globalhotkey.cpp

HEADERS  += widget.h \
    musiclist.h \
    musiclrc.h \
    nofocusdelegate.h \
    musicdownload.h \
    downloadlist.h \
    downloadthread.h \
    albumthread.h \
    minmusicwidget.h \
    musiclistwidget.h \
    czplayerconfig.h \
    static.h \
    configdialog.h \
    generalsettingspage.h \
    downloadsettingspage.h \
    hotkeyssettingspage.h \
    lrcsettingspage.h \
    proxysettingspage.h \
    hotkeystablewidget.h \
    lrcdemo.h \
    defaultScheme.h \
    globalhotkey.h \
    head.h

FORMS    +=

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    CZPlayerIcon.rc
RC_FILE += CZPlayerIcon.rc
