#include "qselectedshapecommand.h"

#include <QDebug>

QSelectedShapeCommand::QSelectedShapeCommand(QShape *receiver)
    :QShapeCommand(receiver)
{
}

void QSelectedShapeCommand::execute()
{
    m_shape->setSelected(true);
}
