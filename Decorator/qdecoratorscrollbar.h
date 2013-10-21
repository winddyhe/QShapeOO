#ifndef QDECORATORSCROLLBAR_H
#define QDECORATORSCROLLBAR_H

#include "qdecoratorcomponent.h"

#include <QScrollArea>

class QDecoratorScrollBar : public QDecoratorComponent
{
    Q_OBJECT
public:
    explicit QDecoratorScrollBar(QWidget *parent = 0);
    virtual ~QDecoratorScrollBar();

    void createScroolArea();
    void Create();

private:
    QScrollArea* m_scrollArea;
};

#endif // QDECORATORSCROLLBAR_H
