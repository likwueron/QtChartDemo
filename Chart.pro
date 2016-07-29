#-------------------------------------------------
#
# Project created by QtCreator 2016-07-29T19:56:52
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chart
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qchartpresent.cpp \
    axismodel.cpp

HEADERS  += widget.hpp \
    qchartpresent.hpp \
    axismodel.hpp

FORMS    += widget.ui
