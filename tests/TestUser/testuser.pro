#-------------------------------------------------
#
# Project created by QtCreator 2016-01-25T12:43:50
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERs = $$SRC/Data/tuser.h \    
$$SRC/Data/tresult.h \
$$SRC/Data/tprogression.h \
$$SRC/Data/tstats.h \
$$SRC/Util/factory.h \
$$SRC/Util/htmlhelper.h \
$$SRC/Util/filehelper.h \
$$SRC/Data/texercice.h

SOURCES = $$SRC/Data/tuser.cpp \
$$SRC/Data/tresult.cpp \
$$SRC/Data/tprogression.cpp \
$$SRC/Data/tstats.cpp \
$$SRC/Util/factory.cpp \
$$SRC/Util/htmlhelper.cpp \
$$SRC/Util/filehelper.cpp \
$$SRC/Data/texercice.cpp \
testuser.cpp
TARGET = tst_testusertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app



