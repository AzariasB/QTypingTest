
QT += widgets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11


HEADERs = ../../src/Util/htmlhelp.h \    


SOURCES = ../../src/Util/htmlhelper.cpp \
    testutils.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target

DESTDIR = build
TARGET = testUtils
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

