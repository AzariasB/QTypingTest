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
        src/Data/TPractice.cpp \
        src/QTypingTest/mainwindow.cpp \
        src/QTypingTest/TLine/Tline.cpp \
        src/QTypingTest/TLine/TLabel.cpp \
        src/QTypingTest/TLine/TLineEdit.cpp \
        src/QTypingTest/TWindowTest.cpp \
        src/QTypingTest/THomePage.cpp \
        src/QTypingTest/Learn/LearnPage.cpp \
        src/Data/TResult.cpp \
        src/Data/TExercice.cpp \
        src/Data/TUser.cpp

HEADERS  += src/QTypingTest/mainwindow.h \
        src/Data/TPractice.h \
        src/QTypingTest/TLine/Tline.h \
        src/QTypingTest/TLine/TLabel.h \
        src/QTypingTest/TLine/TLineEdit.h \
        src/QTypingTest/TWindowTest.h \
        src/QTypingTest/THomePage.h \
        src/QTypingTest/Learn/LearnPage.h \
        src/Data/TResult.h \
        src/Data/TExercice.h \
        src/Data/TUser.h
        

RC_ICONS += etc/icon.ico
ICON = TypingLine.icns

FORMS += \
    src/ui/homepage.ui

