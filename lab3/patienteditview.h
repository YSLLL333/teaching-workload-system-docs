#ifndef PATIENTEDITVIEW_H
#define PATIENTEDITVIEW_H

#include <QWidget>
#include <QUuid>          // 新增：必须包含QUuid头文件
#include <QDateTime>      // 新增：生成创建时间需要
#include <QMessageBox>    // 新增：弹窗提示需要
#include <QSqlQuery>
#include "ui_patienteditview.h"
#include "PatientModel.h"
#include "patientview.h"


class PatientEditView : public QWidget {
    Q_OBJECT
public:
    // id为nullptr表示添加，否则为修改
    explicit PatientEditView(const QString& id = "", PatientView* parent = nullptr)
        : QWidget(parent), ui(new Ui::PatientEditView), patientId(id), patientView(parent) {
        ui->setupUi(this);
        // 加载数据（修改时）
        if (!patientId.isEmpty()) { // 现在patientId是QString，可调用isEmpty()
            QSqlQuery query;
            query.prepare("SELECT * FROM Patient WHERE ID=:id");
            query.bindValue(":id", patientId);
            if (query.exec() && query.next()) {
                ui->lineEdit->setText(query.value("NAME").toString());          // 姓名
                ui->lineEdit_2->setText(query.value("ID_CARD").toString());     // 身份证
                ui->comboBox->setCurrentIndex(query.value("SEX").toInt());      // 性别（0/1）
                ui->dateEdit->setDate(QDate::fromString(query.value("DOB").toString(), "yyyy/MM/dd")); // 出生日期
                ui->spinBox_2->setValue(query.value("HEIGHT").toDouble());         // 身高
                ui->spinBox_3->setValue(query.value("WEIGHT").toDouble());       // 体重
                ui->lineEdit_7->setText(query.value("MOBILEPHONE").toString()); // 手机号
                ui->spinBox_3->setValue(query.value("AGE").toInt());             // 年龄
            }
        }
        connect(ui->pushButton, &QPushButton::clicked, this, &PatientEditView::onSave);
        connect(ui->pushButton_2, &QPushButton::clicked, this, &PatientEditView::close);
    }

    ~PatientEditView() { delete ui; }

private slots:
    void onSave() {
        QString name = ui->lineEdit->text();
        QString idCard = ui->lineEdit_2->text();
        int sex = ui->comboBox->currentIndex();
        QString dob = ui->dateEdit->date().toString("yyyy/MM/dd");
        double height = ui->spinBox_2->value();
        double weight = ui->spinBox_3->value();
        QString mobilePhone = ui->lineEdit_7->text();
        int age = ui->spinBox->value();
        // 生成ID（示例：用UUID）
        QString id = patientId.isEmpty() ? QUuid::createUuid().toString().replace("{", "").replace("}", "") : patientId;
        // 生成创建时间
        QString createTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

        if (name.isEmpty() || idCard.isEmpty()) {
            QMessageBox::warning(this, "错误", "姓名和身份证不能为空");
            return;
        }


        PatientModel* model = patientView->getModel();
        bool ok;
        if (patientId.isEmpty()) {
            ok = model->addPatient(id, idCard, name, sex, dob, height, weight, mobilePhone, age, createTime);
        } else {
            ok = model->updatePatient(id, idCard, name, sex, dob, height, weight, mobilePhone, age);
        }

        if (ok) {
            QMessageBox::information(this, "成功", "操作成功");
            this->close();
        } else {
            QMessageBox::warning(this, "错误", "操作失败");
        }
    }

private:
    Ui::PatientEditView *ui;
    QString patientId;
    PatientView* patientView;
};

#endif // PATIENTEDITVIEW_H
