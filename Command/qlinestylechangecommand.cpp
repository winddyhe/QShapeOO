#include "qlinestylechangecommand.h"

QLineStyleChangeCommand::QLineStyleChangeCommand(Qt::PenStyle penStyle, QShape *receiver):
    QShapeCommand(receiver)
{
    m_penStyle = penStyle;
}

void QLineStyleChangeCommand::execute()
{
    m_shape->setLineType(m_penStyle);
}
