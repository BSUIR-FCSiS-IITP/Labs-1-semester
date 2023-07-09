#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector.h"
#include "pair.h"
#include <QString>
#include <iostream>

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
   ui -> label -> clear();
   ui -> label_2 -> clear();
   Pair<Vector<int>, Vector<Pair<int, int>>> a;
   int value = rand() * 100;
   for (int j = 0; j < 5; ++j) {
       for (int i = 0; i < 5; ++i)
       {
           value = (value * 731 + 951) % 2000;
           a.first.push_back(value);
           ui->label->setText(ui->label->text() + QString::number(a.first.back()) + " ");
       }
       ui->label->setText(ui->label->text() + '\n');
   }
   for (int j = 0; j < 5; ++j)
   {
       for (int i = 0; i < 2; ++i)
       {
           value = (value * 421 + 693) % 2000;
           int value1 = (value * 517 - 421) % 2000;
           Pair<int, int> buff = Pair<int, int>::make_pair(value, value1);
           a.second.push_back(buff);
           ui->label_2->setText(ui->label_2->text() + QString::number(a.second.back().first) + "," + QString::number(a.second.back().second) + " ");
       }
       ui->label_2->setText(ui->label_2->text() + '\n');
   }
}

