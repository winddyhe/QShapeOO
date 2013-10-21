#ifndef QLINESTYLECHANGECOMMAND_H
#define QLINESTYLECHANGECOMMAND_H

#include "qshapecommand.h"

class QLineStyleChangeCommand : public QShapeCommand
{
public:
    QLineStyleChangeCommand(Qt::PenStyle penStyle, QShape* receiver);

    void execute();

private:
    Qt::PenStyle m_penStyle;
};

#endif // QLINESTYLECHANGECOMMAND_H
