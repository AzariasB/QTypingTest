
QT += widgets testlib xml

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERS = $$SRC/Widgets/tvirtualkey.h \
        $$SRC/Widgets/tvirtualkeyboard.h \
        $$SRC/Widgets/tfingerposition.h \
        $$SRC/Widgets/tpresentation.h \
        $$SRC/Util/factory.h \
        $$SRC/Data/tlayout.h

SOURCES = $$SRC/Widgets/tvirtualkey.cpp \
        $$SRC/Widgets/tvirtualkeyboard.cpp \
        $$SRC/Widgets/tfingerposition.cpp \
        $$SRC/Widgets/tpresentation.cpp \
        $$SRC/Data/tlayout.cpp \
        $$SRC/Util/factory.cpp \
        testvirtualkeyboard.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testVirtualKeyboard
INSTALLS += target

DESTDIR = build
TARGET = testVirtualKeyboard
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

RESOURCES += \
    ../../ressources.qrc
