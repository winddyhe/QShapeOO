#ifndef QSHAPECOMMAND_H
#define QSHAPECOMMAND_H

#include "../Shapes/qshape.h"

#include <QPoint>

class QShapeCommand
{
public:
    QShapeCommand(QShape *receiver);
    virtual ~QShapeCommand() {}

    virtual void execute() = 0;
    void setCommandReceiver(QShape* shape);
    void setPosition(QPoint pos);

protected:
    QShape* m_shape;
    QPoint  m_pos;
};

#endif // QSHAPECOMMAND_H
