
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
        $$SRC/Data/tuser.h \
        $$SRC/Data/tusermanager.h \
        $$SRC/Data/tstats.h \
        $$SRC/Data/tjsonserializable.h \
        $$SRC/Data/texercise.h \
        $$SRC/Data/tresult.h \
        $$SRC/Data/tprogression.h \
        $$SRC/Data/ttext.h \
        $$SRC/tapplication.h \
        $$SRC/Util/htmlhelper.h \
        $$SRC/Data/tlayout.h

SOURCES = $$SRC/Widgets/tvirtualkey.cpp \
        $$SRC/Widgets/tvirtualkeyboard.cpp \
        $$SRC/Widgets/tfingerposition.cpp \
        $$SRC/Widgets/tpresentation.cpp \
        $$SRC/Data/tlayout.cpp \
        $$SRC/Util/factory.cpp \
        $$SRC/Data/tuser.cpp \
        $$SRC/Data/tusermanager.cpp \
        $$SRC/Data/tstats.cpp \
        $$SRC/Data/tjsonserializable.cpp \
        $$SRC/Data/texercise.cpp \
        $$SRC/Data/tresult.cpp \
        $$SRC/Data/tprogression.cpp \
        $$SRC/Data/ttext.cpp \
        $$SRC/tapplication.cpp \
        $$SRC/Util/htmlhelper.cpp \
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
