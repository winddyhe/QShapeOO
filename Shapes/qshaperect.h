#ifndef QSHAPERECT_H
#define QSHAPERECT_H

#include "qshape.h"

class QShapeRect : public QShape
{
public:
    QShapeRect(QString name);

    void draw(QPainter* painter);

    void move(int x, int y);
    float getArea();
    bool isSelected(QPoint point);
    void save(QDataStream& out);
    void setData(float topleftX, float topleftY, float width, float height);

    void update();

private:
    float m_topleftX;
    float m_topleftY;
    float m_width;
    float m_height;

    float m_zoomX;
    float m_zoomY;
    float m_zoomW;
    float m_zoomH;
};

#endif // QSHAPERECT_H
