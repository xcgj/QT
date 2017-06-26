#-------------------------------------------------
#
# Project created by QtCreator 2017-05-08T11:22:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Switche2Win_overloadSignal
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    vice.cpp

HEADERS  += widget.h \
    vice.h

#增加C++11新特性
CONFIG += C++11
