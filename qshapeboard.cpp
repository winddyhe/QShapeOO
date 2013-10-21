#include "qshapeboard.h"

#include <QDebug>

QShapeBoard* QShapeBoard::m_shapeBoard = NULL;

QShapeBoard::QShapeBoard(QWidget *parent)
    : QMainWindow(parent)
{
    m_shapeListWidget = NULL;
    m_mainSplitter = NULL;
    m_shapeObjectListWidget = NULL;
}

QShapeBoard::~QShapeBoard()
{
    if(m_shapeListWidget)
    {
        delete m_shapeListWidget;
        m_shapeListWidget = NULL;
    }
    m_shapeBoard->deleteLater();
}

void QShapeBoard::init()
{
    createWindowLayout();
    setWidget(this);
}

void QShapeBoard::Create()
{
    qDebug() << "show..";
    show();
}

void QShapeBoard::setWidget(QShapeBoard *shapeBoard)
{
    m_shapeBoard = shapeBoard;
}

void QShapeBoard::createWindowLayout()
{
    m_shapeListWidget = new QShapeListWidget();
    connect((QObject*)m_shapeListWidget, SIGNAL(addLastShapeNameToListObjectWidget(QString)),
            this,              SLOT(addShapeNameToListObjectWidget(QString)));
    connect((QObject*)m_shapeListWidget, SIGNAL(setFocusInShapeListObjectWidget(QString)), this, SLOT(setFocusInShapeListView(QString)));
    connect((QObject*)m_shapeListWidget, SIGNAL(clearShapeNameToListObjectWidget()), this, SLOT(clearShapeName()));

    m_shapeObjectListWidget = new QListWidget();
    m_shapeObjectListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    m_mainSplitter = new QSplitter(Qt::Horizontal);
    m_mainSplitter->addWidget((QWidget*)m_shapeListWidget);
    m_mainSplitter->addWidget(m_shapeObjectListWidget);
    m_mainSplitter->setStretchFactor(0, 60);
    m_mainSplitter->setStretchFactor(1, 40);

    setCentralWidget(m_mainSplitter);
    setWindowTitle("ShapeOO");
    setGeometry(100, 200, 800, 480);
}

void QShapeBoard::setFocusInShapeListView(QString name)
{
    for(int i = m_shapeObjectListWidget->count() - 1; i >= 0 ; i--)
    {
        if(m_shapeObjectListWidget->item(i)->text() == name)
        {
            m_shapeObjectListWidget->setCurrentRow(i);
            m_shapeObjectListWidget->currentItem()->setSelected(true);
            m_statusLabel->setText("select: " + name);
            break;
        }
    }
}

void QShapeBoard::clearShapeName()
{
    m_shapeObjectListWidget->clear();
}

void QShapeBoard::addShapeNameToListObjectWidget(QString name)
{
    m_shapeObjectListWidget->addItem(name);
}

QShapeListWidget* QShapeBoard::getShapeListWidget()
{
    return m_shapeListWidget;
}
