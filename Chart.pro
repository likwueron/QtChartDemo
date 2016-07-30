#-------------------------------------------------
#
# Project created by QtCreator 2016-07-29T19:56:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chart
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    axismodel.cpp

HEADERS  += widget.hpp \
    axismodel.hpp

FORMS    += widget.ui

greaterThan(QT_MAJOR_VERSION, 4) {
greaterThan(QT_MINOR_VERSION, 6) {
    QT += charts
    SOURCES += qchartpresent.cpp
    HEADERS += qchartpresent.hpp
}
}

DISTFILES += \
    work
