#include "bus.h"
#include "ui_bus.h"

bus::bus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bus)
{
    ui->setupUi(this);
}

bus::~bus()
{
    delete ui;
}

void Bus::set_number(QString number){
    if (number == "") throw "error";
    this -> number = number;
}

void Bus::set_destination(QString destination){
    if (destination == "") throw "error";
    this ->destination = destination;
}

void Bus::set_type(QString type){
    if (type == "") throw "error";
    this -> type = type;
}

void Bus::set_time_arrive(QString time_arrive){
    if (QTime::fromString(time_arrive, "HH:mm").isValid()){
       this -> time_arrive  = QTime::fromString(time_arrive);
    }
    else throw "error";
}

void Bus::set_time_dispatch(QString time_dispatch){
    if (time_dispatch == "") throw "error";
    this -> time_dispatch = time_dispatch;
}

QString Bus::get_number() const{
    return number;
}

QString Bus::get_type() const{
    return type;
}

QString Bus::get_destination() const{
    return destination;
}

QString Bus::get_time_dispatch() const{
    return time_dispatch;
}

QTime Bus::get_time_arrive () const{
    return time_arrive;
}


