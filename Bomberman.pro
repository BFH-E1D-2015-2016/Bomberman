#-------------------------------------------------
#
# Project created by QtCreator 2016-04-26T11:21:19
#
#-------------------------------------------------
CONFIG += c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bomberman
TEMPLATE = app


SOURCES += main.cpp \
    myrect.cpp \
    playfield.cpp \
    block.cpp \
    player.cpp \
    game.cpp \
    bomb.cpp

HEADERS  += \
    myrect.h \
    playfield.h \
    block.h \
    player.h \
    game.h \
    bomb.h

FORMS    +=
