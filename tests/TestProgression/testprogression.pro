
QT += widgets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11


HEADERs = ../../src/Data/tprogression.h

SOURCES = ../../src/Data/tprogression.cpp \
    testprogression.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target

DESTDIR = build
TARGET = testProgression
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

