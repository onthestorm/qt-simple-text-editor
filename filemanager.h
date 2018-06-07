#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QFontDialog>
#include <QColorDialog>
#include <QFont>
#include <QTextCharFormat>

class filemanager
{
private:
    QTextEdit * _te;
public:
    filemanager();
    filemanager(QTextEdit *te);
    static QString openFile(QString file);
    void saveFile(QString file);
    void saveAsFile(QString file);
};
#endif // FILEMANAGER_H
