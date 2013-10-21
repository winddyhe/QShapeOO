#ifndef QSHAPEFACTORYMETHOD_H
#define QSHAPEFACTORYMETHOD_H

#include "../Shapes/qshape.h"

class QShapeFactoryMethod
{
public:
    virtual ~QShapeFactoryMethod(){}
    virtual QShape* createShape(QString name) = 0;
};

#endif // QSHAPEFACTORYMETHOD_H
