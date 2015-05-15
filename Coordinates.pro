#-------------------------------------------------
#
# Project created by QtCreator 2015-05-06T15:28:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Coordinates
TEMPLATE = app

include(brisa.pri)

SOURCES += main.cpp\
        coordinates.cpp\
	functions.cpp \
    view.cpp

HEADERS  += coordinates.h\
	 functions.h \
    coordinates_ui.h \
    view.h

RESOURCES += \
    resource.qrc
