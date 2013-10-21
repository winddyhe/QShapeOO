#ifndef QCOMMANDSENDER_H
#define QCOMMANDSENDER_H

#include "qshapecommand.h"

#include <QList>

class QCommandSender
{
public:
    QCommandSender();
    ~QCommandSender();

    void addCommand(QShapeCommand* command);
    void cancelCommand();
    void notifyExcuteCurrentCommand();

private:
    QList<QShapeCommand*>* m_commandList;
    QShapeCommand*         m_curCommand;
};

#endif // QCOMMANDSENDER_H
