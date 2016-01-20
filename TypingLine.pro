#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T15:06:49
#
#-------------------------------------------------

QT              += designer uitools core gui
CONFIG          += -std=c++11 debug
QMAKE_CXXFLAGS  += -std=c++11

PRO_PATH=$$PWD

INCLUDEPATH = /home/boutina/Documents/Scolaire/Programmation/C++/Qt/QTypingTest/src


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
  
RC_ICONS += etc/icon.ico
ICON = TypingLine.icns

FORMS += \
    src/ui/homepage.ui


SOURCES += src/main.cpp \
        #------------
        #Core classes= src/main.cpp \
        #------------
        src/QTypingTest/Dialogs/Exercices/TLine/tpage.cpp \
        src/QTypingTest/Dialogs/Exercices/TLine/tlabel.cpp \
        src/QTypingTest/Dialogs/Exercices/stackpages.cpp \
        src/QTypingTest/Dialogs/Exercices/toolbar.cpp \
        src/QTypingTest/Dialogs/Exercices/twindowlearn.cpp \
        src/QTypingTest/Dialogs/twindowtest.cpp \
        src/QTypingTest/thomepage.cpp \
        src/QTypingTest/Learn/learnpage.cpp \
        src/QTypingTest/Practice/practicepage.cpp \
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
        src/Data/tpractice.cpp \
        src/Data/tprogression.cpp \
        src/Data/tuser.cpp \
        src/Data/tstats.cpp \
        src/Data/tkeys.cpp


#------------
#Core classes
#------------
HEADERS += src/QTypingTest/Dialogs/Exercices/TLine/tpage.h \
            src/QTypingTest/Dialogs/Exercices/TLine/tlabel.h \
            src/QTypingTest/Dialogs/Exercices/twindowlearn.h \
            src/QTypingTest/Dialogs/Exercices/stackpages.h \
            src/QTypingTest/Dialogs/Exercices/toolbar.h \
            src/QTypingTest/Dialogs/twindowtest.h \
            src/QTypingTest/thomepage.h \
            src/QTypingTest/Learn/learnpage.h \
            src/QTypingTest/Practice/practicepage.h \
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
            src/Data/tpractice.h \
            src/Data/tuser.h \
            src/Data/tstats.h \
            src/Data/tkeys.h