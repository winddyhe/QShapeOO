#ifndef QSHAPEBOARD_H
#define QSHAPEBOARD_H

#include <QWidget>
#include <QMainWindow>
#include <QPointer>
#include <QListWidget>
#include <QSplitter>
#include <QLabel>

#include "Facade/qshapelistwidget.h"

class QShapeBoard : public QMainWindow
{
    Q_OBJECT
public:
    QShapeBoard(QWidget *parent = 0);
    ~QShapeBoard();

    void init();
    static QPointer<QShapeBoard> getInstance();

    virtual void Create();
    QShapeListWidget* getShapeListWidget();

private slots:
    void setFocusInShapeListView(QString name);
    void addShapeNameToListObjectWidget(QString name);
    void clearShapeName();

private:
    void createWindowLayout();

protected:
    static void setWidget(QShapeBoard* shapeBoard);

public:
    QLabel              *m_statusLabel;

protected:
    QShapeListWidget    *m_shapeListWidget;
    static QShapeBoard  *m_shapeBoard;
    QListWidget         *m_shapeObjectListWidget;
    QSplitter           *m_mainSplitter;
};

#endif // QSHAPEBOARD_H
