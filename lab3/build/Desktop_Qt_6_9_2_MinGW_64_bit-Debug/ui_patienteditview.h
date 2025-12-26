/********************************************************************************
** Form generated from reading UI file 'patienteditview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTEDITVIEW_H
#define UI_PATIENTEDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientEditView
{
public:
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *PatientEditView)
    {
        if (PatientEditView->objectName().isEmpty())
            PatientEditView->setObjectName("PatientEditView");
        PatientEditView->resize(552, 366);
        horizontalLayout_10 = new QHBoxLayout(PatientEditView);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalSpacer = new QSpacerItem(102, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(PatientEditView);
        label->setObjectName("label");
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(PatientEditView);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(PatientEditView);
        label_2->setObjectName("label_2");
        label_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(PatientEditView);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_2->addWidget(lineEdit_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(PatientEditView);
        label_3->setObjectName("label_3");
        label_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        lineEdit_7 = new QLineEdit(PatientEditView);
        lineEdit_7->setObjectName("lineEdit_7");

        horizontalLayout_3->addWidget(lineEdit_7);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_8 = new QLabel(PatientEditView);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(label_8);

        comboBox = new QComboBox(PatientEditView);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_4->addWidget(comboBox);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(PatientEditView);
        label_4->setObjectName("label_4");
        label_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_5->addWidget(label_4);

        dateEdit = new QDateEdit(PatientEditView);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout_5->addWidget(dateEdit);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(PatientEditView);
        label_5->setObjectName("label_5");
        label_5->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_6->addWidget(label_5);

        spinBox_2 = new QSpinBox(PatientEditView);
        spinBox_2->setObjectName("spinBox_2");

        horizontalLayout_6->addWidget(spinBox_2);


        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(PatientEditView);
        label_6->setObjectName("label_6");
        label_6->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_7->addWidget(label_6);

        spinBox_3 = new QSpinBox(PatientEditView);
        spinBox_3->setObjectName("spinBox_3");

        horizontalLayout_7->addWidget(spinBox_3);


        gridLayout->addLayout(horizontalLayout_7, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_9 = new QLabel(PatientEditView);
        label_9->setObjectName("label_9");

        horizontalLayout_8->addWidget(label_9);

        spinBox = new QSpinBox(PatientEditView);
        spinBox->setObjectName("spinBox");

        horizontalLayout_8->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout_8, 7, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_7 = new QLabel(PatientEditView);
        label_7->setObjectName("label_7");
        label_7->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_9->addWidget(label_7);

        lineEdit_3 = new QLineEdit(PatientEditView);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_9->addWidget(lineEdit_3);


        gridLayout->addLayout(horizontalLayout_9, 8, 0, 1, 1);


        horizontalLayout_10->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(PatientEditView);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(PatientEditView);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_10->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(155, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        retranslateUi(PatientEditView);

        QMetaObject::connectSlotsByName(PatientEditView);
    } // setupUi

    void retranslateUi(QWidget *PatientEditView)
    {
        PatientEditView->setWindowTitle(QCoreApplication::translate("PatientEditView", "Form", nullptr));
        label->setText(QCoreApplication::translate("PatientEditView", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("PatientEditView", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("PatientEditView", "\350\272\253\344\273\275\350\257\201\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("PatientEditView", "\346\200\247\345\210\253\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("PatientEditView", "\347\224\267", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("PatientEditView", "\345\245\263", nullptr));

        label_4->setText(QCoreApplication::translate("PatientEditView", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("PatientEditView", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("PatientEditView", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("PatientEditView", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("PatientEditView", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("PatientEditView", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PatientEditView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientEditView: public Ui_PatientEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTEDITVIEW_H
