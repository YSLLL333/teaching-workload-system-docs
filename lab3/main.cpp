#include <QApplication>
#include "loginview.h"
#include "DatabaseUtil.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // 初始化数据库
    DatabaseUtil::getInstance();
    // 显示登录界面
    LoginView w;
    w.show();
    return a.exec();
}
