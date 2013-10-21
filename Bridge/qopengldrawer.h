#ifndef QOPENGLDRAWER_H
#define QOPENGLDRAWER_H

#include "qdrawinterface.h"

#include <QtOpenGL>
#include <qmath.h>

class QOpenglDrawer : public QDrawInterface
{
public:
    QOpenglDrawer();
    void drawTriangle(QPoint point[], QPainter* painter);
    void drawCircle(QPoint center, float radius, QPainter* painter);
    void drawRect(float topleftX, float topleftY, float width, float height, QPainter* painter);
    void setShapeSelectedState(bool state);

private:
    void pushOpenglParameter();
    void popOpenglParameter();
};

#endif // QOPENGLDRAWER_H
