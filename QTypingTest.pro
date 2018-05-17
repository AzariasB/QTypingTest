#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T15:06:49
#
#-------------------------------------------------

QT              += designer uitools core gui xml multimedia
CONFIG          += -std=c++14 debug
QMAKE_CXXFLAGS  += -std=c++14

PRO_PATH=$$PWD

INCLUDEPATH = $$PRO_PATH/src


greaterThan(QT_MAJOR_VERSION, 5): QT += widgets


UI_DIR = src/UI


TEMPLATE = app

#Icons for windows
RC_ICONS += resources/icon.ico
ICON = resources/icon.ico

FORMS += src/UI/homepage.ui \
         src/UI/options.ui


SOURCES +=\
    src/main.cpp \
    src/tapplication.cpp


HEADERS +=\
    src/tapplication.h


include(src/Data/data.pro)
include(src/Dialogs/dialogs.pro)
include(src/Widgets/widgets.pro)
include(src/Util/util.pro)
include(src/Pages/pages.pro)
include(src/Games/games.pro)


RESOURCES += ressources.qrc
