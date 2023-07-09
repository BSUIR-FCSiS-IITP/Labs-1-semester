#include "mainwindow.h"
#include "search.h"
#include "ui_mainwindow.h"
#include "list.cpp"
#include "libs.h"
#include "bus.h"
#include "ui_search.h"

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

list <Bus> trips;

int count = 0;

void MainWindow::on_add_clicked()
{

    Bus new_trip;
    try
    {
        new_trip.set_number(ui -> lineEdit -> text());
        new_trip.set_type(ui -> lineEdit_2 -> text());
        new_trip.set_destination(ui -> lineEdit_3 -> text());
        new_trip.set_time_dispatch(ui -> lineEdit_4 -> text());
        new_trip.set_time_arrive(ui -> lineEdit_5 -> text());
        ui -> listWidget -> addItem(new_trip.get_number() + "\t" + new_trip.get_type() + "\t" + new_trip.get_destination() + "\t" + new_trip.get_time_dispatch() + '\t' + new_trip.get_time_arrive().toString("HH:mm"));
        trips.push_back(new_trip);
    }
    catch(...){
        QMessageBox::critical(this, "error", "Ошибка");
    }
    ui -> lineEdit -> clear();
    ui -> lineEdit_2 -> clear();
    ui -> lineEdit_3 -> clear();
    ui -> lineEdit_4 -> clear();
    ui -> lineEdit_5 -> clear();
}


void MainWindow::on_clear_clicked()
{
    if (trips.size() == 0) QMessageBox::information(this,"info", "Блин, все пусто");
    else{
        ui -> listWidget -> clear();
        trips.clear();
    }
}


void MainWindow::on_delete_2_clicked()
{
    try{
        if (trips.size() == 0){
            QMessageBox::critical (this, "error", "Конфуций:\n"
                                                  "Когда ничего нет, то и терять нечего");
        }
        else if (trips.size() == 1){
            ui -> listWidget -> clear();
            trips.clear();
        }
        else{
            ui -> listWidget ->takeItem(ui->listWidget->currentRow());
            int number = ui -> listWidget -> currentRow();
            if (number == -1){
                throw "error";
            }
            trips.erase(number - 1);
        }
        ui -> listWidget -> show();
    }
    catch(...){
        QMessageBox::critical(this, "error", "Выберите элемент для удаления:)");
    }
}

void MainWindow::on_searching_clicked()
{
    if (trips.size() == 0)
        QMessageBox::warning(this, "Error", "Сори, ниче там нет, не пытайся");
    else {
        searchwindow = new class search;
        searchwindow -> setWindowTitle("Поиск");
        searchwindow -> show();
    }
}

void search::on_pushButton_clicked()
{
    try{
        QString time = ui -> lineEdit -> text();
        QTime time_arrive = QTime::fromString(time);
        if (!time_arrive.isValid())
            throw "error";
        QString destination = ui -> lineEdit_2 -> text();
        int count = 0;
        for (int i = 0; i < trips.size(); i ++)
        {
            if (trips[i].get_time_arrive() <= time_arrive && trips[i].get_destination().toLower() == destination.toLower())
            {
                count ++;
                ui -> listWidget -> addItem(trips[i].get_number() + "\t" + trips[i].get_type() + "\t" + trips[i].get_destination() + "\t" + trips[i].get_time_dispatch() + '\t' + trips[i].get_time_arrive().toString("HH:mm"));
            }
        }
        if (!count) QMessageBox::information(this, "info", "Ничего не нашел:(");
    }
    catch(...){
        QMessageBox::critical(this, "error", "Что-то пошло не по плану");
    }
    ui -> lineEdit -> clear();
    ui -> lineEdit_2 -> clear();
}
