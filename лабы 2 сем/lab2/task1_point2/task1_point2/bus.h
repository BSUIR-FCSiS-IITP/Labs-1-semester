#ifndef BUS_H
#define BUS_H

#include <QDialog>
#include "QTime"

namespace Ui {
class bus;
}

class bus : public QDialog
{
    Q_OBJECT

public:
    explicit bus(QWidget *parent = nullptr);
    ~bus();

private:
    Ui::bus *ui;
};

#endif // BUS_H

class Bus{
private:
    QString number;
    QString type;
    QString destination;
    QString time_dispatch;
    QTime time_arrive;
public:
    void set_number(QString number);
    void set_type(QString type);
    void set_destination(QString destination);
    void set_time_dispatch(QString time_dispatch);
    void set_time_arrive(QString time_arrive);

    QString get_number() const;
    QString get_type() const;
    QString get_destination() const;
    QString get_time_dispatch() const;
    QTime get_time_arrive() const;
};
