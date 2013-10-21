#ifndef QDECORATORSTATUSBAR_H
#define QDECORATORSTATUSBAR_H

#include "qdecoratorcomponent.h"

#include <QStatusBar>
#include <QLabel>

class QDecoratorStatusBar : public QDecoratorComponent
{
    Q_OBJECT
public:
    explicit QDecoratorStatusBar(QWidget *parent = 0);
    virtual ~QDecoratorStatusBar();

    void Create();

protected:
    void createStatusBar();
};

#endif // QDECORATORSTATUSBAR_H
