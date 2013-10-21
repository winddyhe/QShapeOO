#include "qshapelist.h"

#include <QDebug>

QShapeList::QShapeList()
{
    m_shapeSimpleFactory = new QShapeSimpleFactory();
    m_shapeFactoryMethod = NULL;
    m_shapeCount = 0;
}

QShapeList::~QShapeList()
{
    foreach(QShape* shape, m_shapeList)
    {
        delete shape;
    }
    m_shapeList.clear();

    if(m_shapeSimpleFactory)
    {
        delete m_shapeSimpleFactory;
        m_shapeSimpleFactory = NULL;
    }

    if(m_shapeFactoryMethod)
    {
        delete m_shapeFactoryMethod;
        m_shapeFactoryMethod = NULL;
    }
}

void QShapeList::draw(QPainter* painter)
{
    foreach(QShape* shape, m_shapeList)
    {
        shape->draw(painter);
    }
}

void QShapeList::addShape(QShape *shape, EShapeType type)
{
    QDrawInterface *drawer = new QPainterDrawer();
    //QDrawInterface *drawer = new QOpenglDrawer();
    shape->setDrawer(drawer);
    shape->setType(type);
    m_shapeList.append(shape);
}

void QShapeList::createShapeBySimpleFactory(EShapeType type)
{
    m_shapeCount++;
    QString name;

    switch(type)
    {
    case eTriangle:
        name = QString("triangle") + QString::number(m_shapeCount);
        break;
    case eRect:
        name = QString("rect") + QString::number(m_shapeCount);
        break;
    case eCircle:
        name = QString("circle") + QString::number(m_shapeCount);
        break;
    }

    QShape *shape = m_shapeSimpleFactory->createShape(name, type);
    addShape(shape, type);
}

void QShapeList::createShapeByFactoryMethod(EShapeType type)
{
    QShape *shape = NULL;
    m_shapeCount++;
    QString name;

    switch(type)
    {
    case eTriangle:
        name = QString("triangle") + QString::number(m_shapeCount);
        m_shapeFactoryMethod = new QTriangleFactory();
        shape = m_shapeFactoryMethod->createShape(name);
        addShape(shape, type);
        delete m_shapeFactoryMethod;
        m_shapeFactoryMethod = NULL;
        break;

    case eRect:
        name = QString("rect") + QString::number(m_shapeCount);
        m_shapeFactoryMethod = new QRectFactory();
        shape = m_shapeFactoryMethod->createShape(name);
        addShape(shape, type);
        delete m_shapeFactoryMethod;
        m_shapeFactoryMethod = NULL;
        break;

    case eCircle:
        name = QString("circle") + QString::number(m_shapeCount);
        m_shapeFactoryMethod = new QCircleFactory();
        shape = m_shapeFactoryMethod->createShape(name);
        addShape(shape, type);
        delete m_shapeFactoryMethod;
        m_shapeFactoryMethod = NULL;
        break;
    }
}

QString QShapeList::getLastShapeName()
{
    if (m_shapeList.count() == 0)   return "";

    return m_shapeList.last()->getName();
}

QShape* QShapeList::searchShapeIsSelected(QPoint point)
{
    QShape* result = NULL;
    for(int i = m_shapeList.count() - 1; i >= 0; i--)
    {
        if(m_shapeList.at(i)->isSelected(point))
        {
            result = m_shapeList.at(i);
        }
    }

    /*修复Shape重复相交的地方*/
    for(int i = 0; i < m_shapeList.count(); i++)
    {
        if(m_shapeList.at(i) != result)
        {
            m_shapeList.at(i)->setSelected(false);
        }
    }
    return result;
}

void QShapeList::setUpdateRect(QRect rect)
{
    Q_UNUSED(rect);
}

void QShapeList::clearShapes()
{
    for(int i = 0; i < m_shapeList.count(); i++)
    {
        delete m_shapeList.at(i);
    }
    m_shapeList.clear();
}

void QShapeList::saveToFile(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "File open failed!";
        return;
    }

    QDataStream out(&file);
    for(int i = 0; i < m_shapeList.count(); i++)
    {
        out << m_shapeList.at(i)->getType();
        out << m_shapeList.at(i)->getName();
        out << m_shapeList.at(i)->getSizeRate();
        m_shapeList.at(i)->save(out);
    }
    file.close();
    QMessageBox msgBox;
    msgBox.setWindowTitle("Save File");
    msgBox.setText("Save success!");
    msgBox.exec();
}

void QShapeList::loadFromFile(QString fileName)
{
    QFile file(fileName);
    QShape* shape;
    QDrawInterface* drawerInterface;
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "File open failed!";
        return;
    }

    QDataStream in(&file);

    int     type = -1;
    QString name;
    float   sizeRate = 0.0f;
    int     red, green, blue;
    int     lineStyle;
    int px, py, radius;
    QPoint p[3];
    float topleftX, topleftY, width, height;

    if(!in.atEnd())
    {
        clearShapes();
    }

    while(!in.atEnd())
    {
        in >> type;
        in >> name;
        in >> sizeRate;
        in >> red >> green >> blue;
        in >> lineStyle;

        switch(type)
        {
        case 0:
            shape = new QShapeTriangle(name);
            shape->setType((EShapeType)type);
            drawerInterface = new QPainterDrawer();
            drawerInterface->setLineColor(QColor(red, green, blue));
            drawerInterface->setLineStyle((Qt::PenStyle)lineStyle);
            shape->setDrawer(drawerInterface);
            in >> px >> py;
            p[0].setX(px);  p[0].setY(py);

            in >> px >> py;
            p[1].setX(px);  p[1].setY(py);

            in >> px >> py;
            p[2].setX(px);  p[2].setY(py);
            shape->setData(p);
            break;

        case 1:
            shape = new QShapeRect(name);
            shape->setType((EShapeType)type);
            drawerInterface = new QPainterDrawer();
            drawerInterface->setLineColor(QColor(red, green, blue));
            drawerInterface->setLineStyle((Qt::PenStyle)lineStyle);
            shape->setDrawer(drawerInterface);

            in >> topleftX >> topleftY >> width >> height;
            shape->setData(topleftX, topleftY, width, height);
            break;

        case 2:
            shape = new QShapeCircle(name);
            shape->setType((EShapeType)type);
            drawerInterface = new QPainterDrawer();
            drawerInterface->setLineColor(QColor(red, green, blue));
            drawerInterface->setLineStyle((Qt::PenStyle)lineStyle);
            shape->setDrawer(drawerInterface);

            in >> radius;
            in >> px >> py;
            shape->setData(radius, px, py);
            break;
        default:
            break;
        }
        m_shapeList.append(shape);
    }
}

