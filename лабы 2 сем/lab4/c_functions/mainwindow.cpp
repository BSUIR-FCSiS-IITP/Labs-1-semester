
#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 1);
    ui -> label -> setText(s1);
}


void MainWindow::on_pushButton_2_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}



void MainWindow::on_pushButton_3_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    char *s  = strcpy(s1, s2);
    ui -> label_3 -> setText(s);
}



void MainWindow::on_pushButton_4_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_5_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_6_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_7_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_8_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_9_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_10_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_11_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_12_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_13_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_14_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}


void MainWindow::on_pushButton_15_clicked()
{
    char *s1 = "gg";
    const char *s2 = "wp";
    memcmp(s1, s2, 4);
    ui -> label_2 -> setText(s2);
}

