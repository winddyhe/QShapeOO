#ifndef QZOOMSHAPECOMMAND_H
#define QZOOMSHAPECOMMAND_H

#include "qshapecommand.h"

class QZoomShapeCommand : public QShapeCommand
{
public:
    enum EZoomType { EZoomIn, EZoomOut };

public:
    QZoomShapeCommand(QShape* receiver, EZoomType zoomType);
    void execute();

private:
    EZoomType   m_zoomType;
};

#endif // QZOOMSHAPECOMMAND_H
