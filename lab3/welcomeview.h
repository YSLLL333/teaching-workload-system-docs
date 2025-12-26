#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include <QWidget>
#include "ui_welcomeview.h"

// 前置声明
class MasterView;

class WelcomeView : public QWidget {
    Q_OBJECT
public:
    explicit WelcomeView(QWidget *parent = nullptr);
    ~WelcomeView();

private slots:
    // 抽离跳转逻辑为独立槽函数（关键：避免头文件中写模板代码）
    void onPatientBtnClicked();

private:
    Ui::WelcomeView *ui;
};

#endif // WELCOMEVIEW_H
