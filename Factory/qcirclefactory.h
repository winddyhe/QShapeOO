#ifndef QCIRCLEFACTORY_H
#define QCIRCLEFACTORY_H

#include "qshapefactorymethod.h"
#include "../Shapes/qshapecircle.h"

class QShapeCircle;

class QCircleFactory : public QShapeFactoryMethod
{
public:
    QCircleFactory();
    QShape* createShape(QString name);
};

#endif // QCIRCLEFACTORY_H
