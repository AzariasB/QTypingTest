
QT += widgets testlib core xml

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../../src/

INCLUDEPATH += $$SRC

HEADERS = $$SRC/Dialogs/twindowtest.h \
            $$SRC/Dialogs/tpracticetext.h \
            $$SRC/Widgets/tstackpages.h \
            $$SRC/Widgets/ttoolbar.h \
            $$SRC/Widgets/tlabel.h \
            $$SRC/Widgets/tpage.h \
            $$SRC/Data/tprogression.h \
            $$SRC/Data/tresult.h \
            $$SRC/Data/texercice.h \
            $$SRC/Data/tuser.h \
            $$SRC/Data/ttext.h \
            $$SRC/Data/tusermanager.h \
            $$SRC/Data/tstats.h \
            $$SRC/Data/tlayout.h \
            $$SRC/Util/htmlhelper.h \
            $$SRC/Util/factory.h 
          

SOURCES = $$SRC/Dialogs/twindowtest.cpp \
            $$SRC/Dialogs/tpracticetext.cpp \
            $$SRC/Widgets/tstackpages.cpp \
            $$SRC/Widgets/ttoolbar.cpp \
            $$SRC/Widgets/tlabel.cpp \
            $$SRC/Widgets/tpage.cpp \
            $$SRC/Data/tprogression.cpp \
            $$SRC/Data/tresult.cpp \
            $$SRC/Data/texercice.cpp \
            $$SRC/Data/tuser.cpp \
            $$SRC/Data/tusermanager.cpp \
            $$SRC/Data/tstats.cpp \
            $$SRC/Data/tlayout.cpp \
            $$SRC/Data/ttext.cpp \
            $$SRC/Util/htmlhelper.cpp \
            $$SRC/Util/factory.cpp \
            testtext.cpp

# install
INSTALLS += target

RESOURCES += \
    $$PWD/../../../ressources.qrc


target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testtext

DESTDIR = build
TARGET = testtext
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

