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
    src/Model/TetriminoFactory.cpp \
    src/Model/TetriminoCreateNormal.cpp \
    src/Model/TetriminoCreateDifficult.cpp \
    src/Model/MyselfTetrimino.cpp \
    src/Model/TetrisField.cpp \
    src/ViewModel/ConvDispInfo.cpp \
    src/Model/GameManeger.cpp \
    src/Controll/Controller.cpp

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
    Include/Controll/Controller.h

FORMS    += Dialog.ui
