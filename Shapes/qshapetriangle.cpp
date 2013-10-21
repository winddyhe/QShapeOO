#include "qshapetriangle.h"

#include <QDebug>

QShapeTriangle::QShapeTriangle(QString name) :
    QShape(name)
{
    /*random*/
    QTime time = QTime::currentTime();
    qsrand(time.msec() + time.second() * 1000 + time.minute() * 60 * 1000 + time.hour() * 3600 * 1000);

    m_point[0] = QPoint(qrand() % 400 + 200, qrand() % 180 + 200);
    m_point[1] = QPoint(m_point[0].x() + qrand() % 400 - 200, m_point[0].y() + qrand() % 400 - 200);
    m_point[2] = QPoint(m_point[1].x() + qrand() % 400 - 200, m_point[1].y() + qrand() % 400 - 200);

    if(m_point[0].x() == m_point[1].x() && m_point[0].x() == m_point[2].x())
    {
        m_point[1].setX(m_point[1].x() + 50);
    }
    if(m_point[0].y() == m_point[1].y() && m_point[0].y() == m_point[2].y())
    {
        m_point[1].setY(m_point[1].y() + 50);
    }

    update();
}

void QShapeTriangle::move(int x, int y)
{
    for(int i = 0; i < 3; i++)
    {
        m_point[i] += QPoint(x, y);
    }
}

float QShapeTriangle::getArea()
{
    float l = qSqrt(qPow(m_point[0].x() - m_point[1].x(), 2) + qPow(m_point[0].y() - m_point[1].y(), 2));

    QPoint hPoint = (m_point[0] + m_point[1]) / 2.0f;
    float h = qSqrt(qPow(m_point[2].x() - hPoint.x(), 2) + qPow(m_point[2].y() - hPoint.y(), 2));

    return h * l / 2.0f;
}

void QShapeTriangle::draw(QPainter* painter)
{
    update();
    m_drawerInterface->drawTriangle(m_zoomPoint, painter);
}

bool QShapeTriangle::isSelected(QPoint point)
{
    update();
    QPolygon path;
    path << m_zoomPoint[0] << m_zoomPoint[1] << m_zoomPoint[2];
    return path.containsPoint(point, Qt::WindingFill);
}

void QShapeTriangle::save(QDataStream& out)
{
    out << m_drawerInterface->getColor().red() << m_drawerInterface->getColor().green()
        << m_drawerInterface->getColor().blue();
    out << m_drawerInterface->getPenStyle();
    out << m_point[0].x() << m_point[0].y();
    out << m_point[1].x() << m_point[1].y();
    out << m_point[2].x() << m_point[2].y();
}

void QShapeTriangle::setData(QPoint p[])
{
    for(int i = 0; i < 3; i++)
    {
        m_point[i] = p[i];
    }
}

void QShapeTriangle::update()
{
    QPoint p = (m_point[0] + m_point[1] + m_point[2]) / 3.0f;

    for(int i = 0; i < 3; i++)
    {
        m_zoomPoint[i].setX(p.x() - (m_point[i].x() - p.x()) * m_sizeRate);
        m_zoomPoint[i].setY(p.y() - (m_point[i].y() - p.y()) * m_sizeRate);
    }
}
