#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T15:06:49
#
#-------------------------------------------------

QT              += designer uitools core gui
CONFIG          += -std=c++11 debug
QMAKE_CXXFLAGS  += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


#Change config depending on the build configuration
CONFIG(debug, debug|release) {
    TARGET = TypingLineD
    DESTDIR = build/debug
    OBJECTS_DIR = build/debug/.obj
    MOC_DIR = build/debug/.moc
    RCC_DIR = build/debug/.rcc
} else {
    TARGET = TypingLineR
    DESTDIR = build/release
    OBJECTS_DIR = build/release/.obj
    MOC_DIR = build/release/.moc
    RCC_DIR = build/release/.rcc
}

UI_DIR = src/ui


TEMPLATE = app

SOURCES += src/main.cpp \
        src/Data/tpractice.cpp \
        src/QTypingTest/TLine/tpage.cpp \
        src/QTypingTest/TLine/tlabel.cpp \
        src/QTypingTest/Dialogs/twindowtest.cpp \
        src/QTypingTest/thomepage.cpp \
        src/QTypingTest/Learn/learnpage.cpp \
        src/Util/factory.cpp \
        src/Util/filehelper.cpp \
        src/Util/htmlhelper.cpp \
        src/Data/tresult.cpp \
        src/Data/texercice.cpp \
        src/Data/tprogression.cpp \
        src/Data/tuser.cpp \
        src/Data/tstats.cpp \
        src/Data/tkeys.cpp

HEADERS  += src/Data/tpractice.h \
        src/QTypingTest/TLine/tpage.h \
        src/QTypingTest/TLine/tlabel.h \
        src/QTypingTest/Dialogs/twindowtest.h \
        src/QTypingTest/thomepage.h \
        src/QTypingTest/Learn/learnpage.h \
        src/Util/factory.h \
        src/Util/filehelper.h \
        src/Util/htmlhelper.h \
        src/Data/tresult.h \
        src/Data/texercice.h \
        src/Data/tprogression.h \
        src/Data/tuser.h \
        src/Data/tstats.h \
        src/Data/tkeys.h
        

RC_ICONS += etc/icon.ico
ICON = TypingLine.icns

FORMS += \
    src/ui/homepage.ui

