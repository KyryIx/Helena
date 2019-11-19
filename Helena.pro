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
        windows/mainwindow.cpp \
        windows/windowpreference.cpp \
        windows/windowwire.cpp \
        windows/windowlamina.cpp \
        windows/windowbobbin.cpp \
        windows/windowabout.cpp \
        windows/windowhelp.cpp \
        windows/windownewproject.cpp \
        windows/windowopenproject.cpp

HEADERS += \
        components/bobbin.h \
        components/bobbins.h \
        components/database.h \
        components/lamina.h \
        components/laminas.h \
        components/wire.h \
        components/wires.h \
        components/transformer.h \
        windows/mainwindow.h \
        windows/windowpreference.h \
        windows/windowwire.h \
        windows/windowbobbin.h \
        windows/windowlamina.h \
        windows/windowabout.h \
        windows/windowhelp.h \
        windows/windowopenproject.h \
        windows/windownewproject.h \
        samples.h

FORMS += \
        windows/mainwindow.ui \
        windows/windowpreference.ui \
        windows/windowwire.ui \
        windows/windowbobbin.ui \
        windows/windowlamina.ui \
        windows/windowabout.ui \
        windows/windowhelp.ui \
        windows/windowopenproject.ui \
        windows/windownewproject.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons/main.qrc
