#ifndef QDECORATORMENU_H
#define QDECORATORMENU_H

#include "qdecoratorcomponent.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QComboBox>
#include <QLabel>

class QDecoratorMenu : public QDecoratorComponent
{
    Q_OBJECT
public:
    explicit QDecoratorMenu(QWidget *parent = 0);
    virtual ~QDecoratorMenu();

    void Create();

private:
    void createActions();
    void createMenu();
    void createToolBar();

protected:
    QMenu*      m_fileMenu;
    QMenu*      m_operatorMenu;
    QMenu*      m_drawMenu;

    QList<QAction*> m_fileActions;
    QList<QAction*> m_operatorActions;
    QList<QAction*> m_drawActions;
    QAction *m_clearAction;

    QLabel*     m_lineLabel;

    QToolBar*   m_operatorToolBar;
    QToolBar*   m_drawToolBar;

    QComboBox*  m_lineComboBox;
};

#endif // QDECORATORMENU_H
