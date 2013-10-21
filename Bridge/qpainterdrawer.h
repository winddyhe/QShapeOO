#ifndef QPAINTERDRAWER_H
#define QPAINTERDRAWER_H

#include "qdrawinterface.h"

class QPainterDrawer : public QDrawInterface
{
public:
    QPainterDrawer();
    void drawTriangle(QPoint point[], QPainter* painter);
    void drawCircle(QPoint center, float radius, QPainter* painter);
    void drawRect(float topleftX, float topleftY, float width, float height, QPainter* painter);
    void setShapeSelectedState(bool state);
};

#endif // QPAINTERDRAWER_H
