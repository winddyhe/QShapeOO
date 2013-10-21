#include "qzoomshapecommand.h"

QZoomShapeCommand::QZoomShapeCommand(QShape *receiver, EZoomType zoomType) :
    QShapeCommand(receiver)
{
    m_zoomType = zoomType;
}

void QZoomShapeCommand::execute()
{
    switch(m_zoomType)
    {
    case EZoomIn:
        m_shape->zoomIn();
        break;
    case EZoomOut:
        m_shape->zoomOut();
        break;
    }
}
