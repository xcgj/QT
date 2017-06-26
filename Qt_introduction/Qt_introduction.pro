#-------------------------------------------------
#
# Project created by QtCreator 2017-05-07T15:46:20
#
#-------------------------------------------------

# 注释代码用#号

#模块
QT       += core gui

#为了兼容qt4，高于版本4，添加 QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#应用程序名字，可修改，运行会生成不同名字的build文件
TARGET = Qt_introduction

#指定makefile的类型，指定生成app，可改为lib等
TEMPLATE = app

#源文件 .cpp文件
SOURCES += main.cpp\
        mywidget.cpp

#头文件 .h文件
HEADERS  += mywidget.h
