#include "qopengldrawer.h"

#include <QDebug>

QOpenglDrawer::QOpenglDrawer()
{
    m_isSelected = false;
}

void QOpenglDrawer::drawTriangle(QPoint point[], QPainter* painter)
{
    Q_UNUSED(painter);
    if (!point) return;

    pushOpenglParameter();

    glBegin(GL_LINE_LOOP);
    glVertex3f(point[0].x(), point[0].y(), 0);
    glVertex3f(point[1].x(), point[1].y(), 0);
    glVertex3f(point[2].x(), point[2].y(), 0);
    glEnd();

    popOpenglParameter();
}

void QOpenglDrawer::drawCircle(QPoint center, float radius, QPainter* painter)
{
    Q_UNUSED(painter);
    pushOpenglParameter();

    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 360; i += 10)
    {
        float x = radius * qCos(i * M_PI / 180.0f);
        float y = radius * qSin(i * M_PI / 180.0f);
        glVertex3f(center.x() + x, center.y() + y, 0.0f);
    }
    glEnd();

    popOpenglParameter();
}

void QOpenglDrawer::drawRect(float topleftX, float topleftY, float width, float height, QPainter* painter)
{
    Q_UNUSED(painter);
    pushOpenglParameter();

    glBegin(GL_LINE_LOOP);
    glVertex3f(topleftX        , topleftY,          0.0f);
    glVertex3f(topleftX + width, topleftY,          0.0f);
    glVertex3f(topleftX + width, topleftY + height, 0.0f);
    glVertex3f(topleftX        , topleftY + height, 0.0f);
    glEnd();

    popOpenglParameter();
}

void QOpenglDrawer::pushOpenglParameter()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, m_updateRect.width(), m_updateRect.height(), 0, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
}

void QOpenglDrawer::popOpenglParameter()
{
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glPopAttrib();
}

void QOpenglDrawer::setShapeSelectedState(bool state)
{
    m_isSelected = state;
}
