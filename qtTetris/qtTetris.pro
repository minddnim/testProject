#-------------------------------------------------
#
# Project created by QtCreator 2013-09-21T11:24:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtTetris
TEMPLATE = app

INCLUDEPATH += Include/View\
	       Include/Model\
	       Include/Controll

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
	mainwindow.cpp \
    src/Model/Tetrimino_Z.cpp \
    src/Model/Tetrimino_T.cpp \
    src/Model/Tetrimino_S.cpp \
    src/Model/Tetrimino_O.cpp \
    src/Model/Tetrimino_L.cpp \
    src/Model/Tetrimino_J.cpp \
    src/Model/Tetrimino_I.cpp \
    src/Model/Tetrimino.cpp \
    src/Model/TetriminoFactory.cpp \
    src/Model/TetriminoCreateNormal.cpp \
    src/Model/TetriminoCreateDifficult.cpp

HEADERS  += mainwindow.h \
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
    Include/Model/TetriminoCreateDifficult.h

FORMS    += mainwindow.ui
