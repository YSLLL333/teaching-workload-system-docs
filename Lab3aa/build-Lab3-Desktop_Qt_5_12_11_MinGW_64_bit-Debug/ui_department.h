/********************************************************************************
** Form generated from reading UI file 'department.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENT_H
#define UI_DEPARTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Department
{
public:

    void setupUi(QWidget *Department)
    {
        if (Department->objectName().isEmpty())
            Department->setObjectName(QString::fromUtf8("Department"));
        Department->resize(400, 300);

        retranslateUi(Department);

        QMetaObject::connectSlotsByName(Department);
    } // setupUi

    void retranslateUi(QWidget *Department)
    {
        Department->setWindowTitle(QApplication::translate("Department", "\347\247\221\345\256\244\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Department: public Ui_Department {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENT_H
