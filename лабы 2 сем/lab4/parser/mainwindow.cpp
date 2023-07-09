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
ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();
    ui->listWidget_4->clear();
    ui->listWidget_5->clear();
    ui->listWidget_6->clear();

    auto str = ui->plainTextEdit->toPlainText().toStdString();

        Parser pars(std::move(str));

        for(auto v : pars.getVariables()){
            ui->listWidget->addItem("Переменые "+QString::fromStdString(v.getType() + " " + v.getName() + " = " +
                                                          v.getDefaulValue() + " " + v.getVisibilityArea() + "\n" + v.getPositions()));
        }

        for(auto v : pars.getFunctions()){
            ui->listWidget_2->addItem("Прототипы "+QString::fromStdString(v.getPrototype() + "\nПерегрузки " + v.getOverloadsFunc()));
        }

        for(auto v : pars.getChangePosition()){
            ui->listWidget_3->addItem("Изменение переменых\nСтолбец :" + QString::number(v.first) + " ,Строка :" + QString::number(v.second) + "\n");
        }

        for(auto v : pars.getBranches()){
            ui->listWidget_4->addItem("Строка ветки:"+QString::number(v.first) + " " + ",глубина ветвления: "+ QString::number(v.second) + "\n");
        }

        ui->listWidget_5->addItem("Количество классов : " +QString::number(pars.getComplexStructs()[0]) + "\n" +
                "Структур : " +QString::number(pars.getComplexStructs()[1]) + "\n" +
                "Динамических массивов : " +QString::number(pars.getComplexStructs()[2]) + "\n" +
                "Статических массивов : " +QString::number(pars.getComplexStructs()[3]) + "\n");
        std::pair<int, int> errors = pars.findLogicalErrors();
        if (errors.first == -1 && errors.second == -1) {
            ui->listWidget_6->addItem("не найдено бесконечных циклов.");
        } else {
            ui->listWidget_6->addItem(QString::fromStdString("Бесконечный цикл на строке " + std::to_string(errors.first) + ", символ " + std::to_string(errors.second) + "."));
            }

}


void MainWindow::on_pushButton_2_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "D:", tr("source files (*.cpp *.h)"));
        QFile file(file_name);
        if(file.size() == 0){
           QMessageBox::information(this,"Title","Вы открыли пустой файл");

            }
        if(file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in(&file);
            QString text = in.readAll();
            ui->plainTextEdit->setPlainText(text);
        }
        file.close();

}
