#include "qshapesimplefactory.h"

QShapeSimpleFactory::QShapeSimpleFactory()
{
}

QShape* QShapeSimpleFactory::createShape(QString name,EShapeType type)
{
    QShape *shape = NULL;
    switch(type)
    {
    case eTriangle:
        shape = new QShapeTriangle(name);
        break;
    case eRect:
        shape = new QShapeRect(name);
        break;
    case eCircle:
        shape = new QShapeCircle(name);
        break;
    }
    return shape;
}
