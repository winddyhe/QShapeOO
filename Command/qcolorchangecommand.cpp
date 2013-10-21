#include "qcolorchangecommand.h"

QColorChangeCommand::QColorChangeCommand(QColor color, QShape *receiver):
    QShapeCommand(receiver)
{
    m_color = color;
}

void QColorChangeCommand::execute()
{
    m_shape->setLineColor(m_color);
}
