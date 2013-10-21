#include "qshapecircle.h"

#include <QDebug>

QShapeCircle::QShapeCircle(QString name) :
    QShape(name)
{
    /*random the x, y of circle center and radius*/
    QTime time = QTime::currentTime();
    qsrand(time.msec() + time.second() * 1000 + time.minute() * 60 * 1000 + time.hour() * 3600 * 1000);
    m_center.setX(qrand() % 600 + 150);
    m_center.setY(qrand() % 330 + 100);
    m_radius = qrand() % 90 + 10;
}

float QShapeCircle::getArea()
{
    return (2.0f * M_PI * m_radius * m_sizeRate * m_radius * m_sizeRate);
}

void QShapeCircle::draw(QPainter* painter)
{
    m_drawerInterface->drawCircle(m_center, m_radius * m_sizeRate, painter);
}

void QShapeCircle::move(int x, int y)
{
    m_center.setX(m_center.x() + x);
    m_center.setY(m_center.y() + y);
}

bool QShapeCircle::isSelected(QPoint point)
{
    int x = point.x() - m_center.x();
    int y = point.y() - m_center.y();

    return (qSqrt(x*x + y*y) <= m_radius * m_sizeRate);
}

void QShapeCircle::save(QDataStream& out)
{
    out << m_drawerInterface->getColor().red() << m_drawerInterface->getColor().green()
        << m_drawerInterface->getColor().blue();
    out << m_drawerInterface->getPenStyle();
    out << m_radius;
    out << m_center.x() << m_center.y();
}

void QShapeCircle::setData(int radius, int px, int py)
{
    m_radius = radius;
    m_center.setX(px);
    m_center.setY(py);
}
