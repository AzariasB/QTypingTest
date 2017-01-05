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


HEADERS = $$SRC/QTypingTest/Statistics/tstatswpm.h \
            $$SRC/Data/tprogression.h \
            $$SRC/Data/tresult.h \
            $$SRC/Data/texercice.h \
            $$SRC/Data/tuser.h \
            $$SRC/Data/tstats.h \
            $$SRC/Data/tlayouts.h \
            $$SRC/Data/ttext.h \
            $$SRC/Util/htmlhelper.h \
            $$SRC/Util/factory.h \
            $$SRC/QTypingTest/Statistics/tscrollwidget.h \
            $$SRC/QTypingTest/Statistics/tlayoutwidget.h

SOURCES = $$SRC/QTypingTest/Statistics/tstatswpm.cpp \
            $$SRC/Data/tprogression.cpp \
            $$SRC/Data/tresult.cpp \
            $$SRC/Data/texercice.cpp \
            $$SRC/Data/tuser.cpp \
            $$SRC/Data/tstats.cpp \
            $$SRC/Data/tlayouts.cpp \
            $$SRC/Data/ttext.cpp \
            $$SRC/Util/htmlhelper.cpp \
            $$SRC/Util/factory.cpp \           
            $$SRC/QTypingTest/Statistics/tscrollwidget.cpp \
            $$SRC/QTypingTest/Statistics/tlayoutwidget.cpp \
            tst_teststatstest.cpp

TARGET = tst_teststatstest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = build
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc



#DEFINES += SRCDIR=\\\"$$PWD/\\\"
