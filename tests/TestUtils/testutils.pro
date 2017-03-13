
QT += widgets testlib xml

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERS = $$SRC/Util/htmlhelper.h \
            $$SRC/Util/factory.h


SOURCES = $$SRC/Util/htmlhelper.cpp \
        $$SRC/Util/factory.cpp \
        testutils.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target

DESTDIR = build
TARGET = testUtils
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc


RESOURCES += \
    ../../ressources.qrc
