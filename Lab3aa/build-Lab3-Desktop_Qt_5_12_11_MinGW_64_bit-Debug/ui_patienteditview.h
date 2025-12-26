/********************************************************************************
** Form generated from reading UI file 'patienteditview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QDateEdit *dbDateEditDOB;
    QComboBox *dbComboSex;
    QSpinBox *dbSpinWeight;
    QLabel *label_6;
    QLineEdit *dbEditMobile;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *dbEditIDCard;
    QLabel *label_8;
    QLineEdit *dbEditID;
    QLabel *label_5;
    QLineEdit *dbEditName;
    QLabel *label_3;
    QSpinBox *dbSpinHeight;
    QLabel *label_4;
    QLabel *label_9;
    QLineEdit *dbCreatedTimeStamp;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *PatientEditView)
    {
        if (PatientEditView->objectName().isEmpty())
            PatientEditView->setObjectName(QString::fromUtf8("PatientEditView"));
        PatientEditView->resize(627, 431);
        layoutWidget = new QWidget(PatientEditView);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 0, 531, 411));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 2);

        dbDateEditDOB = new QDateEdit(layoutWidget);
        dbDateEditDOB->setObjectName(QString::fromUtf8("dbDateEditDOB"));

        gridLayout->addWidget(dbDateEditDOB, 4, 1, 1, 2);

        dbComboSex = new QComboBox(layoutWidget);
        dbComboSex->addItem(QString());
        dbComboSex->addItem(QString());
        dbComboSex->setObjectName(QString::fromUtf8("dbComboSex"));

        gridLayout->addWidget(dbComboSex, 3, 2, 1, 1);

        dbSpinWeight = new QSpinBox(layoutWidget);
        dbSpinWeight->setObjectName(QString::fromUtf8("dbSpinWeight"));

        gridLayout->addWidget(dbSpinWeight, 6, 2, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        dbEditMobile = new QLineEdit(layoutWidget);
        dbEditMobile->setObjectName(QString::fromUtf8("dbEditMobile"));

        gridLayout->addWidget(dbEditMobile, 7, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        dbEditIDCard = new QLineEdit(layoutWidget);
        dbEditIDCard->setObjectName(QString::fromUtf8("dbEditIDCard"));

        gridLayout->addWidget(dbEditIDCard, 2, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        dbEditID = new QLineEdit(layoutWidget);
        dbEditID->setObjectName(QString::fromUtf8("dbEditID"));

        gridLayout->addWidget(dbEditID, 0, 2, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        dbEditName = new QLineEdit(layoutWidget);
        dbEditName->setObjectName(QString::fromUtf8("dbEditName"));

        gridLayout->addWidget(dbEditName, 1, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        dbSpinHeight = new QSpinBox(layoutWidget);
        dbSpinHeight->setObjectName(QString::fromUtf8("dbSpinHeight"));

        gridLayout->addWidget(dbSpinHeight, 5, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 2);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        dbCreatedTimeStamp = new QLineEdit(layoutWidget);
        dbCreatedTimeStamp->setObjectName(QString::fromUtf8("dbCreatedTimeStamp"));

        gridLayout->addWidget(dbCreatedTimeStamp, 8, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        retranslateUi(PatientEditView);

        QMetaObject::connectSlotsByName(PatientEditView);
    } // setupUi

    void retranslateUi(QWidget *PatientEditView)
    {
        PatientEditView->setWindowTitle(QApplication::translate("PatientEditView", "\347\274\226\350\276\221\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        label_7->setText(QApplication::translate("PatientEditView", "\344\275\223\351\207\215\357\274\232", nullptr));
        dbComboSex->setItemText(0, QApplication::translate("PatientEditView", "\347\224\267", nullptr));
        dbComboSex->setItemText(1, QApplication::translate("PatientEditView", "\345\245\263", nullptr));

        label_6->setText(QApplication::translate("PatientEditView", "\350\272\253\351\253\230\357\274\232", nullptr));
        label->setText(QApplication::translate("PatientEditView", "ID:", nullptr));
        label_2->setText(QApplication::translate("PatientEditView", "\350\272\253\344\273\275\350\257\201", nullptr));
        label_8->setText(QApplication::translate("PatientEditView", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_5->setText(QApplication::translate("PatientEditView", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("PatientEditView", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_4->setText(QApplication::translate("PatientEditView", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_9->setText(QApplication::translate("PatientEditView", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("PatientEditView", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QApplication::translate("PatientEditView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientEditView: public Ui_PatientEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTEDITVIEW_H
