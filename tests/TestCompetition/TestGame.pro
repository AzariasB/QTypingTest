#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T18:23:51
#
#-------------------------------------------------

QT += widgets core websockets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/
INCLUDEPATH += $$SRC


HEADERS = $$SRC/Games/competitionmain.h

SOURCES = $$SRC/Games/competitionmain.cpp \
            testgame.cpp

# install
INSTALLS += target

target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testImprove

RESOURCES += \
    $$PWD/../../ressources.qrc

DESTDIR = build
TARGET = testGame
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
