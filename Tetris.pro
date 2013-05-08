#-------------------------------------------------
#
# Project created by QtCreator 2013-05-08T17:12:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    well.cpp \
    figure.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    well.h \
    figure.h \
    figures.h \
    game.h

QMAKE_CXXFLAGS += -std=gnu++0x
