#include "task2.h"
#include "ui_task2.h"
#include <QFile>
#include <QTextStream>
#include <QString>

Task2::Task2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task2)
{
    ui->setupUi(this);
}

Task2::~Task2()
{
    delete ui;
}

void *qs11(football *a, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        QString middle = a[(left + right) / 2].foals;
        do {
            while (a[left].foals < middle)
                ++left;
            while (a[right].foals > middle)
                --right;
            if (left <= right) {
                football temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                ++left;
                --right;
            }
        } while (left < right);
        qs11(a, first, right);
        qs11(a, left, last);
    }
}

void Task2::on_pushButton_clicked()
{
    QFile file("C://Users//reshe//Documents//untitled4//work.txt");
    file.open(QIODevice::ReadWrite);
    int n = 0;
    QString line;
    QTextStream in(&file);
    while(!in.atEnd())
    {
        line = in.readLine();
        if (line != 0)
            n++;
    }
    n /= 5;
    football *a = new football [n];
    QTextStream q(&file);
    int i = 0;
    q.seek(0);
    while (!q.atEnd())
    {
       a[i].name = q.readLine().toUtf8();
       a[i].club = q.readLine().toUtf8();
       a[i].type = q.readLine().toUtf8();
       a[i].goals = q.readLine().toUtf8();
       a[i].foals = q.readLine().toUtf8();
       ++i;
    }
    qs11(a, 0, n - 1);
    QWidget *mainWidget1 = new QWidget;
    QVBoxLayout *mainLayout1 = new QVBoxLayout;
    QLabel *label1 = new QLabel;
    if (n != 0) {
        QString data;
        data.toUtf8();
        label1->setText("Топ 10 футболистов с max штрафами:\n");
        if (n > 10)
            n = 10;
        for (int i = n - 1; i >= 0; --i) {
            label1->setText(label1->text() + "------------------------------------------\n"
                                           "Футболист № " + QString::number(n - i) + '\n');
            data = a[i].name + '\n';
            label1->setText(label1->text() + data.toUtf8());
            data = a[i].club + '\n';
            label1->setText(label1->text() + data.toUtf8());
            data = a[i].type + '\n';
            label1->setText(label1->text() + data.toUtf8());
            data = a[i].goals + '\n';
            label1->setText(label1->text() + data.toUtf8());
            data = a[i].foals + '\n';
            label1->setText(label1->text() + data.toUtf8());
            data = "------------------------------------------\n\n";
            label1->setText(label1->text() + data.toUtf8());
        }
    }
    else
        label1->setText("Информация о футболистах не найдена!\n"
                       "Добавьте информацию");
    delete [] a;
    mainLayout1->addWidget(label1);
    mainWidget1->setLayout(mainLayout1);
    mainWidget1->show();
}

