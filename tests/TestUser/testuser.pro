
QT += widgets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11


HEADERs = ../../src/Data/TUser.h

SOURCES = ../../src/Data/TUser.cpp \
    testqstring.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target


TARGET = testUser
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

