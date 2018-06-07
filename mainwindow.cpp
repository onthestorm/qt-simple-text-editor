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
    fileName = ""; // делаем переменную названия файла пустой
    ui->textEdit->setPlainText(""); // делаем textedit пустым
}


void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a file");
    if(!file.isEmpty()) {
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text)) {
            fileName = file;
            QTextStream in (&sFile);
            QString text = in.readAll();
            sFile.close();
            ui->textEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile(fileName);
    if(sFile.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&sFile);
        out << ui->textEdit->toPlainText(); // !!
        sFile.flush();
        sFile.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Save a file");
    if(!file.isEmpty()) {
       fileName = file;
       on_actionSave_triggered();
    }
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
