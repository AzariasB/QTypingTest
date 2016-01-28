
QT += widgets testlib

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERS = $$SRC/QTypingTest/Learn/tvirtualkey.h \
          $$SRC/QTypingTest/Learn/tvirtualkeyboard.h \
          $$SRC/Util/filehelper.h


SOURCES = $$SRC/QTypingTest/Learn/tvirtualkey.cpp \
          $$SRC/QTypingTest/Learn/tvirtualkeyboard.cpp \
          $$SRC/Util/filehelper.cpp \
    testvirtualkeyboard.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testVirtualKeyboard
INSTALLS += target

DESTDIR = build
TARGET = testVirtualKeyboard
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

