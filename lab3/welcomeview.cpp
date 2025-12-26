#include "welcomeview.h"
#include "masterview.h" // 包含完整头文件，支持模板解析
#include <QStackedWidget>

WelcomeView::WelcomeView(QWidget *parent) : QWidget(parent), ui(new Ui::WelcomeView) {
    ui->setupUi(this);
    // 绑定按钮点击到槽函数
    connect(ui->btPatient, &QPushButton::clicked, this, &WelcomeView::onPatientBtnClicked);
}

WelcomeView::~WelcomeView() {
    delete ui;
}

// 实现跳转逻辑（编译器能正确解析findChild模板）
void WelcomeView::onPatientBtnClicked() {
    // 安全转换父窗口类型
    MasterView* master = qobject_cast<MasterView*>(parent()->parentWidget());
    if (master) {
        // 查找堆叠窗口并跳转
        QStackedWidget* stackWidget = master->findChild<QStackedWidget*>();
        if (stackWidget) {
            stackWidget->setCurrentIndex(1);
        }
    }
}
