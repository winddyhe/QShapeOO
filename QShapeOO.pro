#-------------------------------------------------
#
# Project created by QtCreator 2012-04-27T18:07:47
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = QShapeOO
TEMPLATE = app


SOURCES += main.cpp \
    Shapes/qshapetriangle.cpp \
    Shapes/qshaperect.cpp \
    Shapes/qshapecircle.cpp \
    Shapes/qshape.cpp \
    qshapeboard.cpp \
    Factory/qcirclefactory.cpp \
    Factory/qshapesimplefactory.cpp \
    Factory/qtrianglefactory.cpp \
    Factory/qrectfactory.cpp \
    Decorator/qdecoratorcomponent.cpp \
    Decorator/qdecoratormenu.cpp \
    Decorator/qdecoratorstatusbar.cpp \
    Decorator/qdecoratorscrollbar.cpp \
    Factory/qshapefactorymethod.cpp \
    Facade/qshapelistwidget.cpp \
    Facade/qshapelist.cpp \
    Bridge/qdrawInterface.cpp \
    Bridge/qpainterdrawer.cpp \
    Bridge/qopengldrawer.cpp \
    Command/qshapecommand.cpp \
    Command/qselectedshapecommand.cpp \
    Command/qmoveshapecommand.cpp \
    Command/qcommandsender.cpp \
    Command/qzoomshapecommand.cpp \
    Command/qcolorchangecommand.cpp \
    Command/qlinestylechangecommand.cpp \
    Command/qshapefilecommand.cpp \
    Command/qcalcareacommand.cpp

HEADERS  += \
    Shapes/qshaperect.h \
    Shapes/qshapecircle.h \
    Shapes/qshape.h \
    Shapes/qshapetriangle.h \
    qshapeboard.h \
    Factory/qcirclefactory.h \
    Factory/qshapesimplefactory.h \
    Factory/qtrianglefactory.h \
    Factory/qrectfactory.h \
    Decorator/qdecoratorcomponent.h \
    Decorator/qdecoratormenu.h \
    Decorator/qdecoratorstatusbar.h \
    Decorator/qdecoratorscrollbar.h \
    Factory/qshapefactorymethod.h \
    Facade/qshapelistwidget.h \
    Facade/qshapelist.h \
    Bridge/qdrawinterface.h \
    Bridge/qpainterdrawer.h \
    Bridge/qopengldrawer.h \
    Command/qshapecommand.h \
    Command/qselectedshapecommand.h \
    Command/qmoveshapecommand.h \
    Command/qcommandsender.h \
    Command/qzoomshapecommand.h \
    Command/qcolorchangecommand.h \
    Command/qlinestylechangecommand.h \
    Command/qshapefilecommand.h \
    Command/qcalcareacommand.h

RESOURCES += \
    images.qrc












