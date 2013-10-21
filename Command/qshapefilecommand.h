#ifndef QSHAPEFILECOMMAND_H
#define QSHAPEFILECOMMAND_H

#include "qshapecommand.h"
#include "../Facade/qshapelist.h"

class QShapeFileCommand : public QShapeCommand
{
public:
    enum EFileCommandMode
    {
        EOpenFile,
        ESaveFile
    };

    QShapeFileCommand(QShapeList* receiver, EFileCommandMode fileCommandMode, QString fileName);

    void execute();

private:
    QShapeList*         m_shapeList;
    EFileCommandMode    m_fileCommandModel;
    QString             m_fileName;
};

#endif // QSHAPEFILECOMMAND_H
