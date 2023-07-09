#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "vector.h"

Vector<int> a;

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

}


void MainWindow::on_pushButton_2_clicked()
{
    ui -> lineEdit_4 -> setEnabled(true);
    ui -> pushButton_10 -> setEnabled(true);
}


void MainWindow::on_pushButton_10_clicked()
{
    int pos = std::stoi(ui -> lineEdit_4 -> text().toStdString());
    QWidget *mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QLabel *label = new QLabel;
    try {
        int data = a.at(pos);
        label -> setText(QString::number(data));
    }
    catch(...)
    {
        label -> setText("Invalid index error");
    }
    mainLayout->addWidget(label);
    mainWidget->setLayout(mainLayout);
    mainWidget->show();
    ui -> lineEdit_4 -> clear();
    ui -> lineEdit_4 -> setEnabled(false);
    ui -> pushButton_10 -> setEnabled(false);
}


void MainWindow::on_pushButton_3_clicked()
{
    QWidget *mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QLabel *label = new QLabel;
    label -> setText(QString::number(a.capacity()));
    mainLayout->addWidget(label);
    mainWidget->setLayout(mainLayout);
    mainWidget->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    QWidget *mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QLabel *label = new QLabel;
    if (a.size() > 0)
        label -> setText(QString::number(a[0]));
    else
        label -> setText("Vector is empty");
    mainLayout->addWidget(label);
    mainWidget->setLayout(mainLayout);
    mainWidget->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    ui -> lineEdit_5 -> setEnabled(true);
    ui -> pushButton_11 -> setEnabled(true);
}


void MainWindow::on_pushButton_11_clicked()
{
    try {
        a.emplace_back(std::stoi(ui -> lineEdit_5 -> text().toStdString()));
        ui -> lineEdit -> setText(ui -> lineEdit -> text() + ' ' +  QString::number(a[a.size() - 1]));
    } catch (...)
    {
        QWidget *mainWidget = new QWidget;
        QVBoxLayout *mainLayout = new QVBoxLayout;
        QLabel *label = new QLabel;
        label -> setText("Some error occured");
        mainLayout->addWidget(label);
        mainWidget->setLayout(mainLayout);
        mainWidget->show();
    }
    ui -> lineEdit_5 -> clear();
    ui -> lineEdit_5 -> setEnabled(false);
    ui -> pushButton_11 -> setEnabled(false);
}


void MainWindow::on_pushButton_7_clicked()
{
    QWidget *mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QLabel *label = new QLabel;
    label -> setText(QString::number(a.max_size()));
    mainLayout->addWidget(label);
    mainWidget->setLayout(mainLayout);
    mainWidget->show();
}


void MainWindow::on_pushButton_8_clicked()
{
    ui -> lineEdit_6 -> setEnabled(true);
    ui -> pushButton_12 -> setEnabled(true);
}


void MainWindow::on_pushButton_12_clicked()
{
    try {
        a.push_back(std::stoi(ui -> lineEdit_6 -> text().toStdString()));
        ui -> lineEdit -> setText(ui -> lineEdit -> text() + ' ' +  QString::number(a[a.size() - 1]));
    } catch (...)
    {
        QWidget *mainWidget = new QWidget;
        QVBoxLayout *mainLayout = new QVBoxLayout;
        QLabel *label = new QLabel;
        label -> setText("Some error occured");
        mainLayout->addWidget(label);
        mainWidget->setLayout(mainLayout);
        mainWidget->show();
    }
    ui -> lineEdit_6 -> clear();
    ui -> lineEdit_6 -> setEnabled(false);
    ui -> pushButton_12 -> setEnabled(false);
}


void MainWindow::on_pushButton_9_clicked()
{
    Vector<int> b;
    a.swap(b);
    if (ui -> lineEdit -> text() != "")
    {
        ui -> lineEdit_2 -> setText(ui -> lineEdit -> text());
        ui -> lineEdit -> clear();
    }
    else {
        ui -> lineEdit -> setText(ui -> lineEdit_2 -> text());
        ui -> lineEdit_2 -> clear();
    }
}

