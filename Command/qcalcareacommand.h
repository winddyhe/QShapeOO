#ifndef QCALCAREACOMMAND_H
#define QCALCAREACOMMAND_H

#include "qshapecommand.h"

#include <QMessageBox>

class QCalcAreaCommand : public QShapeCommand
{
public:
    QCalcAreaCommand(QShape* receiver);

    void execute();

private:
    float m_area;
};

#endif // QCALCAREACOMMAND_H
