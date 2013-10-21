#include "qdecoratormenu.h"

#include <QDebug>

QDecoratorMenu::QDecoratorMenu(QWidget *parent) :
    QDecoratorComponent(parent)
{
}

QDecoratorMenu::~QDecoratorMenu()
{
}

void QDecoratorMenu::createActions()
{
    if(!m_shapeBoard)   return;

    //! [0]
    QAction *openFileAction = new QAction(QIcon(":/images/open.png"), tr("&Open file"), m_shapeBoard);
    openFileAction->setToolTip("Open a file");
    connect(openFileAction, SIGNAL(triggered()), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(openFile()));
    m_fileActions << openFileAction;

    QAction *saveFileAction = new QAction(QIcon(":/images/save.png"), tr("&Save file"), m_shapeBoard);
    saveFileAction->setToolTip("Save to file");
    connect(saveFileAction, SIGNAL(triggered()), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(saveFile()));
    m_fileActions << saveFileAction;
    //! [0]

    //! [1]
    QAction *drawCircle = new QAction(QIcon(":/images/circle.png"), tr("Draw &Circle"), m_shapeBoard);
    drawCircle->setToolTip("Draw circle");
    connect(drawCircle, SIGNAL(triggered()), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(drawCircle()));
    m_drawActions << drawCircle;

    QAction *drawTriangle = new QAction(QIcon(":/images/triangle.png"), tr("Draw &Triangle"), m_shapeBoard);
    drawTriangle->setToolTip("Draw triangle");
    connect(drawTriangle, SIGNAL(triggered()), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(drawTriangle()));
    m_drawActions << drawTriangle;

    QAction *drawRect = new QAction(QIcon(":/images/rect.png"), tr("Draw &Rect"), m_shapeBoard);
    drawRect->setToolTip("Draw rect");
    connect(drawRect, SIGNAL(triggered()), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(drawRect()));
    m_drawActions << drawRect;
    //! [1]

    //! [2]
    QAction *selectedAction = new QAction(QIcon(":/images/selected.png"), tr("&Selected"), m_shapeBoard);
    selectedAction->setToolTip("Selected action");
    connect(selectedAction, SIGNAL(toggled(bool)), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(selectedShape(bool)));
    selectedAction->setCheckable(true);
    m_operatorActions << selectedAction;

    QAction *moveAction = new QAction(QIcon(":/images/move.png"), tr("&Move"), m_shapeBoard);
    moveAction->setToolTip("Move");
    moveAction->setCheckable(true);
    connect(moveAction, SIGNAL(toggled(bool)), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(moveShape(bool)));
    m_operatorActions << moveAction;

    QAction *zoomInAction = new QAction(QIcon(":/images/zoomin.png"), tr("Zoom &In"), m_shapeBoard);
    zoomInAction->setToolTip("ZoomIn");
    connect(zoomInAction, SIGNAL(triggered()), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(zoomInShape()));
    m_operatorActions << zoomInAction;

    QAction *zoomOutAction = new QAction(QIcon(":/images/zoomout.png"), tr("Zoom &Out"), m_shapeBoard);
    zoomOutAction->setToolTip("ZoomOut");
    connect(zoomOutAction, SIGNAL(triggered()), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(zoomOutShape()));
    m_operatorActions << zoomOutAction;

    QAction *colorAction = new QAction(QIcon(":/images/color.png"), tr("&Color"), m_shapeBoard);
    colorAction->setToolTip("Change Color");
    connect(colorAction, SIGNAL(triggered()), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(openColorDialog()));
    m_operatorActions << colorAction;

    m_lineLabel = new QLabel(m_shapeBoard);
    m_lineLabel->setPixmap(QPixmap(":/images/line.png"));
    m_lineLabel->setToolTip("Change Line");

    m_lineComboBox = new QComboBox(m_shapeBoard);
    QStringList lineStr;
    lineStr << "SolidLine" << "DashLine" << "DotLine" << "DashDotLine" << "DashDotDotLine";
    m_lineComboBox->addItems(lineStr);
    connect(m_lineComboBox, SIGNAL(activated(int)),
           (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(lineBoxValueChange(int)));

    m_clearAction = new QAction(QIcon(":/images/clear.png"), tr("C&lear"), m_shapeBoard);
    m_clearAction->setToolTip("Clear");
    connect(m_clearAction, SIGNAL(triggered()), (QObject*)m_shapeBoard->getShapeListWidget(), SLOT(clearShapes()));
    //! [2]
}

void QDecoratorMenu::createMenu()
{
    if(!m_shapeBoard)   return;

    m_fileMenu = new QMenu(tr("&File"));
    m_fileMenu->addActions(m_fileActions);

    m_drawMenu = new QMenu(tr("&Draw"));
    m_drawMenu->addActions(m_drawActions);

    m_operatorMenu = new QMenu(tr("&Operator"));
    m_operatorMenu->addActions(m_operatorActions);

    m_shapeBoard->menuBar()->addMenu(m_fileMenu);
    m_shapeBoard->menuBar()->addMenu(m_drawMenu);
    m_shapeBoard->menuBar()->addMenu(m_operatorMenu);
}

void QDecoratorMenu::createToolBar()
{
    if(!m_shapeBoard)    return;

    m_drawToolBar = new QToolBar(m_shapeBoard);
    m_drawToolBar->addActions(m_fileActions);
    m_drawToolBar->addSeparator();
    m_drawToolBar->addActions(m_drawActions);

    m_operatorToolBar = new QToolBar(m_shapeBoard);
    m_operatorToolBar->addActions(m_operatorActions);
    m_operatorToolBar->addSeparator();
    m_operatorToolBar->addWidget(m_lineLabel);
    m_operatorToolBar->addWidget(m_lineComboBox);
    m_operatorToolBar->addSeparator();
    m_operatorToolBar->addAction(m_clearAction);

    m_shapeBoard->addToolBar(m_drawToolBar);
    m_shapeBoard->addToolBar(m_operatorToolBar);
}

void QDecoratorMenu::Create()
{
    if(m_decorator)
    {
        qDebug() << "QDecoratorMenu..";
        QDecoratorComponent::Create();
        createActions();
        createMenu();
        createToolBar();
    }
}
