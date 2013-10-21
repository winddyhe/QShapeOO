#ifndef QSHAPELIST_H
#define QSHAPELIST_H

#include "../Shapes/qshape.h"
#include "../Factory/qshapesimplefactory.h"
#include "../Factory/qshapefactorymethod.h"
#include "../Factory/qtrianglefactory.h"
#include "../Factory/qcirclefactory.h"
#include "../Factory/qrectfactory.h"

#include "../Bridge/qopengldrawer.h"
#include "../Bridge/qpainterdrawer.h"

#include <QVector>
#include <QFile>
#include <QDataStream>

class QShapeList
{
public:
    QShapeList();
    ~QShapeList();

    void addShape(QShape* shape, EShapeType type);
    void draw(QPainter* painter);
    void createShapeBySimpleFactory(EShapeType type);
    void createShapeByFactoryMethod(EShapeType type);
    QString getLastShapeName();
    QShape* searchShapeIsSelected(QPoint point);
    void setUpdateRect(QRect rect);
    void clearShapes();

    void saveToFile(QString fileName);
    void loadFromFile(QString fileName);

private:
    QVector<QShape*>        m_shapeList;

    QShapeSimpleFactory*    m_shapeSimpleFactory;
    QShapeFactoryMethod*    m_shapeFactoryMethod;

    int m_shapeCount;
};

#endif // QSHAPELIST_H
