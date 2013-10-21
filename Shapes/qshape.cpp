#include "qshape.h"

QShape::QShape(QString name)
{
    m_name = name;
    m_sizeRate = 1.0f;
}

QShape::~QShape()
{
    if(m_drawerInterface)
    {
        delete m_drawerInterface;
        m_drawerInterface = NULL;
    }
}

void QShape::draw(QPainter* painter)
{
    Q_UNUSED(painter);
}

void QShape::setName(QString name)
{
    m_name = name;
}

QString QShape::getName()
{
    return m_name;
}

void QShape::setDrawer(QDrawInterface *drawer)
{
    m_drawerInterface = drawer;
}

QDrawInterface* QShape::getDrawer()
{
    return m_drawerInterface;
}

void QShape::setType(EShapeType shapeType)
{
    m_shapeType = shapeType;
}

int QShape::getType()
{
    return (int)m_shapeType;
}

float QShape::getSizeRate()
{
    return m_sizeRate;
}

float QShape::getArea()
{
    return 0.0f;
}

bool QShape::isSelected(QPoint point)
{
    Q_UNUSED(point);
    return false;
}

void QShape::move(int x, int y)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
}

void QShape::zoomIn()
{
    m_sizeRate += 0.2f;
    if(m_sizeRate >= 3.0f)
    {
        m_sizeRate = 3.0f;
    }
}

void QShape::zoomOut()
{
    m_sizeRate -= 0.2f;
    if(m_sizeRate <= 0.4f)
    {
        m_sizeRate = 0.4f;
    }
}

void QShape::setLineColor(QColor color)
{
    m_drawerInterface->setLineColor(color);
}

void QShape::setLineType(Qt::PenStyle penStyle)
{
    m_drawerInterface->setLineStyle(penStyle);
}

void QShape::save(QDataStream& out)
{
    Q_UNUSED(out);
}

void QShape::setSelected(bool isSelected)
{
    m_drawerInterface->setShapeSelectedState(isSelected);
}

void QShape::setData(QPoint p[])
{
    Q_UNUSED(p);
}

void QShape::setData(int radius, int px, int py)
{
    Q_UNUSED(radius);
    Q_UNUSED(px);
    Q_UNUSED(py);
}

void QShape::setData(float topleftX, float topleftY, float width, float height)
{
    Q_UNUSED(topleftX);
    Q_UNUSED(topleftY);
    Q_UNUSED(width);
    Q_UNUSED(height);
}
