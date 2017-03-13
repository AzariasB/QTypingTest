#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T16:52:17
#
#-------------------------------------------------

QT       += widgets testlib xml

QT       -= gui

CONFIG          += -std=c++11 debug
QMAKE_CXXFLAGS  += -std=c++11

TARGET = tst_testusersettingstest

INCLUDEPATH = ../../src

CONFIG   += console
CONFIG   -= app_bundle
CONFIG(debug, debug|release) {
    TARGET = QTypingTest
    DESTDIR = build/Debug
    OBJECTS_DIR = build/Debug/.obj
    MOC_DIR = build/Debug/.moc
    RCC_DIR = build/Debug/.rcc
} else {
    TARGET = QTypingTest
    DESTDIR = build/release
    OBJECTS_DIR = build/release/.obj
    MOC_DIR = build/release/.moc
    RCC_DIR = build/release/.rcc
}

SRC = $$PWD/../../src/


TEMPLATE = app


SOURCES += tst_testusersettingstest.cpp \
        $$SRC/Data/texercice.cpp \
        $$SRC/Data/tlayout.cpp \
        $$SRC/Data/tprogression.cpp \
        $$SRC/Data/tresult.cpp \
        $$SRC/Data/tstats.cpp \
        $$SRC/Data/tuser.cpp \
        $$SRC/Data/ttext.cpp \
        $$SRC/Data/tusermanager.cpp \
        $$SRC/Dialogs/toptiondialog.cpp \
        $$SRC/Util/factory.cpp \
        $$SRC/tapplication.cpp \
        $$SRC/Util/htmlhelper.cpp

HEADERS += \
        $$SRC/Data/texercice.h \
        $$SRC/Data/tlayout.h \
        $$SRC/Data/tprogression.h \
        $$SRC/Data/tresult.h \
        $$SRC/Data/tstats.h \
        $$SRC/Data/tuser.h \
        $$SRC/Data/tusermanager.h \
        $$SRC/Data/ttext.h \
        $$SRC/Dialogs/toptiondialog.h \
        $$SRC/Util/factory.h \
        $$SRC/tapplication.h \
        $$SRC/Util/htmlhelper.h

FORMS += \
    $$SRC/UI/options.ui

UI_DIR = $$SRC/UI


RESOURCES += \
    ../../ressources.qrc

