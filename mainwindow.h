#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filemanager.h"
#include "textmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionDelete_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

private:
    Ui::MainWindow *ui;
    QString fileName;
};

#endif // MAINWINDOW_H
