#-------------------------------------------------
#
# Project created by QtCreator 2014-07-10T20:05:30
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

deployment.files += keaz.db
deployment.path = /assets
INSTALLS += deployment

TARGET = test
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    treemodel.cpp \
    treeitem.cpp \
    maincontroller.cpp \
    downloader.cpp

HEADERS  += mainwindow.h \
    treemodel.h \
    treeitem.h \
    maincontroller.h \
    downloader.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

OTHER_FILES += \
    keaz.db
