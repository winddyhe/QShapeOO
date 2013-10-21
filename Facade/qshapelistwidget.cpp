#include "qshapelistwidget.h"

#include <QDebug>

QShapeListWidget::QShapeListWidget(QWidget *parent) :
    QWidget(parent)
{
    m_shapeList = new QShapeList();
    m_mouseState = ENormalState;
    m_curShape = NULL;

    m_shapeCommandSender = new QCommandSender();
    m_hasShapeCanMoved = false;
}

QShapeListWidget::~QShapeListWidget()
{
    if(m_shapeList)
    {
        delete m_shapeList;
        m_shapeList = NULL;
    }
}

void QShapeListWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);

//    qglColor(Qt::black);

//    QRect rect = e->rect();
//    glViewport(rect.x(), rect.y(), rect.width(), rect.height());
//    m_curShape->getDrawer()->setUpdateRect(rect);
    m_shapeList->draw(&painter);

//    swapBuffers();
}

void QShapeListWidget::createShapeByFactoryMethod(EShapeType type)
{
    m_shapeList->createShapeByFactoryMethod(type);
    update();
}

void QShapeListWidget::createShapeBySimpleFactory(EShapeType type)
{
    m_shapeList->createShapeBySimpleFactory(type);
    update();
}

QString QShapeListWidget::getLastShapeName()
{
    return m_shapeList->getLastShapeName();
}

QShape* QShapeListWidget::searchShapeIsSelected(QPoint point)
{
    return m_shapeList->searchShapeIsSelected(point);
}

void QShapeListWidget::drawCircle()
{
    createShapeByFactoryMethod(eCircle);
    emit addLastShapeNameToListObjectWidget(getLastShapeName());
}

void QShapeListWidget::drawTriangle()
{
    createShapeByFactoryMethod(eTriangle);
    emit addLastShapeNameToListObjectWidget(getLastShapeName());
}

void QShapeListWidget::drawRect()
{
    createShapeByFactoryMethod(eRect);
    emit addLastShapeNameToListObjectWidget(getLastShapeName());
}

void QShapeListWidget::selectedShape(bool checkable)
{
    if(checkable)
    {
        m_mouseState = m_mouseState | ESelectedState;
    }
    else
    {
        m_mouseState = m_mouseState & (~ESelectedState);
    }
}

void QShapeListWidget::moveShape(bool checkable)
{
    if(checkable)
    {
        m_mouseState = m_mouseState | EMoveState;
    }
    else
    {
        m_mouseState = m_mouseState & (~EMoveState);
    }
}

void QShapeListWidget::zoomInShape()
{
    if(m_curShape)
    {
        QShapeCommand* zoomInCommand = new QZoomShapeCommand(m_curShape, QZoomShapeCommand::EZoomIn);
        m_shapeCommandSender->addCommand(zoomInCommand);
        m_shapeCommandSender->notifyExcuteCurrentCommand();
    }
    update();
}

void QShapeListWidget::zoomOutShape()
{
    if(m_curShape)
    {
        QShapeCommand* zoomOutCommand = new QZoomShapeCommand(m_curShape, QZoomShapeCommand::EZoomOut);
        m_shapeCommandSender->addCommand(zoomOutCommand);
        m_shapeCommandSender->notifyExcuteCurrentCommand();
    }
    update();
}

void QShapeListWidget::openColorDialog()
{
    if(m_curShape)
    {
        QColor color = QColorDialog::getColor(Qt::white,this);
        if(color == Qt::white)
        {
            color = QColor(Qt::black);
        }
        QShapeCommand* colorChangeCommand = new QColorChangeCommand(color, m_curShape);
        m_shapeCommandSender->addCommand(colorChangeCommand);
        m_shapeCommandSender->notifyExcuteCurrentCommand();

        update();
    }
}

void QShapeListWidget::lineBoxValueChange(int index)
{
    if(m_curShape)
    {
        Qt::PenStyle penStyle = Qt::SolidLine;
        switch(index)
        {
        case 0:
            penStyle = Qt::SolidLine;
            break;
        case 1:
            penStyle = Qt::DashLine;
            break;
        case 2:
            penStyle = Qt::DotLine;
            break;
        case 3:
            penStyle = Qt::DashDotLine;
            break;
        case 4:
            penStyle = Qt::DashDotDotLine;
            break;
        }
        QShapeCommand* lineStyleChangeCommand = new QLineStyleChangeCommand(penStyle, m_curShape);
        m_shapeCommandSender->addCommand(lineStyleChangeCommand);
        m_shapeCommandSender->notifyExcuteCurrentCommand();

        update();
    }
}

void QShapeListWidget::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr(""), tr("Shapes(*.shape)"));
    if(!fileName.isEmpty())
    {
        QShapeCommand* openFileCommand = new QShapeFileCommand(m_shapeList, QShapeFileCommand::EOpenFile, fileName);
        m_shapeCommandSender->addCommand(openFileCommand);
        m_shapeCommandSender->notifyExcuteCurrentCommand();
    }
    update();
}

void QShapeListWidget::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), tr(""), tr("Shapes(*.shape)"));

    if(!fileName.isEmpty())
    {
        QShapeCommand* saveFileCommand = new QShapeFileCommand(m_shapeList, QShapeFileCommand::ESaveFile, fileName);
        m_shapeCommandSender->addCommand(saveFileCommand);
        m_shapeCommandSender->notifyExcuteCurrentCommand();
    }
    update();
}

void QShapeListWidget::clearShapes()
{
    m_shapeList->clearShapes();
    emit clearShapeNameToListObjectWidget();
    update();
}

void QShapeListWidget::mousePressEvent(QMouseEvent *e)
{
    QPoint p = e->pos();

    if(((m_mouseState & ESelectedState) == ESelectedState))
    {
        m_curShape = searchShapeIsSelected(p);
        if(m_curShape)
        {
            QShapeCommand* selectedCommand = new QSelectedShapeCommand(m_curShape);
            selectedCommand->setPosition(p);
            m_shapeCommandSender->addCommand(selectedCommand);
            m_shapeCommandSender->notifyExcuteCurrentCommand();
            emit setFocusInShapeListObjectWidget(m_curShape->getName());
        }
    }

    if( (m_mouseState & (EMoveState | ESelectedState)) == (EMoveState | ESelectedState) )
    {
        m_curShape = searchShapeIsSelected(p);
        if(m_curShape)
        {
            m_hasShapeCanMoved = true;
            m_prevPressedPoint = p;
        }
    }
    update();
}

void QShapeListWidget::mouseMoveEvent(QMouseEvent *e)
{
    QPoint p = e->pos();
    if(m_hasShapeCanMoved)
    {
        QShapeCommand* moveCommand = new QMoveShapeCommand(m_curShape);
        moveCommand->setPosition(p - m_prevPressedPoint);
        m_shapeCommandSender->addCommand(moveCommand);
        m_shapeCommandSender->notifyExcuteCurrentCommand();
        m_prevPressedPoint = p;
    }
    update();
}

void QShapeListWidget::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    m_hasShapeCanMoved = false;
    m_prevPressedPoint.setX(0);
    m_prevPressedPoint.setY(0);
    update();
}

void QShapeListWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    if(m_curShape)
    {
        QShapeCommand* calcAreaCommand = new QCalcAreaCommand(m_curShape);
        m_shapeCommandSender->addCommand(calcAreaCommand);
        m_shapeCommandSender->notifyExcuteCurrentCommand();
    }
    update();
}
