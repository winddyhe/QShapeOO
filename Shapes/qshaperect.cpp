#include "qshaperect.h"

#include <QDebug>

QShapeRect::QShapeRect(QString name) :
    QShape(name)
{
    /*random*/
    QTime time = QTime::currentTime();
    qsrand(time.msec() + time.second() * 1000 + time.minute() * 60 * 1000 + time.hour() * 3600 * 1000);

    m_topleftX = qrand() % 600;
    m_topleftY = qrand() % 280 + 50;
    m_width = qrand() % 190 + 10;
    m_height = qrand() % 190 + 10;
    update();
}

void QShapeRect::draw(QPainter* painter)
{
    update();
    m_drawerInterface->drawRect(m_zoomX, m_zoomY, m_zoomW, m_zoomH, painter);
}

void QShapeRect::move(int x, int y)
{
    m_topleftX += x;
    m_topleftY += y;
}

float QShapeRect::getArea()
{
    update();
    return m_zoomW * m_zoomH;
}

bool QShapeRect::isSelected(QPoint point)
{
    update();
    return  (point.x() >= m_zoomX && point.x() <= m_zoomX + m_zoomW) &&
            (point.y() >= m_zoomY && point.y() <= m_zoomY + m_zoomH);
}

void QShapeRect::save(QDataStream& out)
{
    out << m_drawerInterface->getColor().red() << m_drawerInterface->getColor().green()
        << m_drawerInterface->getColor().blue();
    out << m_drawerInterface->getPenStyle();
    out << m_topleftX << m_topleftY << m_width << m_height;
}

void QShapeRect::update()
{
    m_zoomX = m_topleftX - (m_width  * m_sizeRate - m_width) / 2.0f;
    m_zoomY = m_topleftY - (m_height * m_sizeRate - m_height) / 2.0f;
    m_zoomW = m_width  * m_sizeRate;
    m_zoomH = m_height * m_sizeRate;
}

void QShapeRect::setData(float topleftX, float topleftY, float width, float height)
{
    m_topleftX = topleftX;
    m_topleftY = topleftY;
    m_width = width;
    m_height = height;
}

