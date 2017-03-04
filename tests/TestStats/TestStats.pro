#-------------------------------------------------
#
# Project created by QtCreator 2016-01-29T14:33:16
#
#-------------------------------------------------

QT       += widgets testlib xml core
QT       -= gui

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

PRO_PATH=$$PWD

INCLUDEPATH += $$PRO_PATH/../../src
message($$INCLUDEPATH)

SRC = $$PWD/../../src/


HEADERS = $$SRC/Data/tprogression.h \
            $$SRC/Data/tresult.h \
            $$SRC/Data/texercice.h \
            $$SRC/Data/tuser.h \
            $$SRC/Data/tusermanager.h \
            $$SRC/Data/tstats.h \
            $$SRC/Data/tlayout.h \
            $$SRC/Data/ttext.h \
            $$SRC/Util/htmlhelper.h \
            $$SRC/Util/factory.h \
            $$SRC/Pages/tstatistics.h

SOURCES = $$SRC/Data/tprogression.cpp \
            $$SRC/Data/tresult.cpp \
            $$SRC/Data/texercice.cpp \
            $$SRC/Data/tuser.cpp \
            $$SRC/Data/tusermanager.cpp \
            $$SRC/Data/tstats.cpp \
            $$SRC/Data/tlayout.cpp \
            $$SRC/Data/ttext.cpp \
            $$SRC/Util/htmlhelper.cpp \
            $$SRC/Util/factory.cpp \           
            $$SRC/Pages/tstatistics.cpp \
            tst_teststatstest.cpp

TARGET = tst_teststatstest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = build
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc


RESOURCES += \
    ../../ressources.qrc

#DEFINES += SRCDIR=\\\"$$PWD/\\\"
