#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->setPlainText("");
    fileName = "";
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file");
    ui->textEdit->setPlainText(filemanager::openFile(fileName));
}

void MainWindow::on_actionSave_triggered()
{
    QString text = ui->textEdit->toPlainText();
    filemanager::saveFile(fileName, text);
}

void MainWindow::on_actionSave_as_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, "Save a file");
    QString text = ui->textEdit->toPlainText();
    filemanager::saveAsFile(fileName, text);
}

void MainWindow::on_actionExit_triggered()
{
    QWidget::close();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionDelete_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_actionFont_triggered()
{
    ui->textEdit->setFont(textmanager::changeFont());
}

void MainWindow::on_actionColor_triggered()
{
    ui->textEdit->setTextColor(textmanager::changeColor());
}
