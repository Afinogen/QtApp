#-------------------------------------------------
#
# Project created by QtCreator 2014-07-10T20:05:30
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    treemodel.cpp \
    treeitem.cpp \
    maincontroller.cpp

HEADERS  += mainwindow.h \
    treemodel.h \
    treeitem.h \
    maincontroller.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

