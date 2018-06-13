#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

class filemanager
{
public:
    static QString openFile(QString & fileName);
    static void saveFile(QString & fileName, QString & text);
    static void saveAsFile(QString & fileName, QString & text);
};
#endif // FILEMANAGER_H
