#-------------------------------------------------
#
# Project created by QtCreator 2016-01-25T12:43:50
#
#-------------------------------------------------

QT       += testlib xml

QT       -= gui

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERS = $$SRC/Data/tuser.h \
         $$SRC/Data/tusermanager.h \
         $$SRC/Data/texercice.h \
         $$SRC/Data/tstats.h \
         $$SRC/Data/tresult.h \
         $$SRC/Data/tlayout.h \
         $$SRC/Data/tjsonserializable.h \
         $$SRC/Data/tprogression.h \
         $$SRC/Data/ttext.h \
         $$SRC/Util/factory.h \
         $$SRC/tapplication.h \
         $$SRC/Util/htmlhelper.h

SOURCES = $$SRC/Data/tuser.cpp \
         $$SRC/Data/tusermanager.cpp \
         $$SRC/Data/texercice.cpp \
         $$SRC/Data/tstats.cpp \
         $$SRC/Data/tresult.cpp \
         $$SRC/Data/tlayout.cpp \
         $$SRC/Data/tjsonserializable.cpp \
         $$SRC/Data/tprogression.cpp \
         $$SRC/Data/ttext.cpp \
         $$SRC/Util/factory.cpp \
         $$SRC/Util/htmlhelper.cpp \
         $$SRC/tapplication.cpp \
            testuser.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testUser
INSTALLS += target

RESOURCES += \
    ../../ressources.qrc

DESTDIR = build
TARGET = testUser
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
