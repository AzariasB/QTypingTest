
QT += widgets testlib core

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

PRO_PATH=$$PWD

INCLUDEPATH += $$PRO_PATH/../../src
message($$INCLUDEPATH)

SRC = $$PWD/../../src/

HEADERS = $$SRC/QTypingTest/Dialogs/twindowtest.h \
            $$SRC/QTypingTest/Dialogs/Exercices/tpracticebase.h \
            $$SRC/QTypingTest/Dialogs/Exercices/tstackpages.h \
            $$SRC/QTypingTest/Dialogs/Exercices/ttoolbar.h \
            $$SRC/QTypingTest/Dialogs/Exercices/tlabel.h \
            $$SRC/QTypingTest/Dialogs/Exercices/tpage.h \
            $$SRC/Data/tprogression.h \
            $$SRC/Data/tresult.h \
            $$SRC/Data/texercice.h \
            $$SRC/Data/tkeys.h \
            $$SRC/Data/tuser.h \
            $$SRC/Data/tstats.h \
            $$SRC/Util/filehelper.h \
            $$SRC/Util/htmlhelper.h \
            $$SRC/Util/factory.h 
          

SOURCES = $$SRC/QTypingTest/Dialogs/twindowtest.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/tpracticebase.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/tstackpages.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/ttoolbar.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/tlabel.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/tpage.cpp \
            $$SRC/Data/tprogression.cpp \
            $$SRC/Data/tresult.cpp \
            $$SRC/Data/tkeys.cpp \
            $$SRC/Data/texercice.cpp \
            $$SRC/Data/tuser.cpp \
            $$SRC/Data/tstats.cpp \
            $$SRC/Util/filehelper.cpp \
            $$SRC/Util/htmlhelper.cpp \
            $$SRC/Util/factory.cpp \
            testpracticebase.cpp

# install
INSTALLS += target

target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testPracticeBase

DESTDIR = build
TARGET = testPracticeBase
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

