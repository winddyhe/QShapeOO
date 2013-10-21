#include "qcommandsender.h"

QCommandSender::QCommandSender()
{
    m_commandList = new QList<QShapeCommand*>();
}

QCommandSender::~QCommandSender()
{
    if(m_commandList)
    {
        for(int i = 0; i < m_commandList->count(); i++)
        {
            delete m_commandList->at(i);
        }
        m_commandList->clear();
        delete m_commandList;
        m_commandList = NULL;
    }
}

void QCommandSender::addCommand(QShapeCommand* command)
{
    m_curCommand = command;
    m_commandList->append(command);
}

void QCommandSender::notifyExcuteCurrentCommand()
{
    if(!m_curCommand)    return;

    m_curCommand->execute();
}
