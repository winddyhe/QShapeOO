#include "qdrawinterface.h"

QDrawInterface::QDrawInterface()
{
    m_color = Qt::black;
    m_lineStyle = Qt::SolidLine;
}

void QDrawInterface::setUpdateRect(QRect rect)
{
    m_updateRect = rect;
}

void QDrawInterface::setLineColor(QColor color)
{
    m_color = color;
}

void QDrawInterface::setLineStyle(Qt::PenStyle lineStyle)
{
    m_lineStyle = lineStyle;
}


QColor QDrawInterface::getColor()
{
    return m_color;
}

int QDrawInterface::getPenStyle()
{
    return (int)m_lineStyle;
}
