#ifndef QDRAWINTERFACE_H
#define QDRAWINTERFACE_H

#include <QPainter>
#include <QPoint>
#include <QPen>
#include <QBrush>

class QDrawInterface
{
public:
    QDrawInterface();
    virtual ~QDrawInterface() {}
    virtual void drawTriangle(QPoint point[], QPainter* painter) = 0;
    virtual void drawCircle(QPoint center, float radius, QPainter* painter) = 0;
    virtual void drawRect(float topleftX, float topleftY, float width, float height, QPainter* painter) = 0;
    virtual void setShapeSelectedState(bool state) = 0;

    void setLineColor(QColor color);
    void setLineStyle(Qt::PenStyle lineStyle);
    void setUpdateRect(QRect rect);

    QColor  getColor();
    int     getPenStyle();

protected:
    QRect        m_updateRect;
    QColor       m_color;
    Qt::PenStyle m_lineStyle;
    bool         m_isSelected;
};

#endif // QDRAWINTERFACE_H
