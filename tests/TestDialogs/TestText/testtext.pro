
QT += widgets testlib core

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../../src/

INCLUDEPATH += $$SRC
message($$INCLUDEPATH)

HEADERS = $$SRC/QTypingTest/Dialogs/twindowtest.h \
            $$SRC/QTypingTest/Dialogs/Exercices/tpracticetext.h \
            $$SRC/QTypingTest/Dialogs/Exercices/tstackpages.h \
            $$SRC/QTypingTest/Dialogs/Exercices/ttoolbar.h \
            $$SRC/QTypingTest/Dialogs/Exercices/tlabel.h \
            $$SRC/QTypingTest/Dialogs/Exercices/tpage.h \
            $$SRC/Data/tprogression.h \
            $$SRC/Data/tresult.h \
            $$SRC/Data/texercice.h \
            $$SRC/Data/tuser.h \
            $$SRC/Data/tstats.h \
            $$SRC/Data/tlayouts.h \
            $$SRC/Util/filehelper.h \
            $$SRC/Util/htmlhelper.h \
            $$SRC/Util/factory.h 
          

SOURCES = $$SRC/QTypingTest/Dialogs/twindowtest.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/tpracticetext.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/tstackpages.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/ttoolbar.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/tlabel.cpp \
            $$SRC/QTypingTest/Dialogs/Exercices/tpage.cpp \
            $$SRC/Data/tprogression.cpp \
            $$SRC/Data/tresult.cpp \
            $$SRC/Data/texercice.cpp \
            $$SRC/Data/tuser.cpp \
            $$SRC/Data/tstats.cpp \
            $$SRC/Data/tlayouts.cpp \
            $$SRC/Util/filehelper.cpp \
            $$SRC/Util/htmlhelper.cpp \
            $$SRC/Util/factory.cpp \
            testtext.cpp

# install
INSTALLS += target

target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testPracticeText

DESTDIR = build
TARGET = testPracticeText
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

