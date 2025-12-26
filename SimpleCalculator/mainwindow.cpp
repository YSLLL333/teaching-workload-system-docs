#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <cmath>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet(R"(
        /* 1. 主窗口样式 */
        QMainWindow {
            background-color: #f0f0f0;
        }

        /* 2. 显示框样式（输入输出区域） */
        QLineEdit#display {
            background-color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 15px 20px;
            margin: 10px;
            color: #333333;
            font-family: "Microsoft YaHei", Arial;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1) inset;
        }

        /* 3. 通用按钮基础样式 */
        QPushButton {
            border: none;
            border-radius: 8px;
            font-family: "Microsoft YaHei", Arial;
            font-size: 16px;
            margin: 5px;
            min-height: 40px;
            min-width: 60px;
        }

        /* 4. 数字按钮样式（0-9、.）- 蓝色系 */
        QPushButton[text="0"],
        QPushButton[text="1"],
        QPushButton[text="2"],
        QPushButton[text="3"],
        QPushButton[text="4"],
        QPushButton[text="5"],
        QPushButton[text="6"],
        QPushButton[text="7"],
        QPushButton[text="8"],
        QPushButton[text="9"],
        QPushButton[text="."] {
            background-color: #e3f2fd;
            color: #1976d2;
        }
        QPushButton[text="0"]:hover,
        QPushButton[text="1"]:hover,
        QPushButton[text="2"]:hover,
        QPushButton[text="3"]:hover,
        QPushButton[text="4"]:hover,
        QPushButton[text="5"]:hover,
        QPushButton[text="6"]:hover,
        QPushButton[text="7"]:hover,
        QPushButton[text="8"]:hover,
        QPushButton[text="9"]:hover,
        QPushButton[text="."]:hover {
            background-color: #bbdefb;
        }
        QPushButton[text="0"]:pressed,
        QPushButton[text="1"]:pressed,
        QPushButton[text="2"]:pressed,
        QPushButton[text="3"]:pressed,
        QPushButton[text="4"]:pressed,
        QPushButton[text="5"]:pressed,
        QPushButton[text="6"]:pressed,
        QPushButton[text="7"]:pressed,
        QPushButton[text="8"]:pressed,
        QPushButton[text="9"]:pressed,
        QPushButton[text="."]:pressed {
            background-color: #90caf9;
        }

        /* 5. 运算符按钮样式（+、-、×、/、=）- 橙色系 */
        QPushButton[text="+"],
        QPushButton[text="-"],
        QPushButton[text="×"],
        QPushButton[text="/"],
        QPushButton[text="="] {
            background-color: #fff3e0;
            color: #f57c00;
            font-weight: bold;
        }
        QPushButton[text="+"]:hover,
        QPushButton[text="-"]:hover,
        QPushButton[text="×"]:hover,
        QPushButton[text="/"]:hover,
        QPushButton[text="="]:hover {
            background-color: #ffe0b2;
        }
        QPushButton[text="+"]:pressed,
        QPushButton[text="-"]:pressed,
        QPushButton[text="×"]:pressed,
        QPushButton[text="/"]:pressed,
        QPushButton[text="="]:pressed {
            background-color: #ffcc80;
        }

        /* 6. 功能按钮样式（C、CE、DEL、%）- 红色系 */
        QPushButton[text="C"],
        QPushButton[text="CE"],
        QPushButton[text="DEL"],
        QPushButton[text="%"] {
            background-color: #ffebee;
            color: #d32f2f;
        }
        QPushButton[text="C"]:hover,
        QPushButton[text="CE"]:hover,
        QPushButton[text="DEL"]:hover,
        QPushButton[text="%"]:hover {
            background-color: #ffcdd2;
        }
        QPushButton[text="C"]:pressed,
        QPushButton[text="CE"]:pressed,
        QPushButton[text="DEL"]:pressed,
        QPushButton[text="%"]:pressed {
            background-color: #ef9a9a;
        }

        /* 7. 特殊运算按钮样式（√、x²、1/x、+/-）- 绿色系 */
        QPushButton[text="√"],
        QPushButton[text="x²"],
        QPushButton[text="1/x"],
        QPushButton[text="+/-"] {
            background-color: #e8f5e9;
            color: #388e3c;
        }
        QPushButton[text="√"]:hover,
        QPushButton[text="x²"]:hover,
        QPushButton[text="1/x"]:hover,
        QPushButton[text="+/-"]:hover {
            background-color: #c8e6c9;
        }
        QPushButton[text="√"]:pressed,
        QPushButton[text="x²"]:pressed,
        QPushButton[text="1/x"]:pressed,
        QPushButton[text="+/-"]:pressed {
            background-color: #a5d6a7;
        }
    )");

    // 1. 绑定数字按钮（0-9）点击事件
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 1
    connect(ui->pushButton_9,  &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 2
    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 3
    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 4
    connect(ui->pushButton_24, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 5
    connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 6
    connect(ui->pushButton_23, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 7
    connect(ui->pushButton_18, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 8
    connect(ui->pushButton_21, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 9
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // 0
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::onNumberClicked); // .

    // 2. 绑定运算符按钮（+/-/×/÷）点击事件
    connect(ui->pushButton_10,  &QPushButton::clicked, this, &MainWindow::onOperatorClicked); // +
    connect(ui->pushButton_22,  &QPushButton::clicked, this, &MainWindow::onOperatorClicked); // -
    connect(ui->pushButton_17,  &QPushButton::clicked, this, &MainWindow::onOperatorClicked); // ×
    connect(ui->pushButton_8,   &QPushButton::clicked, this, &MainWindow::onOperatorClicked); // ÷

    // 3. 绑定功能按钮（C/CE/DEL/=/%）点击事件
    connect(ui->pushButton_4,   &QPushButton::clicked, this, &MainWindow::onFunctionClicked); // C
    connect(ui->pushButton_2,   &QPushButton::clicked, this, &MainWindow::onFunctionClicked); // CE
    connect(ui->pushButton_3,   &QPushButton::clicked, this, &MainWindow::onFunctionClicked); // DEL
    connect(ui->pushButton_12,  &QPushButton::clicked, this, &MainWindow::onFunctionClicked); // =
    connect(ui->pushButton,     &QPushButton::clicked, this, &MainWindow::onFunctionClicked); // %

    // 4. 绑定特殊运算按钮（√/x²/1/x/+/-）点击事件
    connect(ui->pushButton_5,   &QPushButton::clicked, this, &MainWindow::onSpecialOpClicked); // √
    connect(ui->pushButton_7,   &QPushButton::clicked, this, &MainWindow::onSpecialOpClicked); // x²
    connect(ui->pushButton_6,   &QPushButton::clicked, this, &MainWindow::onSpecialOpClicked); // 1/x
    connect(ui->pushButton_15,  &QPushButton::clicked, this, &MainWindow::onSpecialOpClicked); // +/-
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 数字按钮（0-9/.）点击处理
void MainWindow::onNumberClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString btnText = btn->text();
    QString currentText = ui->display->text();

    // 逻辑处理
    if (isNewCalculation)
    {
        // 新计算开始：清空显示（除了小数点需补0）
        if (btnText == ".")
            ui->display->setText("0.");
        else
            ui->display->setText(btnText);
        isNewCalculation = false;
    }
    else
    {
        // 避免重复输入小数点
        if (btnText == "." && currentText.contains("."))
            return;
        // 拼接数字
        ui->display->setText(currentText + btnText);
    }
}

// 运算符按钮（+/-/×/÷）点击处理
void MainWindow::onOperatorClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    // 存储第一个运算数和运算符
    num1 = ui->display->text().toDouble();
    operatorType = btn->text();
    isNewCalculation = true; // 准备输入第二个数
}

// 功能按钮（C/CE/DEL/=/%）点击处理
void MainWindow::onFunctionClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString btnText = btn->text();
    QString currentText = ui->display->text();

    if (btnText == "C")
    {
        // 清空所有状态（重置）
        ui->display->setText("0");
        num1 = 0.0;
        num2 = 0.0;
        operatorType.clear();
        isNewCalculation = true;
    }
    else if (btnText == "CE")
    {
        // 清空当前输入（保留历史状态）
        ui->display->setText("0");
        isNewCalculation = true;
    }
    else if (btnText == "DEL")
    {
        // 删除最后一个字符
        if (currentText.length() > 1)
            ui->display->setText(currentText.left(currentText.length() - 1));
        else
            ui->display->setText("0"); // 只剩1个字符时删为0
    }
    else if (btnText == "%")
    {
        // 百分比运算（当前数÷100）
        double val = currentText.toDouble() / 100;
        ui->display->setText(QString::number(val));
    }
    else if (btnText == "=")
    {
        // 计算结果
        num2 = ui->display->text().toDouble();
        double result = 0.0;

        // 根据运算符计算
        if (operatorType == "+")
            result = num1 + num2;
        else if (operatorType == "-")
            result = num1 - num2;
        else if (operatorType == "×")
            result = num1 * num2;
        else if (operatorType == "/")
        {
            // 避免除以0
            if (num2 == 0)
            {
                ui->display->setText("Error");
                isNewCalculation = true;
                return;
            }
            result = num1 / num2;
        }

        // 显示结果（移除末尾多余的0和小数点）
        if (result == result && !std::isinf(result)) // 排除NaN和无穷大
        {
            if (result == floor(result)) // 整数结果
                ui->display->setText(QString::number((long long)result));
            else // 小数结果
                ui->display->setText(QString::number(result));
        }
        else
        {
            ui->display->setText("Error");
        }

        isNewCalculation = true; // 计算完成，准备新计算
    }
}

// 特殊运算按钮（√/x²/1/x/+/-）点击处理
void MainWindow::onSpecialOpClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString btnText = btn->text();
    double currentVal = ui->display->text().toDouble();
    double result = 0.0;

    if (btnText == "√")
    {
        // 平方根（仅非负数）
        if (currentVal < 0)
        {
            ui->display->setText("Error");
            return;
        }
        result = sqrt(currentVal);
    }
    else if (btnText == "x²")
    {
        // 平方运算
        result = currentVal * currentVal;
    }
    else if (btnText == "1/x")
    {
        // 倒数（避免除以0）
        if (currentVal == 0)
        {
            ui->display->setText("Error");
            return;
        }
        result = 1 / currentVal;
    }
    else if (btnText == "+/-")
    {
        // 正负号切换
        result = -currentVal;
    }

    // 显示结果（同“=”逻辑，优化显示格式）
    if (result == floor(result))
        ui->display->setText(QString::number((long long)result));
    else
        ui->display->setText(QString::number(result));
}
