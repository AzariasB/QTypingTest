#-------------------------------------------------
#
# Project created by QtCreator 2016-01-25T12:43:50
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testusertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testusertest.cpp \
    renderarea.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    renderarea.h
