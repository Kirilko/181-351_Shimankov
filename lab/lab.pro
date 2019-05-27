#-------------------------------------------------
#
# Project created by QtCreator 2019-05-07T14:38:19
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += core
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab
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
        TinyAES.cpp \
        adminwindow.cpp \
        crypto.cpp \
        database.cpp \
        dialogdelete.cpp \
        loginwindow.cpp \
        main.cpp \
        regwindow.cpp \
        startwindow.cpp \
        umwindow.cpp

HEADERS += \
        TinyAES.h \
        adminwindow.h \
        crypto.h \
        database.h \
        dialogdelete.h \
        loginwindow.h \
        regwindow.h \
        sslserver.h \
        startwindow.h \
        umwindow.h

FORMS += \
        adminwindow.ui \
        dialogdelete.ui \
        loginwindow.ui \
        regwindow.ui \
        startwindow.ui \
        umwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -LC:/Users/Dell/Desktop/ssl/ -llibcrypto
       LIBS += -LC:/Users/Dell/Desktop/ssl/ -llibssl

INCLUDEPATH += C:/Users/Dell/Desktop/ssl/include
DEPENDPATH += C:/Users/Dell/Desktop/ssl/include
