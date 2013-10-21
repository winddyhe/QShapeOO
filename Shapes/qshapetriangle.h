#ifndef QSHAPETRIANGLE_H
#define QSHAPETRIANGLE_H

#include "qshape.h"

#include <QPoint>
#include <qmath.h>
#include <QPolygon>

class QShapeTriangle : public QShape
{
public:
    QShapeTriangle(QString name);

    void draw(QPainter* painter);

    void move(int x, int y);
    float getArea();
    bool isSelected(QPoint point);
    void save(QDataStream& out);
    void setData(QPoint p[]);

    void update();

protected:
    QPoint m_point[3];
    QPoint m_zoomPoint[3];
};

#endif // QSHAPETRIANGLE_H
