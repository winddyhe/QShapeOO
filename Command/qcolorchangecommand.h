#ifndef QCOLORCHANGECOMMAND_H
#define QCOLORCHANGECOMMAND_H

#include "qshapecommand.h"

#include <QColor>

class QColorChangeCommand : public QShapeCommand
{
public:
    QColorChangeCommand(QColor color, QShape* receiver);
    void execute();

private:
    QColor m_color;
};

#endif // QCOLORCHANGECOMMAND_H
