#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <QColor>
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>

class textmanager
{
public:
    textmanager();
    static QColor changeColor();
    static QFont changeFont();
};

#endif // TEXTMANAGER_H
