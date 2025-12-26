#include "loginview.h"
#include <QMessageBox>

void LoginView::onLogin() {
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    // 登录验证
    QSqlQuery query;
    query.prepare("SELECT * FROM User WHERE USERNAME=:username AND PASSWORD=:password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (query.exec() && query.next()) {
        MasterView* master = new MasterView();
        master->show();
        this->close();
    } else {
        QMessageBox::warning(this, "错误", "用户名或密码错误");
    }
}
