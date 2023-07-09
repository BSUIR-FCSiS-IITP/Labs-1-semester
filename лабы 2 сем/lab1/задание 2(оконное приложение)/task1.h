#ifndef TASK1_H
#define TASK1_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Task1;
}

void *qs1(football *a, int first, int last);
void *qs2(football *a, int first, int last);

class Task1 : public QDialog
{
    Q_OBJECT

public:
    explicit Task1(QWidget *parent = nullptr);
    ~Task1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Task1 *ui;
};

#endif // TASK1_H
