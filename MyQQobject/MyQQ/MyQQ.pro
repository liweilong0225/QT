#-------------------------------------------------
#
# Project created by QtCreator 2021-04-03T21:36:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyQQ
TEMPLATE = app

include(./netapi/netapi.pri)

INCLUDEPATH += ./netapi/


SOURCES += main.cpp\
        myqqdialog.cpp \
    logindialog.cpp

HEADERS  += myqqdialog.h \
    logindialog.h

FORMS    += myqqdialog.ui \
    logindialog.ui

RESOURCES += \
    rec.qrc

DISTFILES +=
