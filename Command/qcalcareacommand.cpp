#include "qcalcareacommand.h"

QCalcAreaCommand::QCalcAreaCommand(QShape *receiver) :
    QShapeCommand(receiver)
{
}

void QCalcAreaCommand::execute()
{
    float area = m_shape->getArea();

    QMessageBox msgBox;
    msgBox.setWindowTitle("Calculate area");
    msgBox.setText(m_shape->getName() + " area: " + QString::number(area) + "(px^2)");
    msgBox.exec();
}
