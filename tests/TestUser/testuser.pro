
QT += widgets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11


HEADERs = ../../src/Data/tuser.h \    
    ../../src/Data/tresult.h \
    ../../src/Data/tprogression.h \
    ../../src/Data/texercice.h

SOURCES = ../../src/Data/tuser.cpp \
    ../../src/Data/tresult.cpp \
    ../../src/Data/tprogression.cpp \
    ../../src/Data/texercice.cpp \
    testuser.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target


TARGET = testUser
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

