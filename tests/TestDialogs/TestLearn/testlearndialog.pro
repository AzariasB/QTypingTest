
QT += widgets testlib core xml

CONFIG          += -std=c++11
QMAKE_CXXFLAGS  += -std=c++11

SRC = $$PWD/../../../src/

INCLUDEPATH += $$SRC
message($$INCLUDEPATH)


HEADERS = $$SRC/Dialogs/twindowtest.h \
            $$SRC/Dialogs/twindowlearn.h \
            $$SRC/Widgets/tstackpages.h \
            $$SRC/Widgets/ttoolbar.h \
            $$SRC/Widgets/tlabel.h \
            $$SRC/Widgets/tpage.h \
            $$SRC/Widgets/tfingerposition.h \
            $$SRC/Widgets/tpresentation.h \
            $$SRC/Widgets/tvirtualkey.h \
            $$SRC/Widgets/tvirtualkeyboard.h \
            $$SRC/Data/tprogression.h \
            $$SRC/Data/tresult.h \
            $$SRC/Data/texercise.h \
            $$SRC/Data/tuser.h \
            $$SRC/Data/tusermanager.h \
            $$SRC/Data/tstats.h \
            $$SRC/Data/tlayout.h \
            $$SRC/Data/ttext.h \
            $$SRC/Util/htmlhelper.h \
            $$SRC/tapplication.h \
            $$SRC/Util/factory.h 
          

SOURCES = $$SRC/Dialogs/twindowtest.cpp \
            $$SRC/Dialogs/twindowlearn.cpp \
            $$SRC/Widgets/tstackpages.cpp \
            $$SRC/Widgets/ttoolbar.cpp \
            $$SRC/Widgets/tlabel.cpp \
            $$SRC/Widgets/tpage.cpp \
            $$SRC/Widgets/tfingerposition.cpp \
            $$SRC/Widgets/tpresentation.cpp \
            $$SRC/Widgets/tvirtualkey.cpp \
            $$SRC/Widgets/tvirtualkeyboard.cpp \
            $$SRC/Data/tprogression.cpp \
            $$SRC/Data/tresult.cpp \
            $$SRC/Data/texercise.cpp \
            $$SRC/Data/tuser.cpp \
            $$SRC/Data/tusermanager.cpp \
            $$SRC/Data/tstats.cpp \
            $$SRC/Data/tlayout.cpp \
            $$SRC/Data/ttext.cpp \
            $$SRC/Util/htmlhelper.cpp \
            $$SRC/Util/factory.cpp \
            $$SRC/tapplication.cpp \
            testlearndialog.cpp

# install
INSTALLS += target

RESOURCES += \
    $$PWD/../../../ressources.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/testLearnDialog

DESTDIR = build
TARGET = testlearnDialog
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

