#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T15:06:49
#
#-------------------------------------------------

QT              += designer uitools core gui xml
CONFIG          += -std=c++11 debug
QMAKE_CXXFLAGS  += -std=c++11

PRO_PATH=$$PWD

INCLUDEPATH = $$PRO_PATH/src


greaterThan(QT_MAJOR_VERSION, 5): QT += widgets


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

FORMS += src/ui/homepage.ui \
         src/ui/options.ui


SOURCES +=\
    src/main.cpp \
    #-------------------------
    # QTypingTest
    #------------------------- \
    src/QTypingTest/thomepage.cpp \
    src/QTypingTest/toptiondialog.cpp \
    #-------------------------
    # Learn
    #------------------------- \
    src/QTypingTest/Learn/tvirtualkey.cpp \
    src/QTypingTest/Learn/learnpage.cpp \
    src/QTypingTest/Learn/tpresentation.cpp \
    src/QTypingTest/Learn/tvirtualkeyboard.cpp \
    src/QTypingTest/Learn/tfingerposition.cpp \
    #-------------------------
    # Home
    #------------------------- \
    src/QTypingTest/Home/homepage.cpp \
    #-------------------------
    # Dialogs
    #------------------------- \
    src/QTypingTest/Dialogs/twindowtest.cpp \
    #-------------------------
    # Exercices
    #------------------------- \
    src/QTypingTest/Dialogs/Exercices/tpracticerace.cpp \
    src/QTypingTest/Dialogs/Exercices/tpage.cpp \
    src/QTypingTest/Dialogs/Exercices/tlabel.cpp \
    src/QTypingTest/Dialogs/Exercices/ttoolbar.cpp \
    src/QTypingTest/Dialogs/Exercices/tstackpages.cpp \
    src/QTypingTest/Dialogs/Exercices/timprove.cpp \
    src/QTypingTest/Dialogs/Exercices/tpracticetext.cpp \
    src/QTypingTest/Dialogs/Exercices/tpracticebase.cpp \
    src/QTypingTest/Dialogs/Exercices/twindowlearn.cpp \
    #-------------------------
    # Practice
    #------------------------- \
    src/QTypingTest/Practice/practicepage.cpp \
    #-------------------------
    # Games
    #------------------------- \
    src/QTypingTest/Games/gamepage.cpp \
    #-------------------------
    # Util
    #------------------------- \
    src/Util/htmlhelper.cpp \
    src/Util/factory.cpp \
    #-------------------------
    # ui
    #------------------------- \
    #-------------------------
    # Data
    #------------------------- \
    src/Data/texercice.cpp \
    src/Data/tprogression.cpp \
    src/Data/tlayouts.cpp \
    src/Data/tpractical.cpp \
    src/Data/tstats.cpp \
    src/Data/tusermanager.cpp \
    src/Data/tuser.cpp \
    src/Data/ttext.cpp \
    src/Data/tresult.cpp

HEADERS +=\
    #-------------------------
    # QTypingTest
    #------------------------- \
    src/QTypingTest/toptiondialog.h \
    src/QTypingTest/thomepage.h \
    #-------------------------
    # Learn
    #------------------------- \
    src/QTypingTest/Learn/tvirtualkeyboard.h \
    src/QTypingTest/Learn/tpresentation.h \
    src/QTypingTest/Learn/tvirtualkey.h \
    src/QTypingTest/Learn/learnpage.h \
    src/QTypingTest/Learn/tfingerposition.h \
    #-------------------------
    # Home
    #------------------------- \
    src/QTypingTest/Home/homepage.h \
    #-------------------------
    # Dialogs
    #------------------------- \
    src/QTypingTest/Dialogs/twindowtest.h \
    #-------------------------
    # Exercices
    #------------------------- \
    src/QTypingTest/Dialogs/Exercices/tpracticerace.h \
    src/QTypingTest/Dialogs/Exercices/tpracticebase.h \
    src/QTypingTest/Dialogs/Exercices/ttoolbar.h \
    src/QTypingTest/Dialogs/Exercices/twindowlearn.h \
    src/QTypingTest/Dialogs/Exercices/tlabel.h \
    src/QTypingTest/Dialogs/Exercices/tpracticetext.h \
    src/QTypingTest/Dialogs/Exercices/tpage.h \
    src/QTypingTest/Dialogs/Exercices/timprove.h \
    src/QTypingTest/Dialogs/Exercices/tstackpages.h \
    #-------------------------
    # Practice
    #------------------------- \
    src/QTypingTest/Practice/practicepage.h \
    #-------------------------
    # Games
    #------------------------- \
    src/QTypingTest/Games/gamepage.h \
    #-------------------------
    # Util
    #------------------------- \
    src/Util/htmlhelper.h \
    src/Util/factory.h \
    #-------------------------
    # ui
    #------------------------- \
    src/ui/ui_homepage.h \
    src/ui/ui_options.h \
    #-------------------------
    # Data
    #------------------------- \
    src/Data/tresult.h \
    src/Data/tusermanager.h \
    src/Data/tpractical.h \
    src/Data/texercice.h \
    src/Data/tlayouts.h \
    src/Data/tprogression.h \
    src/Data/tuser.h \
    src/Data/ttext.h \
    src/Data/tstats.h

DISTFILES += \
    ressources/layouts.txt \
    ressources/syle.qss

RESOURCES += \
    ressources.qrc
