#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>
#include "ui_patientview.h"
#include "PatientModel.h"
#include "patienteditview.h"

class PatientView : public QWidget {
    Q_OBJECT
public:
    explicit PatientView(QWidget *parent = nullptr) : QWidget(parent), ui(new Ui::PatientView), model(new PatientModel) {
        ui->setupUi(this);
        ui->tableView->setModel(model);
        // 搜索
        connect(ui->btSearch, &QPushButton::clicked, this, [=]{
            model->refreshData(ui->txtSearch->text());
        });
        // 添加
        connect(ui->btAdd, &QPushButton::clicked, this, [=]{
            PatientEditView* edit = new PatientEditView(nullptr, this);
            edit->show();
        });
        // 修改t
        connect(ui->btEdit, &QPushButton::clicked, this, [=]{
            QModelIndex idx = ui->tableView->currentIndex();
            if (idx.isValid()) {
                QString id = idx.siblingAtColumn(0).data().toString(); // ID是TEXT类型
                PatientEditView* edit = new PatientEditView(id, this);
                edit->show();
            }
        });
        // 删除
        connect(ui->btDelete, &QPushButton::clicked, this, [=]{
            QModelIndex idx = ui->tableView->currentIndex();
            if (idx.isValid() && QMessageBox::question(this, "确认", "确定删除？") == QMessageBox::Yes) {
                QString id = idx.siblingAtColumn(0).data().toString(); // ID是TEXT类型
                model->deletePatient(id);
            }
        });
        connect(ui->btAdd, &QPushButton::clicked, this, [=]{
            PatientEditView* edit = new PatientEditView("", this); // 空字符串表示新增
            edit->show();
        });
    }

    ~PatientView() { delete ui; }

    PatientModel* getModel() { return model; }

private:
    Ui::PatientView *ui;
    PatientModel* model;
};

#endif // PATIENTVIEW_H
