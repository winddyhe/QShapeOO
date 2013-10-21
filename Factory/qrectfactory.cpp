#include "qrectfactory.h"

QRectFactory::QRectFactory()
{
}

QShape* QRectFactory::createShape(QString name)
{
    return (new QShapeRect(name));
}
