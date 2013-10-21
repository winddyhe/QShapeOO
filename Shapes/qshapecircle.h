#ifndef QSHAPECIRCLE_H
#define QSHAPECIRCLE_H

#include "qshape.h"

#include <QPoint>
#include <qmath.h>

class QShapeCircle : public QShape
{
public:
    QShapeCircle(QString name);

    void draw(QPainter* painter);

    void move(int x, int y);
    float getArea();
    bool isSelected(QPoint point);
    void save(QDataStream& out);
    void setData(int radius, int px, int py);

private:
    QPoint m_center;
    int m_radius;
};

#endif // QSHAPECIRCLE_H
