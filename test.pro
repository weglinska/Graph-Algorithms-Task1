#-------------------------------------------------
#
# Project created by QtCreator 2016-02-23T14:58:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphpainter.cpp \
    matrixview.cpp \
    matrixvievcell.cpp \
    graphsizewidget.cpp \
    generatorswidget.cpp \
    graph.cpp \
    listview.cpp \
    listviewitem.cpp \
    listviewremovebutton.cpp \
    addconnection.cpp \
    connectionmatrixview.cpp \
    filemanager.cpp \
    filemanagerwidget.cpp \
    engine.cpp \
    sequence.cpp \
    sequencewidget.cpp \
    randomizer.cpp \
    randomizerwidget.cpp \
    hamiltoniancycle.cpp \
    hamiltonianwidget.cpp \
    euleriancircuit.cpp \
    euleriancircuitwidget.cpp \
    consistent.cpp \
    vertex.cpp \
    consistentwidget.cpp

HEADERS  += mainwindow.h \
    graphpainter.h \
    matrixview.h \
    matrixvievcell.h \
    graphsizewidget.h \
    generatorswidget.h \
    graph.h \
    listview.h \
    listviewitem.h \
    listviewremovebutton.h \
    addconnection.h \
    connectionmatrixview.h \
    filemanager.h \
    filemanagerwidget.h \
    engine.h \
    sequence.h \
    sequencewidget.h \
    randomizer.h \
    randomizerwidget.h \
    hamiltoniancycle.h \
    hamiltonianwidget.h \
    euleriancircuit.h \
    euleriancircuitwidget.h \
    consistent.h \
    vertex.h \
    consistentwidget.h

FORMS    += mainwindow.ui \
    graphsizewidget.ui \
    generatorswidget.ui \
    addconnection.ui \
    filemanagerwidget.ui \
    sequencewidget.ui \
    randomizerwidget.ui \
    hamiltonianwidget.ui \
    euleriancircuitwidget.ui \
    consistentwidget.ui

RESOURCES += \
    img/images.qrc

DISTFILES +=
