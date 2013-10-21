#include "qshapecommand.h"

QShapeCommand::QShapeCommand(QShape *receiver)
{
    m_shape = receiver;
}

void QShapeCommand::setCommandReceiver(QShape *shape)
{
    m_shape = shape;
}

void QShapeCommand::setPosition(QPoint pos)
{
    m_pos = pos;
}
