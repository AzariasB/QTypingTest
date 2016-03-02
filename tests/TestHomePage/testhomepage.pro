
QT += widgets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERS = $$SRC/QTypingTest/Home/homepage.h \
          $$SRC/Data/tusermanager.h \
          $$SRC/Data/tuser.h \
          $$SRC/Data/tprogression.h \
          $$SRC/Data/texercice.h \
          $$SRC/Data/tresult.h \
          $$SRC/Data/tstats.h  \
          $$SRC/Data/tlayouts.h \
          $$SRC/Util/factory.h \
          $$SRC/Util/htmlhelper.h 


SOURCES = $$SRC/QTypingTest/Home/homepage.cpp \
          $$SRC/Data/tprogression.cpp \
          $$SRC/Data/texercice.cpp \
          $$SRC/Data/tresult.cpp \
          $$SRC/Data/tstats.cpp \
          $$SRC/Data/tusermanager.cpp \
          $$SRC/Data/tuser.cpp \
          $$SRC/Data/tlayouts.cpp \
          $$SRC/Util/factory.cpp \
          $$SRC/Util/htmlhelper.cpp  \
          testhomepage.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testHomePage
INSTALLS += target

DESTDIR = build
TARGET = testHomePage
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

