#include "filemanager.h"

QString filemanager::openFile(QString &fileName) {
    QString returnText;
    if(!fileName.isEmpty()) {
        QFile sFile(fileName);
        if(sFile.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in (&sFile);
            returnText = in.readAll();
            sFile.close();
        }
    }
    return returnText;
}

void filemanager::saveFile(QString & fileName, QString & text) {
    QFile sFile(fileName);
    if(sFile.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&sFile);
        out << text;
        sFile.flush();
        sFile.close();
    }
}

void filemanager::saveAsFile(QString &fileName, QString &text) {
    if(!fileName.isEmpty()) {
       saveFile(fileName, text);
    }
}
