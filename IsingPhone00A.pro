#-------------------------------------------------
#
# Project created by QtCreator 2014-06-19T14:47:53
#
#-------------------------------------------------

#QMAKE_CXXFLAGS += -static-libgcc
QT       += core gui
QT += datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = IsingPhone00A
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += d:\Kody\Libs\


SOURCES  += main.cpp\
         mainwindow.cpp \
         isingtab.cpp \
    visualtest.cpp

HEADERS  += mainwindow.h \
         isingtab.h \
    visualtest.h


FORMS    += mainwindow.ui


