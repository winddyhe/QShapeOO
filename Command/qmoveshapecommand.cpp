#include "qmoveshapecommand.h"

QMoveShapeCommand::QMoveShapeCommand(QShape *receiver) :
    QShapeCommand(receiver)
{
}

void QMoveShapeCommand::execute()
{
    m_shape->move(m_pos.x(), m_pos.y());
}
