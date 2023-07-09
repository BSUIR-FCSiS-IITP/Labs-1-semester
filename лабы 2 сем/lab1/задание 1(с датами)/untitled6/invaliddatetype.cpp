#include "invaliddatetype.h"
#include "ui_invaliddatetype.h"

invaliddatetype::invaliddatetype(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::invaliddatetype)
{
    ui->setupUi(this);
}

invaliddatetype::~invaliddatetype()
{
    delete ui;
}
