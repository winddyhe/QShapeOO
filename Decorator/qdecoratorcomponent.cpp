#include "qdecoratorcomponent.h"

#include <QDebug>

QDecoratorComponent::QDecoratorComponent(QWidget *parent) :
    QShapeBoard(parent)
{
}

QDecoratorComponent::~QDecoratorComponent()
{
}

QShapeBoard* QDecoratorComponent::decorator(QShapeBoard *shapeBoard)
{
    m_decorator = shapeBoard;

    return this;
}

void QDecoratorComponent::Create()
{
    if(m_decorator)
    {
        qDebug() << "QDecoratorComponent..";
        m_decorator->Create();
    }
}
