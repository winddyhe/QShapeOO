#ifndef QMOVESHAPECOMMAND_H
#define QMOVESHAPECOMMAND_H

#include "qshapecommand.h"

class QMoveShapeCommand : public QShapeCommand
{
public:
    QMoveShapeCommand(QShape *receiver);
    void execute();
};

#endif // QMOVESHAPECOMMAND_H
