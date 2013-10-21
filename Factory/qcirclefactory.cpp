#include "qcirclefactory.h"

QCircleFactory::QCircleFactory()
{
}

QShape* QCircleFactory::createShape(QString name)
{
    return (new QShapeCircle(name));
}
