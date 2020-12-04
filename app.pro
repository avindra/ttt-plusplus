# This is meant only for building wasm
# with qt and emscripten
#
# Use the cmake build wherever possible

QT += core widgets
CONFIG += c++17

INCLUDEPATH += $$PWD/Src

HEADERS += $$PWD/Src/AI.h \
	$$PWD/Src/Board.h \
	$$PWD/Src/btnSquare.h \
	$$PWD/Src/winmain.h \
	$$PWD/Src/Game.h

FORMS = $$PWD/Src/winmain.ui

SOURCES += $$PWD/Src/AI.cpp \
	$$PWD/Src/Board.cpp \
	$$PWD/Src/btnSquare.cpp \
	$$PWD/Src/Game.cpp \
	$$PWD/Src/main.cpp \
	$$PWD/Src/winmain.cpp

