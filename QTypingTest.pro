#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T15:06:49
#
#-------------------------------------------------

QT              += designer uitools core gui xml multimedia websockets
CONFIG          += -std=c++11 debug
QMAKE_CXXFLAGS  += -std=c++11

PRO_PATH=$$PWD

INCLUDEPATH = $$PRO_PATH/src


greaterThan(QT_MAJOR_VERSION, 5): QT += widgets


#Change config depending on the build configuration
CONFIG(debug, debug|release) {
        TARGET = QTypingTest
        DESTDIR = Debug
        OBJECTS_DIR = Debug/.obj
        MOC_DIR = Debug/.moc
        RCC_DIR = Debug/.rcc
} else {
        TARGET = QTypingTest
        DESTDIR = Release
        OBJECTS_DIR = Release/.obj
        MOC_DIR = Release/.moc
        RCC_DIR = Release/.rcc
}

UI_DIR = src/ui


TEMPLATE = app

#Icons for windows
RC_ICONS += resources/icon.ico
ICON = resources/icon.ico

FORMS += src/UI/homepage.ui \
         src/UI/options.ui


SOURCES +=\
    src/main.cpp \
    #-------------------------
    # Pages
    #------------------------- \
    src/Pages/gamepage.cpp \
    src/Pages/homepage.cpp \
    src/Pages/learnpage.cpp \
    src/Pages/practicepage.cpp \
    src/Pages/thomepage.cpp \
    src/Pages/tstatistics.cpp \
    #-------------------------
    # Dialogs
    #------------------------- \
    src/Dialogs/timprove.cpp \
    src/Dialogs/toptiondialog.cpp \
    src/Dialogs/tpracticebase.cpp \
    src/Dialogs/tpracticerace.cpp \
    src/Dialogs/tpracticetext.cpp \
    src/Dialogs/twindowlearn.cpp \
    src/Dialogs/twindowtest.cpp \
    #-------------------------
    # Widgets
    #------------------------- \
    src/Widgets/tfingerposition.cpp \
    src/Widgets/tlabel.cpp \
    src/Widgets/tpage.cpp \
    src/Widgets/tpresentation.cpp \
    src/Widgets/tstackpages.cpp \
    src/Widgets/ttoolbar.cpp \
    src/Widgets/tvirtualkey.cpp \
    src/Widgets/tvirtualkeyboard.cpp \
    #-------------------------
    # Util
    #------------------------- \
    src/Util/htmlhelper.cpp \
    src/Util/factory.cpp \
    #-------------------------
    # UI
    #------------------------- \
    #-------------------------
    # Data
    #------------------------- \
    src/Data/tprogression.cpp \
    src/Data/tpractical.cpp \
    src/Data/tstats.cpp \
    src/Data/tusermanager.cpp \
    src/Data/tuser.cpp \
    src/Data/ttext.cpp \
    src/Data/tresult.cpp \
    src/Data/tlayout.cpp \
    src/tapplication.cpp \
    src/Data/texercise.cpp \
    #-------------------------
    #   Games
    #------------------------- \
    src/Games/bullet.cpp \
    src/Games/letterwall.cpp \
    src/Games/recttext.cpp \
    src/Games/vector2f.cpp \
    src/Games/animatedsprite.cpp \
    src/Games/resourcemanager.cpp \
    src/Games/bouncegame.cpp \
    src/Games/bouncemenu.cpp \
    src/Games/bouncedata.cpp \
    src/Games/bouncemain.cpp \
    src/Games/bouncehelp.cpp \
    src/Games/countdown.cpp \
    src/Games/menubutton.cpp \
    src/Games/bouncescore.cpp \
    src/Games/Competition/competitionmain.cpp \
    src/Games/Competition/userlist.cpp

HEADERS +=\
    #-------------------------
    # Pages
    #------------------------- \
    src/Pages/gamepage.h \
    src/Pages/homepage.h \
    src/Pages/learnpage.h \
    src/Pages/practicepage.h \
    src/Pages/thomepage.h \
    src/Pages/tstatistics.h \
    #-------------------------
    # Dialogs
    #------------------------- \
    src/Dialogs/timprove.h \
    src/Dialogs/toptiondialog.h \
    src/Dialogs/tpracticebase.h \
    src/Dialogs/tpracticerace.h \
    src/Dialogs/tpracticetext.h \
    src/Dialogs/twindowlearn.h \
    src/Dialogs/twindowtest.h \
    #-------------------------
    # Widgets
    #------------------------- \
    src/Widgets/tfingerposition.h \
    src/Widgets/tlabel.h \
    src/Widgets/tpage.h \
    src/Widgets/tpresentation.h \
    src/Widgets/tstackpages.h \
    src/Widgets/ttoolbar.h \
    src/Widgets/tvirtualkey.h \
    src/Widgets/tvirtualkeyboard.h \
    #-------------------------
    # Util
    #------------------------- \
    src/Util/htmlhelper.h \
    src/Util/factory.h \
    src/Util/config.h \
    #-------------------------
    # ui
    #------------------------- \
    src/UI/ui_options.h \
    src/UI/ui_homepage.h \
    #-------------------------
    # Data
    #------------------------- \
    src/Data/tresult.h \
    src/Data/tusermanager.h \
    src/Data/tpractical.h \
    src/Data/tprogression.h \
    src/Data/tuser.h \
    src/Data/ttext.h \
    src/Data/tstats.h \
    src/Data/tlayout.h \
    src/Data/tjsonserializable.h \
    src/tapplication.h \
    src/Data/texercise.h \
    #-------------------------
    #   Games
    #------------------------- \
    src/Games/bullet.h \
    src/Games/letterwall.h \
    src/Games/recttext.h \
    src/Games/vector2f.h \
    src/Games/animatedsprite.h \
    src/Games/resourcemanager.h \
    src/Games/bouncemenu.h \
    src/Games/bouncedata.h \
    src/Games/bouncemain.h \
    src/Games/bouncehelp.h \
    src/Games/bouncegame.h \
    src/Games/countdown.h \
    src/Games/menubutton.h \
    src/Games/bouncescore.h \
    src/Games/Competition/competitionmain.h \
    src/Games/Competition/userlist.h

DISTFILES += \
    ressources/syle.qss

RESOURCES += \
    ressources.qrc
