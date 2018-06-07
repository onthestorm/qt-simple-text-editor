#include "filemanager.h"
#include <iostream>

filemanager::filemanager()
{

}

filemanager::filemanager(QTextEdit *te) {
    _te = te;
}

QString filemanager::openFile(QString file) {
    if(!file.isEmpty()) {
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in (&sFile);
            QString text = in.readAll();
            sFile.close();
            return text;
        }
    }
}

void filemanager::saveFile(QString file) {
    QFile sFile(file);
    if(sFile.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&sFile);
        out << _te->toPlainText();
        sFile.flush();
        sFile.close();
    }
}

void filemanager::saveAsFile(QString file) {
    if(!file.isEmpty()) {
       saveFile(file);
    }
}
