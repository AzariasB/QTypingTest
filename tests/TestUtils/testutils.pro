
QT += widgets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERs = $$SRC/Util/htmlhelp.h \    
    $$SRC/Util/factory.h \
    $$SRC/Util/filehelper.h


SOURCES = $$SRC/Util/htmlhelper.cpp \
    $$SRC/Util/factory.cpp \
    $$SRC/Util/filehelper.cpp \
    testutils.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target

DESTDIR = build
TARGET = testUtils
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

