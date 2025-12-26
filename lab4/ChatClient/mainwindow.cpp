#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::onReadyRead);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString serverAddr = ui->lineEdit->text().trimmed();
    if (serverAddr.isEmpty()) {
        serverAddr = "127.0.0.1";
}
    tcpSocket->connectToHost(serverAddr, 8888);
}

void MainWindow::onConnected()
{
    ui->listWidget->addItem("已成功连接到聊天室");
}

void MainWindow::onReadyRead()
{
    // 读取服务器消息并显示
    QByteArray data = tcpSocket->readAll();
    ui->listWidget->addItem(QString(data));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}


void MainWindow::on_sendButton_clicked()
{
    // 获取输入的消息并发送
    QString msg = ui->textEdit->toPlainText().trimmed();
    if (!msg.isEmpty()) {
        tcpSocket->write(msg.toUtf8());
        ui->textEdit->clear();
    }
}

