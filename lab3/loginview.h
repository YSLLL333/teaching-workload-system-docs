#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include "ui_loginview.h"
#include "DatabaseUtil.h"
#include "masterview.h"

class LoginView : public QWidget {
    Q_OBJECT
public:
    explicit LoginView(QWidget *parent = nullptr) : QWidget(parent), ui(new Ui::LoginView) {
        ui->setupUi(this);
        connect(ui->btLogin, &QPushButton::clicked, this, &LoginView::onLogin);
    }

    ~LoginView() { delete ui; }

private slots:
    void onLogin() {
        QString username = ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();

        // 登录验证
        QSqlQuery query;
        query.prepare("SELECT * FROM user WHERE username=:username AND password=:password");
        query.bindValue(":username", username);
        query.bindValue(":password", password);
        if (query.exec() && query.next()) {
            // 登录成功，跳转到主界面
            MasterView* master = new MasterView();
            master->show();
            this->close();
        } else {
            QMessageBox::warning(this, "错误", "用户名或密码错误");
        }
    }

private:
    Ui::LoginView *ui;
};

#endif // LOGINVIEW_H
