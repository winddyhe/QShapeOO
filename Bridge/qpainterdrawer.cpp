#include "qpainterdrawer.h"

#include <QDebug>

QPainterDrawer::QPainterDrawer()
{
    m_isSelected = false;
}

void QPainterDrawer::drawTriangle(QPoint point[], QPainter* painter)
{
    if(!point)  return;

    if(m_isSelected)
    {
        painter->setPen(QPen(Qt::red, 2, Qt::DotLine));
        painter->drawPolygon(point, 3);
    }
    painter->setPen(QPen(m_color, 1, m_lineStyle));
    painter->drawPolygon(point, 3);
}

void QPainterDrawer::drawCircle(QPoint center, float radius, QPainter* painter)
{
    if(m_isSelected)
    {
        painter->setPen(QPen(Qt::red, 2, Qt::DotLine));
        painter->drawEllipse(QPointF(center), radius, radius);
    }
    painter->setPen(QPen(m_color, 1, m_lineStyle));
    painter->drawEllipse(QPointF(center), radius, radius);
}

void QPainterDrawer::drawRect(float topleftX, float topleftY, float width, float height, QPainter* painter)
{
    if(m_isSelected)
    {
        painter->setPen(QPen(Qt::red, 2, Qt::DotLine));
        painter->drawRect(QRectF(topleftX, topleftY, width, height));
    }

    painter->setPen(QPen(m_color, 1, m_lineStyle));
    painter->drawRect(QRectF(topleftX, topleftY, width, height));
}

void QPainterDrawer::setShapeSelectedState(bool state)
{
    m_isSelected = state;
}
