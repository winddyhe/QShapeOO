#include "qdecoratorstatusbar.h"

#include <QDebug>

QDecoratorStatusBar::QDecoratorStatusBar(QWidget *parent) :
    QDecoratorComponent(parent)
{
}

QDecoratorStatusBar::~QDecoratorStatusBar()
{
}

void QDecoratorStatusBar::createStatusBar()
{
    if(!m_shapeBoard)   return;

    m_shapeBoard->m_statusLabel = new QLabel("select: ");
    m_shapeBoard->statusBar()->addWidget(m_shapeBoard->m_statusLabel);
}

void QDecoratorStatusBar::Create()
{
    if(m_decorator)
    {
        createStatusBar();
        qDebug() << "QDecoratorStatusBar..";
        QDecoratorComponent::Create();
    }
}
