
QT += widgets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERs = $$SRC/Data/tuser.h \    
    $$SRC/Data/tresult.h \
    $$SRC/Data/tprogression.h \
    $$SRC/Data/tstats.h \
    $$SRC/Util/factory.h \
    $$SRC/Util/htmlhelper.h \
    $$SRC/Util/filehelper.h \
    $$SRC/Data/texercice.h

SOURCES = $$SRC/Data/tuser.cpp \
    $$SRC/Data/tresult.cpp \
    $$SRC/Data/tprogression.cpp \
    $$SRC/Data/tstats.cpp \
    $$SRC/Util/factory.cpp \
    $$SRC/Util/htmlhelper.cpp \
    $$SRC/Util/filehelper.cpp \
    $$SRC/Data/texercice.cpp \
    testuser.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target

DESTDIR = build
TARGET = testUser
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

