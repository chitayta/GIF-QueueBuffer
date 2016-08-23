#-------------------------------------------------
#
# Project created by QtCreator 2016-08-10T09:15:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GIF8
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    gifdecoder.cpp \
    gifdisplayer.cpp

HEADERS  += widget.h \
    gifdecoder.h \
    gifdisplayer.h
