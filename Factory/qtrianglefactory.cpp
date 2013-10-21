#include "qtrianglefactory.h"

QTriangleFactory::QTriangleFactory()
{
}

QShape* QTriangleFactory::createShape(QString name)
{
    return (new QShapeTriangle(name));
}

