#ifndef QDECORATORCOMPONENT_H
#define QDECORATORCOMPONENT_H

#include "../qshapeboard.h"

class QDecoratorComponent : public QShapeBoard
{
    Q_OBJECT
public:
    explicit QDecoratorComponent(QWidget *parent = 0);
    virtual ~QDecoratorComponent();

    QShapeBoard* decorator(QShapeBoard* shapeBoard);
    virtual void Create();

protected:
    QShapeBoard*    m_decorator;
};

#endif // QDECORATORCOMPONENT_H
