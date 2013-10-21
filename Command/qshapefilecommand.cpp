#include "qshapefilecommand.h"

QShapeFileCommand::QShapeFileCommand(QShapeList *receiver, EFileCommandMode fileCommandMode, QString fileName):
    QShapeCommand(NULL)
{
    m_shapeList = receiver;
    m_fileCommandModel = fileCommandMode;
    m_fileName = fileName;
}

void QShapeFileCommand::execute()
{
    switch(m_fileCommandModel)
    {
    case ESaveFile:
        m_shapeList->saveToFile(m_fileName);
        break;
    case EOpenFile:
        m_shapeList->loadFromFile(m_fileName);
        break;
    }
}
