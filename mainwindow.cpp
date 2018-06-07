#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit); // ставим textedit центральным виджетом
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
    fileName = QFileDialog::getOpenFileName(this, "Open a file");
    ui->textEdit->setPlainText(filemanager::openFile(fileName));
}

void MainWindow::on_actionSave_triggered()
{
    filemanager file(ui->textEdit);
    file.saveFile(fileName);
}

void MainWindow::on_actionSave_as_triggered()
{
    fileName = QFileDialog::getSaveFileName(nullptr, "Save a file");
    filemanager file(ui->textEdit);
    file.saveAsFile(fileName);
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
    bool check;
    QFont font = QFontDialog::getFont(&check, this);
    if(check) {
        ui->textEdit->setFont(font);
    }
}

void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    if(color.isValid()) {
        ui->textEdit->setTextColor(color);
    }
}
