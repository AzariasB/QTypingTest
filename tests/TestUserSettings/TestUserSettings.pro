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


TEMPLATE = app


SOURCES += tst_testusersettingstest.cpp \
    ../../src/Data/texercice.cpp \
    ../../src/Data/tlayout.cpp \
    ../../src/Data/tprogression.cpp \
    ../../src/Data/tresult.cpp \
    ../../src/Data/tstats.cpp \
    ../../src/Data/tuser.cpp \
    ../../src/Data/ttext.cpp \
    ../../src/Data/tusermanager.cpp \
    ../../src/Dialogs/toptiondialog.cpp \
    ../../src/Util/factory.cpp \
    ../../src/Util/htmlhelper.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../src/Data/texercice.h \
    ../../src/Data/tlayout.h \
    ../../src/Data/tprogression.h \
    ../../src/Data/tresult.h \
    ../../src/Data/tstats.h \
    ../../src/Data/tuser.h \
    ../../src/Data/tusermanager.h \
    ../../src/Data/ttext.h \
    ../../src/Dialogs/toptiondialog.h \
    ../../src/Util/factory.h \
    ../../src/Util/htmlhelper.h

FORMS += \
    ../../src/UI/options.ui

UI_DIR = ../../src/UI


RESOURCES += \
    ../../ressources.qrc

