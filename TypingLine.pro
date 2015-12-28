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
        src/QTypingTest/mainwindow.cpp \
        src/QTypingTest/TLine/tline.cpp \
        src/QTypingTest/TLine/tlabel.cpp \
        src/QTypingTest/TLine/tlineedit.cpp \
        src/QTypingTest/twindowtest.cpp \
        src/QTypingTest/thomepage.cpp \
        src/QTypingTest/Learn/learnpage.cpp \
        src/Util/exercicecreator.cpp \
        src/Util/htmlhelper.cpp \
        src/Data/tresult.cpp \
        src/Data/texercice.cpp \
        src/Data/tprogression.cpp \
        src/Data/tuser.cpp

HEADERS  += src/QTypingTest/mainwindow.h \
        src/Data/tpractice.h \
        src/QTypingTest/TLine/tline.h \
        src/QTypingTest/TLine/tlabel.h \
        src/QTypingTest/TLine/tlineedit.h \
        src/QTypingTest/twindowtest.h \
        src/QTypingTest/thomepage.h \
        src/QTypingTest/Learn/learnpage.h \
        src/Util/exercicecreator.h \
        src/Util/htmlhelper.h \
        src/Data/tresult.h \
        src/Data/texercice.h \
        src/Data/tprogression.h \
        src/Data/tuser.h
        

RC_ICONS += etc/icon.ico
ICON = TypingLine.icns

FORMS += \
    src/ui/homepage.ui

