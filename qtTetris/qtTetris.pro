#-------------------------------------------------
#
# Project created by QtCreator 2013-09-21T11:24:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtTetris
TEMPLATE = app

INCLUDEPATH += Include/ViewModel\
	       Include/Model\
	       Include/Controll

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
	Dialog.cpp \
    src/Model/TetriminoCreateNormal.cpp \
    src/Model/TetriminoCreateDifficult.cpp \
    src/Model/MyselfTetrimino.cpp \
    src/Model/TetrisField.cpp \
    src/ViewModel/ConvDispInfo.cpp \
    src/Model/GameManeger.cpp \
    src/Controll/Controller.cpp \
    StatePlayMode.cpp \
    StatePauseMode.cpp \
    StateMode.cpp

HEADERS  += Dialog.h \
    Include/Model/Tetrimino_Z.h \
    Include/Model/Tetrimino_T.h \
    Include/Model/Tetrimino_S.h \
    Include/Model/Tetrimino_O.h \
    Include/Model/Tetrimino_L.h \
    Include/Model/Tetrimino_J.h \
    Include/Model/Tetrimino_I.h \
    Include/Model/Tetrimino.h \
    Include/Model/DataDefine.h \
    Include/Model/TetriminoFactory.h \
    Include/Model/TetriminoCreateNormal.h \
    Include/Model/TetriminoCreateDifficult.h \
    Include/Model/MyselfTetrimino.h \
    Include/Model/TetrisField.h \
    Include/ViewModel/ConvDispInfo.h \
    Include/Model/GameManeger.h \
    Include/Controll/Controller.h \
    Include/Model/Tetrimino__S.h \
    Include/Model/Tetrimino__R.h \
    Include/Model/Tetrimino__N.h \
    Include/Model/Tetrimino__M.h \
    Include/Model/Tetrimino__I.h \
    Include/Model/Tetrimino__E.h \
    Include/Model/Tetrimino__D.h \
    Include/Model/Tetrimino__A.h \
    StatePlayMode.h \
    StatePauseMode.h \
    StateMode.h

FORMS    += Dialog.ui

RESOURCES += \
    Dialog.qrc
