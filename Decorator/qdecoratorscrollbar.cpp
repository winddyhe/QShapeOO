#include "qdecoratorscrollbar.h"

QDecoratorScrollBar::QDecoratorScrollBar(QWidget *parent) :
    QDecoratorComponent(parent)
{
    m_scrollArea = NULL;
}

QDecoratorScrollBar::~QDecoratorScrollBar()
{
    m_scrollArea->deleteLater();
}

void QDecoratorScrollBar::createScroolArea()
{
    if(!m_shapeBoard)   return;

    m_scrollArea = new QScrollArea();
    m_scrollArea->setWidget(m_shapeBoard);
    m_scrollArea->viewport()->setBackgroundRole(QPalette::Light);
    m_scrollArea->setAutoFillBackground(true);
    m_scrollArea->setGeometry(200, 200, 803, 485);
    m_scrollArea->show();
}

void QDecoratorScrollBar::Create()
{
    if(m_decorator)
    {
        createScroolArea();
        QDecoratorComponent::Create();
    }
}
