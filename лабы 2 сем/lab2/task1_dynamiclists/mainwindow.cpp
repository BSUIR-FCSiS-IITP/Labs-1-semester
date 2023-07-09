#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "libs.h"
#include "bus.h"
#include "list.h"
#include "search.h"



bool time(std::string const &str)
{
    return std::regex_match(str, std::regex("^(([0,1][0-9])|(2[0-3])):[0-5][0-9]$")) ;
}


List a;

int j = 0;


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


void MainWindow::on_pushButton_3_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui -> tableWidget -> setRowCount(0);
    while (a.head != nullptr)
    {
        a.pop_front();
        --j;
    }
}



void MainWindow::on_pushButton_clicked()
{
    if (ui -> lineEdit -> text() == "" || ui -> lineEdit_2 -> text() == "" || ui -> lineEdit_3 -> text() == "" ||
            ui -> lineEdit_4 -> text() == "" || ui -> lineEdit_5 -> text() == "")
    {
        QMessageBox::warning(this, "Error", "Не оставляй поля пустыми");
        ui -> lineEdit -> clear();
        ui -> lineEdit_2 -> clear();
        ui -> lineEdit_3 -> clear();
        ui -> lineEdit_4 -> clear();
        ui -> lineEdit_5 -> clear();
        return;
    }
    if (!time(ui->lineEdit_4->text().toStdString()) || !time(ui->lineEdit_5->text().toStdString()))
    {
        QMessageBox::warning(this, "Error", "Введи время в формате HH:MM");
        ui -> lineEdit_4 -> clear();
        ui -> lineEdit_5 -> clear();
        return;
    }
    else
    {
        Bus q;
        q.number = ui -> lineEdit -> text();
        q.type = ui -> lineEdit_2 -> text();
        q.point = ui -> lineEdit_3 -> text();
        q.time1 = ui -> lineEdit_4 -> text();
        q.time2 = ui -> lineEdit_5 -> text();
        a.push_back(q);
        ui -> tableWidget -> insertRow(j);
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount() - 1, 0, new QTableWidgetItem(ui -> lineEdit -> text()));
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount() - 1, 1, new QTableWidgetItem(ui -> lineEdit_2 -> text()));
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount() - 1, 2, new QTableWidgetItem(ui -> lineEdit_3 -> text()));
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount() - 1, 3, new QTableWidgetItem(ui -> lineEdit_4 -> text()));
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount() - 1, 4, new QTableWidgetItem(ui -> lineEdit_5 -> text()));
        ++j;
        ui -> lineEdit -> clear();
        ui -> lineEdit_2 -> clear();
        ui -> lineEdit_3 -> clear();
        ui -> lineEdit_4 -> clear();
        ui -> lineEdit_5 -> clear();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    try {
        if (j == 0){
            QMessageBox::critical (this, "error", "Конфуций:\n"
                                                  "Когда ничего нет, то и терять нечего");
            return;
        }
        else if (j == 1){
            ui->tableWidget->setRowCount(0);
            a.pop_back();
            j = 0;
        }
        else
        {
            QTableWidget* tableWidget = findChild<QTableWidget*>("tableWidget");
            QList<QTableWidgetItem*> selectedItems = tableWidget->selectedItems();
            QSet<int> rows;
            foreach (QTableWidgetItem* item, selectedItems)
                rows.insert(item->row());
            QList<int> sortedRows = rows.toList();
            qSort(sortedRows);

            for (int i = sortedRows.count() - 1; i >= 0; i--)
                tableWidget->removeRow(sortedRows.at(i));
            if (j == 0)
                throw "error";
            --j;
        }
        ui -> tableWidget -> show();
    }

    catch(...){
        QMessageBox::critical(this, "error", "А что ты удалять то собрался");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    Search search(this, this);
    search.setModal(true);
    search.exec();
}

