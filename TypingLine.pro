#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T15:06:49
#
#-------------------------------------------------

QT              += core gui
CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


#Change config depending on the build configuration

CONFIG(debug, debug|release) {
    TARGET = TypingLineD
    DESTDIR = build/debug
    OBJECTS_DIR = build/debug/.obj
    MOC_DIR = build/debug/.mocesigner interface is also built in in QtCreator.
    RCC_DIR = build/debug/.rcc
    UI_DIR = build/debug/.ui
} else {
    TARGET = TypingLineR
    DESTDIR = build/release
    OBJECTS_DIR = build/release/.obj
    MOC_DIR = build/release/.moc
    RCC_DIR = build/release/.rcc
    UI_DIR = build/release/.ui
}


TEMPLATE = app

SOURCES += src/main.cpp\
        src/QTypingTest/mainwindow.cpp \
        src/QTypingTest/TLine/Tline.cpp \
        src/QTypingTest/TLine/TLabel.cpp \
        src/QTypingTest/TLine/TLineEdit.cpp \
        src/QTypingTest/TResult.cpp \
        src/QTypingTest/TWindowTest.cpp

HEADERS  += src/QTypingTest/mainwindow.h \
        src/QTypingTest/TLine/Tline.h \
        src/QTypingTest/TLine/TLabel.h \
        src/QTypingTest/TLine/TLineEdit.h \
        src/QTypingTest/TResult.h \
        src/QTypingTest/TWindowTest.h
        

