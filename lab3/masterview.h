#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>
#include "ui_masterview.h"
#include "welcomeview.h"
#include "patientview.h"

class MasterView : public QWidget {
    Q_OBJECT
public:
    explicit MasterView(QWidget *parent = nullptr) : QWidget(parent), ui(new Ui::MasterView) {
        ui->setupUi(this);
        // 初始化堆叠窗口
        ui->stackedWidget->addWidget(new WelcomeView()); // 欢迎页
        ui->stackedWidget->addWidget(new PatientView()); // 患者管理页
        // 添加开发者信息（示例：学号20230001 姓名张三）
        ui->labelTitle->setText("医院诊疗系统 | 开发者：20230001 张三");
        // 按钮跳转
        connect(ui->btBack, &QPushButton::clicked, this, [=]{ ui->stackedWidget->setCurrentIndex(0); });
        connect(ui->btLogout, &QPushButton::clicked, this, [=]{ ui->stackedWidget->setCurrentIndex(1); });
    }

    ~MasterView() { delete ui; }

private:
    Ui::MasterView *ui;
};

#endif // MASTERVIEW_H
