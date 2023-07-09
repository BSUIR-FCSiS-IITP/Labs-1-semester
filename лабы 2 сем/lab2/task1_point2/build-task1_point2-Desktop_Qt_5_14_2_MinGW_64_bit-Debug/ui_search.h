/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_search
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;

    void setupUi(QDialog *search)
    {
        if (search->objectName().isEmpty())
            search->setObjectName(QString::fromUtf8("search"));
        search->resize(580, 300);
        search->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0.965174, y2:0.0909091, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(22, 25, 185, 255))\n"
"};"));
        listWidget = new QListWidget(search);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(170, 10, 401, 231));
        pushButton = new QPushButton(search);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 150, 121, 41));
        lineEdit = new QLineEdit(search);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 70, 121, 31));
        lineEdit_2 = new QLineEdit(search);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 110, 121, 31));
        pushButton_2 = new QPushButton(search);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(460, 240, 111, 31));

        retranslateUi(search);

        QMetaObject::connectSlotsByName(search);
    } // setupUi

    void retranslateUi(QDialog *search)
    {
        search->setWindowTitle(QCoreApplication::translate("search", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("search", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("search", "\320\237\321\200\320\270\320\261\321\213\321\202\320\270\320\265 HH:mm", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("search", "\320\235\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("search", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class search: public Ui_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
