#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "invaliddatetype.h"
#include "date.h"
#include <string>
#include <QTableWidget>
#include <iomanip>
#include <QTableView>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <regex>



bool check_vis1(int q) {
    if ((q % 4 == 0 && q % 100 != 0) || (q % 400 == 0))
        return true ;
    else
        return false ;
}

Date *birthdaydate = new Date();
std::string birthdaydatestr;

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

int i = 0;
void MainWindow::on_pushButton_4_clicked()
{
    bool flag = 1;
    QString str = ui->lineEdit->text();
    if (str.size()<10)
        flag = 0;
    if (flag)
    {
        if (str[2] != '.' || str[5] != '.' || str.size() > 10)
            flag = 0;
        for (int i = 0;i < str.size(); ++i)
        {
            if (i == 2 || i == 5)
                continue;
            if ((!str[i].isDigit()))
            {
                flag=0;
            }
        }
    }
    if (!flag)
    {
         QMessageBox::warning(this,"Error","Неверный ввод");
    }
    else
    {
        Date *date = new Date();
        QString str2;
        str2.push_back(str[0]);
        str2.push_back(str[1]);
        date->setDay(str2.toInt());
        str2.clear();
        str2.push_back(str[3]);
        str2.push_back(str[4]);
        date->setMonth(str2.toInt());
        str2.clear();
        str2.push_back(str[6]);
        str2.push_back(str[7]);
        str2.push_back(str[8]);
        str2.push_back(str[9]);
        date->setYear(str2.toInt());
        QDate *date11 = new QDate(Date::getYear(date), Date::getMonth(date), Date::getDay(date));
        if (!date11->isValid())
        {
            QMessageBox::warning(this, "Error", "Неверный ввод");
            return ;
        }
        delete date11;
        if (!(Date::getDay(date) == 0 || Date::getMonth(date) == 0))
        {
            ui -> tableWidget -> insertRow(i);
            std::string s1;
            s1 = Date::printDate(date);
            ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(s1)));
            Date *date1 = new Date(Date::NextDay(date));
            s1 = Date::printDate(date1);
            ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(s1)));
            Date *date2 = new Date(Date::PreviousDay(date));
            s1 = Date::printDate(date2);
            ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(s1)));
            bool t = Date::IsLeap(date);
            if (t == 0)
                s1 = "no";
            else
                s1 = "yes";
            ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(s1)));
            s1 = std::to_string(Date::WeekNumber(date));
            ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(s1)));
            int r = Date::DaysTillYourBirthday(date, birthdaydate);
            s1 = std::to_string(r);
            ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 5, new QTableWidgetItem(QString::fromStdString(s1)));
            s1 = std::to_string(Date::Duration(date));
            ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 6, new QTableWidgetItem(QString::fromStdString(s1)));
            ++i;
            ui -> lineEdit -> clear();
        }
        else
            QMessageBox::warning(this, "Error", "Неверный ввод");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    bool flag = 1;
    QString str = ui->lineEdit_2->text();
    if (str.size() < 10)
        flag = 0;
    if (flag)
    {
        if (str[2] != '.' || str[5] != '.' || str.size() > 10)
            flag = 0;
        for (int i = 0;i < str.size(); ++i)
        {
            if (i == 2 || i == 5)
                continue;
            if ((!str[i].isDigit()))
            {
                flag = 0;
            }
        }
    }
    if (!flag)
    {
        QMessageBox::warning(this, "Error", "Неверный ввод");
    }
    else
    {
        QString str = ui -> lineEdit_2 -> text();
        QString str2;
        str2.push_back(str[0]);
        str2.push_back(str[1]);
        birthdaydate->setDay(str2.toInt());
        str2.clear();
        str2.push_back(str[3]);
        str2.push_back(str[4]);
        birthdaydate->setMonth(str2.toInt());
        str2.clear();
        str2.push_back(str[6]);
        str2.push_back(str[7]);
        str2.push_back(str[8]);
        str2.push_back(str[9]);
        birthdaydate->setYear(str2.toInt());
        birthdaydatestr = Date::printDate(birthdaydate);
        ui -> label_4 -> setText(QString::fromStdString(Date::printDate(birthdaydate)));
        for (int j = 0; j < i; ++j)
            {
                QString strr =  ui -> tableWidget->item(j, 0)->text();
                QString str22;
                Date *currentdate = new Date();
                str22.push_back(strr[0]);
                str22.push_back(strr[1]);
                currentdate->setDay(str22.toInt());
                str22.clear();
                str22.push_back(strr[3]);
                str22.push_back(strr[4]);
                currentdate->setMonth(str22.toInt());
                str22.clear();
                str22.push_back(strr[6]);
                str22.push_back(strr[7]);
                str22.push_back(strr[8]);
                str22.push_back(strr[9]);
                currentdate->setYear(str22.toInt());
                int r = Date::DaysTillYourBirthday(currentdate, birthdaydate);
                ui->tableWidget->setItem(j, 5, new QTableWidgetItem(QString::number(r)));
            }
    }
    ui -> lineEdit_2 -> clear();
    ui -> label -> setEnabled(true);
    ui -> lineEdit -> setEnabled(true);
    ui -> pushButton -> setEnabled(true);
    ui -> pushButton_4 -> setEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui -> tableWidget -> setRowCount(0);
    i = 0;
    QMessageBox::information(this, "Info", "Очистка таблицы окончена");
}


void MainWindow::on_pushButton_clicked()
{

    QFile fileName = QFileDialog::getOpenFileName(this,
        tr("Open Text file"), "", tr("Text Files (*.txt)"));
    if (fileName.open(QIODevice::ReadOnly)) {
        QTextStream in(&fileName);
        while (!in.atEnd())
        {
            bool flag = 1;
            QString str;
            in >> str;
            if (str.size()<10)
                flag = 0;
            if (flag)
            {
                if (str[2] != '.' || str[5] != '.' || str.size() > 10)
                    flag = 0;
                for (int i = 0;i < str.size(); ++i)
                {
                    if (i == 2 || i == 5)
                        continue;
                    if ((!str[i].isDigit()))
                    {
                        flag=0;
                    }
                }
            }
            if (!flag)
            {
                 QMessageBox::warning(this,"Error","Неверный ввод, проверьте правильность данных в файле");
                 return;
            }
            else
            {
                Date *date = new Date();
                QString str2;
                str2.push_back(str[0]);
                str2.push_back(str[1]);
                date->setDay(str2.toInt());
                str2.clear();
                str2.push_back(str[3]);
                str2.push_back(str[4]);
                date->setMonth(str2.toInt());
                str2.clear();
                str2.push_back(str[6]);
                str2.push_back(str[7]);
                str2.push_back(str[8]);
                str2.push_back(str[9]);
                date->setYear(str2.toInt());
                QDate *date11 = new QDate(Date::getYear(date), Date::getMonth(date), Date::getDay(date));
                if (!date11->isValid())
                {
                    QMessageBox::warning(this, "Error", "Неверный ввод, проверьте правильность данных в файле");
                    return ;
                }
                delete date11;
                if (!(Date::getDay(date) == 0 || Date::getMonth(date) == 0))
                {
                    ui -> tableWidget -> insertRow(i);
                    std::string s1;
                    s1 = Date::printDate(date);
                    ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(s1)));
                    Date *date1 = new Date(Date::NextDay(date));
                    s1 = Date::printDate(date1);
                    ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(s1)));
                    Date *date2 = new Date(Date::PreviousDay(date));
                    s1 = Date::printDate(date2);
                    ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(s1)));
                    bool t = Date::IsLeap(date);
                    if (t == 0)
                        s1 = "no";
                    else
                        s1 = "yes";
                    ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(s1)));
                    s1 = std::to_string(Date::WeekNumber(date));
                    ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(s1)));
                    int r = Date::DaysTillYourBirthday(date, birthdaydate);
                    s1 = std::to_string(r);
                    ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 5, new QTableWidgetItem(QString::fromStdString(s1)));
                    s1 = std::to_string(Date::Duration(date));
                    ui -> tableWidget -> setItem(ui -> tableWidget->rowCount() - 1, 6, new QTableWidgetItem(QString::fromStdString(s1)));
                    ++i;
                    ui -> lineEdit -> clear();
                }
                else
                {
                    QMessageBox::warning(this, "Error", "Неверный ввод проверьте правильность введенных данных в файле");
                    return;
                }
            }

            }
        }
    QMessageBox::information(this, "Info", "Корректно введенные данные успешно импортированы в таблицу из файла");
}

