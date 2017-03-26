#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T18:23:51
#
#-------------------------------------------------

QT += widgets testlib core xml

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/
INCLUDEPATH += $$SRC


HEADERS = $$SRC/Games/vector2f.h \
            $$SRC/Games/bounce.h \
            $$SRC/Games/bullet.h \
            $$SRC/Games/endmessage.h \
            $$SRC/Games/letterwall.h


SOURCES = $$SRC/Games/vector2f.cpp \
            $$SRC/Games/bounce.cpp \
            $$SRC/Games/bullet.cpp \
            $$SRC/Games/letterwall.cpp \
            $$SRC/Games/endmessage.cpp \
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
