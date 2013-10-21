#ifndef QSELECTEDSHAPECOMMAND_H
#define QSELECTEDSHAPECOMMAND_H

#include "qshapecommand.h"

#include <QPoint>

class QSelectedShapeCommand : public QShapeCommand
{
public:
    QSelectedShapeCommand(QShape* receiver);
    void execute();
};

#endif // QSELECTEDSHAPECOMMAND_H
