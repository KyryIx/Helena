#-------------------------------------------------
#
# Project created by QtCreator 2019-09-16T16:06:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = Helena
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        windownew.cpp \
        windowpreference.cpp \
        windowwire.cpp \
        windowlamina.cpp \
        windowbobbin.cpp \
        windowabout.cpp \
        windowhelp.cpp \
    windowopen.cpp

HEADERS += \
        mainwindow.h \
        windownew.h \
        windowpreference.h \
        windowwire.h \
        windowbobbin.h \
        windowlamina.h \
        windowabout.h \
        windowhelp.h \
        database.h \
        wire.h \
        bobbin.h \
        lamina.h \
        wires.h \
        bobbins.h \
        laminas.h \
        transformer.h \
        samples.h \
    windowopen.h

FORMS += \
        mainwindow.ui \
        windownew.ui \
        windowpreference.ui \
        windowwire.ui \
        windowbobbin.ui \
        windowlamina.ui \
        windowabout.ui \
        windowhelp.ui \
    windowopen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons/main.qrc
