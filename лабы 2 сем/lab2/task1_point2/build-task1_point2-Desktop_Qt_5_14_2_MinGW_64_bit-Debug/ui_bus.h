/********************************************************************************
** Form generated from reading UI file 'bus.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUS_H
#define UI_BUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_bus
{
public:

    void setupUi(QDialog *bus)
    {
        if (bus->objectName().isEmpty())
            bus->setObjectName(QString::fromUtf8("bus"));
        bus->resize(400, 300);

        retranslateUi(bus);

        QMetaObject::connectSlotsByName(bus);
    } // setupUi

    void retranslateUi(QDialog *bus)
    {
        bus->setWindowTitle(QCoreApplication::translate("bus", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bus: public Ui_bus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUS_H
