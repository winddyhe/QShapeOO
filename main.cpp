#include <QtWidgets/QApplication>

#include "qshapeboard.h"
#include "Decorator/qdecoratorcomponent.h"
#include "Decorator/qdecoratormenu.h"
#include "Decorator/qdecoratorstatusbar.h"
#include "Decorator/qdecoratorscrollbar.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*Decorator Pattern*/
    QShapeBoard shapeBoard;
    shapeBoard.init();
    QDecoratorMenu menuShapeBoard;
    QDecoratorStatusBar statusBarShapeBoard;
    QDecoratorScrollBar scrollBarShapeBoard;

//    scrollBarShapeBoard.decorator(statusBarShapeBoard.decorator(menuShapeBoard.decorator(&shapeBoard)));
//    scrollBarShapeBoard.Create();

    menuShapeBoard.decorator(statusBarShapeBoard.decorator(scrollBarShapeBoard.decorator(&shapeBoard)));
    menuShapeBoard.Create();

    return a.exec();
}
