#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checker.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::string s = ui -> textEdit -> toPlainText().toStdString() ;
    std::string s1 = checker::check(s).first;
    int s2 = checker::check(s).second.first;
    int s3 = checker::check(s).second.second;
    ui -> textEdit -> clear();
    if (s1 == "Failed")
    {
        QMessageBox::information(this, "Результат", QString::fromStdString(s1) + "\nСтрока:\n" + QString::number(s2) +
                             "\nСтолбец:\n" + QString::number(s3));

    }
    else
    {
        QMessageBox::information(this, "Результат", QString::fromStdString(s1));

    }
}

