#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T15:06:49
#
#-------------------------------------------------

QT              += designer uitools core gui
CONFIG          += -std=c++11 debug
QMAKE_CXXFLAGS  += -std=c++11

PRO_PATH=$$PWD

INCLUDEPATH = $$PRO_PATH/src


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


#Change config depending on the build configuration
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

UI_DIR = src/ui


TEMPLATE = app

#Icons for windows
RC_ICONS += etc/icon.ico
ICON = TypingLine.icns

FORMS += \
    src/ui/homepage.ui


SOURCES += src/main.cpp \
        #------------
        #Core classes= src/main.cpp \
        #------------
        src/QTypingTest/Dialogs/Exercices/tpage.cpp \
        src/QTypingTest/Dialogs/Exercices/tlabel.cpp \
        src/QTypingTest/Dialogs/Exercices/tstackpages.cpp \
        src/QTypingTest/Dialogs/Exercices/ttoolbar.cpp \
        src/QTypingTest/Dialogs/Exercices/twindowlearn.cpp \
        src/QTypingTest/Dialogs/Exercices/tpracticerace.cpp \
        src/QTypingTest/Dialogs/Exercices/tpracticebase.cpp \
        src/QTypingTest/Dialogs/Exercices/tpracticetext.cpp \
        src/QTypingTest/Dialogs/twindowtest.cpp \
        src/QTypingTest/thomepage.cpp \
        src/QTypingTest/Learn/learnpage.cpp \
        src/QTypingTest/Learn/tfingerposition.cpp \
        src/QTypingTest/Learn/tpresentation.cpp \
        src/QTypingTest/Learn/tvirtualkey.cpp \
        src/QTypingTest/Learn/tvirtualkeyboard.cpp \
        src/QTypingTest/Practice/practicepage.cpp \
        src/QTypingTest/Games/gamepage.cpp \
        #------------       
        #Util class/functions
        #------------      
        src/Util/factory.cpp \
        src/Util/filehelper.cpp \
        src/Util/htmlhelper.cpp \
        src/Data/tresult.cpp \
        #------------
        #Data classes
        #------------
        src/Data/texercice.cpp \
        src/Data/tlayouts.cpp \
        src/Data/tprogression.cpp \
        src/Data/tuser.cpp \
        src/Data/tstats.cpp 

#------------
#Core classes
#------------
HEADERS +=  \
            src/QTypingTest/Dialogs/Exercices/tpage.h \
            src/QTypingTest/Dialogs/Exercices/tlabel.h \
            src/QTypingTest/Dialogs/Exercices/tstackpages.h \
            src/QTypingTest/Dialogs/Exercices/ttoolbar.h \
            src/QTypingTest/Dialogs/Exercices/twindowlearn.h \
            src/QTypingTest/Dialogs/Exercices/tpracticerace.h \
            src/QTypingTest/Dialogs/Exercices/tpracticebase.h \
            src/QTypingTest/Dialogs/Exercices/tpracticetext.h \
            src/QTypingTest/Dialogs/twindowtest.h \
            src/QTypingTest/thomepage.h \
            src/QTypingTest/Learn/learnpage.h \
            src/QTypingTest/Learn/tfingerposition.h \
            src/QTypingTest/Learn/tpresentation.h \
            src/QTypingTest/Learn/tvirtualkey.h \
            src/QTypingTest/Learn/tvirtualkeyboard.h \
            src/QTypingTest/Practice/practicepage.h \
            src/QTypingTest/Games/gamepage.h \
            #------------
            #Util functions/classes
            #------------
            src/Util/factory.h \
            src/Util/filehelper.h \
            src/Util/htmlhelper.h \
            #------------
            #Data classes
            #------------
            src/Data/tresult.h \
            src/Data/texercice.h \
            src/Data/tprogression.h \
            src/Data/tlayouts.h \
            src/Data/tuser.h \
            src/Data/tstats.h 