#-------------------------------------------------
#
# Project created by QtCreator 2018-08-05T11:28:10
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColdMusic
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    titlebar.cpp \
    bottombarui.cpp \
    leftsidebarui.cpp \
    contentwidget.cpp \
    music_play/musicplayer.cpp \
    playslider.cpp

HEADERS += \
        mainwindow.h \
    titlebar.h \
    bottombarui.h \
    leftsidebarui.h \
    contentwidget.h \ 
    music_play/musicplayer.h \
    playslider.h

INCLUDEPATH += ffmpeg\include \

#LIBS += $$PWD/ffmpeg/lib/avcodec.lib
LIBS += $$PWD/ffmpeg/lib/avformat.lib
LIBS += $$PWD/ffmpeg/lib/avutil.lib

RESOURCES += \
    res.qrc

FORMS += \
    bottombarui.ui \
    leftsidebarui.ui \
    contentwidget.ui
