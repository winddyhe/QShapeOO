#ifndef QSHAPESIMPLEFACTORY_H
#define QSHAPESIMPLEFACTORY_H

#include "../Shapes/qshapetriangle.h"
#include "../Shapes/qshapecircle.h"
#include "../Shapes/qshaperect.h"

class QShapeSimpleFactory
{
public:
    QShapeSimpleFactory();

    QShape* createShape(QString name, EShapeType type);
};

#endif // QSHAPESIMPLEFACTORY_H
