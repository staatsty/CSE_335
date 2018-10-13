#-------------------------------------------------
#
# Project created by QtCreator 2018-04-15T09:21:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp
CONFIG += console

HEADERS += \
        mainwindow.h \
    pet.h \
    bird.h \
    cat.h \
    dog.h \
    fish.h \
    bundle.h \
    visitor.h \
    builder.h \
    databuilder.h \
    dataparser.h \
    sortablevector.h \
    bubblesorttemplate.h \
    bubblesortdecreasing.h \
    petdatabasesortablebyname.h \
    nonstackedbasedsumvisitor.h \
    dialog.h \
    newtablewidget.h

FORMS += \
        mainwindow.ui \
    dialog.ui

DISTFILES += \
    Pets.csv
