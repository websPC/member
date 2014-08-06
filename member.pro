#-------------------------------------------------
#
# Project created by QtCreator 2014-07-02T15:38:45
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = member
TEMPLATE = app


SOURCES += main.cpp\
    form.cpp \
    edit.cpp \
    mainwindow.cpp \
    eventedit.cpp \
    eventplus.cpp \
    login.cpp

HEADERS  += \
    form.h \
    edit.h \
    mainwindow.h \
    eventedit.h \
    eventplus.h \
    main.h \
    login.h

FORMS    += \
    form.ui \
    edit.ui \
    mainwindow.ui \
    eventedit.ui \
    eventplus.ui \
    login.ui \
    login.ui

RESOURCES += \
    QTimg.qrc \
    QTIMG.qrc
