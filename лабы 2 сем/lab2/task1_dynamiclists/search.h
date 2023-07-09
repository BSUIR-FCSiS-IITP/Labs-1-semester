#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include "mainwindow.h"

class MainWindow;
class QTableWidget;

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    explicit Search(QWidget *parent, MainWindow *mainWindow);
    ~Search();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Search *ui;
    MainWindow *mainWindow;
};

#endif // SEARCH_H
