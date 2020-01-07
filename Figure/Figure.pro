#-------------------------------------------------
#
# Project created by QtCreator 2018-07-24T16:10:44
#
#-------------------------------------------------

QT     += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets

TARGET = Figure
TEMPLATE = app
CONFIG += c++11

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
        View/kalkabstract.cpp \
    Model/plane.cpp \
    Model/point2.cpp \
    Model/point3.cpp \
    Model/polyhedron.cpp \
    Model/shape.cpp \
    Model/solid.cpp \
    Model/square.cpp \
    Model/regularpentagon.cpp \
    Model/circle.cpp \
    Model/cube.cpp \
    Model/rightcircularcylinder.cpp \
    Model/isoscelestrapezoid.cpp \
    Model/regularpolygon.cpp \
    Model/simplepolygon.cpp \
    Model/platonicsolid.cpp \
    Model/tetrahedron.cpp \
    Model/equilateraltriangle.cpp \
    Model/rectangle.cpp \
    Model/solidofrevolution.cpp \
    Model/rightprism.cpp \
    Model/trapezoidalprism.cpp \
    Model/rectangularparallelepiped.cpp \
    Model/pentagonalprism.cpp \
    View/mainwindow.cpp \
    View/kalk2dwidget.cpp \
    View/kalk3dwidget.cpp \
    Model/factory.cpp \
    View/kalkdraw2d.cpp \
    View/renderarea.cpp

HEADERS += \
        ./View/kalkabstract.h \
    Model/plane.h \
    Model/point2.h \
    Model/point3.h \
    Model/polyhedron.h \
    Model/shape.h \
    Model/solid.h \
    Model/square.h \
    Model/regularpentagon.h \
    Model/circle.h \
    Model/cube.h \
    Model/rightcircularcylinder.h \
    Model/isoscelestrapezoid.h \
    Model/regularpolygon.h \
    Model/simplepolygon.h \
    Model/platonicsolid.h \
    Model/tetrahedron.h \
    Model/equilateraltriangle.h \
    Model/rectangle.h \
    Model/solidofrevolution.h \
    Model/rightprism.h \
    Model/trapezoidalprism.h \
    Model/rectangularparallelepiped.h \
    Model/pentagonalprism.h \
    View/mainwindow.h \
    View/kalk2dwidget.h \
    View/kalk3dwidget.h \
    Model/factory.h \
    Eccezioni/kalkexception.h \
    View/kalkdraw2d.h \
    View/renderarea.h
