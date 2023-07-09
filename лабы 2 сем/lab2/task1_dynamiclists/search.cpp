#include "search.h"
#include "ui_search.h"
#include "mainwindow.h"
#include "libs.h"

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}


Search::Search(QWidget *parent, MainWindow *mainWindow) :
    QDialog(parent),
    ui(new Ui::Search),
    mainWindow(mainWindow)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_clicked()
{
    QDialog *mainWidget = new QDialog;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QLabel *label = new QLabel;
    QTableWidget *table = new QTableWidget;
    QHeaderView* headerView = table->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::ResizeToContents);

    table->setColumnCount(5);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Номер"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Тип"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Пункт назначения"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Время отправления"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Время прибытия"));
    table->setEditTriggers(QTableWidget::NoEditTriggers);
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Не оставляй пустыми");
        return;
    }

    QTableWidget *tableWidget = mainWindow->findChild<QTableWidget*>("tableWidget");
    bool found = false;
    for (int i = 0; i < tableWidget->rowCount(); ++i)
    {
        if (tableWidget->item(i, 2)->text().toLower() == ui->lineEdit->text().toLower())
        {
            found = true;
            tableWidget->setCurrentCell(i, 0);
            break;
        }
    }
    if (!found)
    {
        QMessageBox::warning(this, "Error", "Ничего не найдено");
        QDialog::close();
    }
    else
    {
        int r = 0;
        label->setText("Подходящие рейсы:\n\n"
                       "Номер          Тип\tПункт назначения\tВремя отправления\tВремя прибытия\n"
                       "-----------------------------------------------------------------\n");
        for (int i = 0; i < tableWidget -> rowCount(); ++i)
        {
            if (tableWidget->item(i, 2)->text().toLower() == ui->lineEdit->text().toLower() &&
                    tableWidget->item(i, 4)->text().toLower() <= ui->lineEdit_2->text().toLower())
            {
                table->insertRow(r);
                table->setItem(r, 0, new QTableWidgetItem(tableWidget->item(i, 0)->text()));
                table->setItem(r, 1, new QTableWidgetItem(tableWidget->item(i, 1)->text()));
                table->setItem(r, 2, new QTableWidgetItem(tableWidget->item(i, 2)->text()));
                table->setItem(r, 3, new QTableWidgetItem(tableWidget->item(i, 3)->text()));
                table->setItem(r, 4, new QTableWidgetItem(tableWidget->item(i, 4)->text()));
                ++r;
            }
        }
        if (!r)
        {
            QMessageBox::warning(this, "Error", "Сори, таких маршрутов нет");
            return;
        }
        else
        {
            mainLayout->addWidget(table);
            mainWidget->setLayout(mainLayout);
            mainWidget->resize(800, 600);
            mainWidget->exec();
            QDialog::close();
        }
    }
}
