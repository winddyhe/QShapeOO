#ifndef QRECTFACTORY_H
#define QRECTFACTORY_H

#include "qshapefactorymethod.h"
#include "../Shapes/qshaperect.h"

class QRectFactory : public QShapeFactoryMethod
{
public:
    QRectFactory();
    QShape* createShape(QString name);
};

#endif // QRECTFACTORY_H
