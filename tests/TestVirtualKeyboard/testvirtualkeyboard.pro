
QT += widgets testlib xml

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../src/

INCLUDEPATH += $$SRC

HEADERS = $$SRC/QTypingTest/Learn/tvirtualkey.h \
          $$SRC/QTypingTest/Learn/tvirtualkeyboard.h \
          $$SRC/QTypingTest/Learn/tfingerposition.h \
          $$SRC/QTypingTest/Learn/tpresentation.h \
          $$SRC/Util/factory.h \
          $$SRC/Data/tlayout.h

SOURCES = $$SRC/QTypingTest/Learn/tvirtualkey.cpp \
          $$SRC/QTypingTest/Learn/tvirtualkeyboard.cpp \
          $$SRC/QTypingTest/Learn/tfingerposition.cpp \
          $$SRC/QTypingTest/Learn/tpresentation.cpp \
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
