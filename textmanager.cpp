#include "textmanager.h"

QColor textmanager::changeColor() {
    QColor color = QColorDialog::getColor(Qt::white);
    if(color.isValid()) {
        return color;
    }
}

QFont textmanager::changeFont() {
    bool check;
    QFont font = QFontDialog::getFont(&check);
    if(check) {
        return font;
    }
}
