#ifndef INVALIDDATETYPE_H
#define INVALIDDATETYPE_H

#include <QDialog>

namespace Ui {
class invaliddatetype;
}

class invaliddatetype : public QDialog
{
    Q_OBJECT

public:
    explicit invaliddatetype(QWidget *parent = nullptr);
    ~invaliddatetype();

private:
    Ui::invaliddatetype *ui;
};

#endif // INVALIDDATETYPE_H
