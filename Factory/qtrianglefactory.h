#ifndef QTRIANGLEFACTORY_H
#define QTRIANGLEFACTORY_H

#include "qshapefactorymethod.h"
#include "../Shapes/qshapetriangle.h"

class QTriangleFactory : public QShapeFactoryMethod
{
public:
    QTriangleFactory();
    QShape* createShape(QString name);
};

#endif // QTRIANGLEFACTORY_H
