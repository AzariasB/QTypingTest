
QT += widgets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERS = $$SRC/Data/tuser.h \
         $$SRC/Data/texercice.h \
         $$SRC/Data/tstats.h \
         $$SRC/Data/tresult.h \
         $$SRC/Data/tlayouts.h \
         $$SRC/Data/tprogression.h \
         $$SRC/Util/factory.h \
         $$SRC/Util/htmlhelper.h

SOURCES = $$SRC/Data/tuser.cpp \
         $$SRC/Data/texercice.cpp \
         $$SRC/Data/tstats.cpp \
         $$SRC/Data/tresult.cpp \
         $$SRC/Data/tlayouts.cpp \
         $$SRC/Data/tprogression.cpp \
         $$SRC/Util/factory.cpp \
         $$SRC/Util/htmlhelper.cpp \
        testuser.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testUser
INSTALLS += target

DESTDIR = build
TARGET = testUser
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

