#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T18:23:51
#
#-------------------------------------------------

QT += widgets testlib core xml multimedia

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/
INCLUDEPATH += $$SRC


HEADERS = $$SRC/Games/vector2f.h \
			$$SRC/Games/bouncegame.h \
            $$SRC/Games/bullet.h \
            $$SRC/Games/recttext.h \
            $$SRC/Games/animatedsprite.h \
            $$SRC/Games/resourcemanager.h \
			$$SRC/Games/bouncemenu.h \
			$$SRC/Games/bouncedata.h \
			$$SRC/Games/bouncemain.h \
			$$SRC/Games/bouncehelp.h \
            $$SRC/Games/letterwall.h


SOURCES = $$SRC/Games/vector2f.cpp \
			$$SRC/Games/bouncegame.cpp \
            $$SRC/Games/bullet.cpp \
            $$SRC/Games/letterwall.cpp \
            $$SRC/Games/recttext.cpp \
            $$SRC/Games/animatedsprite.cpp \
            $$SRC/Games/resourcemanager.cpp \
			$$SRC/Games/bouncemenu.cpp \
			$$SRC/Games/bouncedata.cpp \
			$$SRC/Games/bouncemain.cpp \
			$$SRC/Games/bouncehelp.cpp \
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
