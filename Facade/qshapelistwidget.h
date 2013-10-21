#ifndef QSHAPELISTWIDGET_H
#define QSHAPELISTWIDGET_H

#include "qshapelist.h"
#include "../Command/qcommandsender.h"
#include "../Command/qselectedshapecommand.h"
#include "../Command/qmoveshapecommand.h"
#include "../Command/qzoomshapecommand.h"
#include "../Command/qcolorchangecommand.h"
#include "../Command/qlinestylechangecommand.h"
#include "../Command/qshapefilecommand.h"
#include "../Command/qcalcareacommand.h"

#include <QtOpenGL>
#include <QGLWidget>
#include <QColorDialog>
#include <QFileDialog>

#define ENormalState    0x00
#define ESelectedState  0x01
#define EMoveState      0x02

/**
* Need do: set a popup menu by click right mouse button,
* and display a list of inspective shapes.
**/
class QShapeListWidget : QWidget
{
    Q_OBJECT
public:
    QShapeListWidget(QWidget* parent = 0);
    virtual ~QShapeListWidget();

    void paintEvent(QPaintEvent *e);
    void createShapeBySimpleFactory(EShapeType type);
    void createShapeByFactoryMethod(EShapeType type);
    QString getLastShapeName();
    QShape* searchShapeIsSelected(QPoint point);
    void setSelectedShape(QString name);

signals:
    void addLastShapeNameToListObjectWidget(QString name);
    void setFocusInShapeListObjectWidget(QString name);
    void clearShapeNameToListObjectWidget();

private slots:
    void drawTriangle();
    void drawRect();
    void drawCircle();

    void selectedShape(bool checkable);
    void moveShape(bool checkable);
    void zoomInShape();
    void zoomOutShape();
    void openColorDialog();
    void lineBoxValueChange(int index);
    void openFile();
    void saveFile();
    void clearShapes();

private:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);

private:
    QShapeList* m_shapeList;

    int                  m_mouseState;
    QShape*              m_curShape;
    QPoint               m_mousePosition;

    QCommandSender*      m_shapeCommandSender;
    bool                 m_hasShapeCanMoved;
    QPoint               m_prevPressedPoint;
};

#endif // QSHAPELISTWIDGET_H
