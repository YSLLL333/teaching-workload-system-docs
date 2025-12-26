#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 数字按钮点击槽函数
    void onNumberClicked();
    // 运算符按钮点击槽函数
    void onOperatorClicked();
    // 功能按钮（C/CE/DEL/=等）点击槽函数
    void onFunctionClicked();
    // 特殊运算按钮（√/x²/1/x/+/-）点击槽函数
    void onSpecialOpClicked();

private:
    Ui::MainWindow *ui;
    double num1 = 0.0;          // 第一个运算数
    double num2 = 0.0;          // 第二个运算数
    QString operatorType;       // 当前运算符（+/-/×/÷）
    bool isNewCalculation = true; // 是否开始新计算（用于清空显示）
};

#endif // MAINWINDOW_H
