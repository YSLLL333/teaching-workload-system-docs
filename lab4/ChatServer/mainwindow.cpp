#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clienthandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection, this, &MainWindow::onNewConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if (tcpServer->isListening()) {
        // 停止服务
        tcpServer->close();
        ui->startButton->setText("启动服务器");
        ui->plainTextEdit->appendPlainText("服务器已停止");
    } else {
        // 启动服务（监听8888端口）
        if (tcpServer->listen(QHostAddress::Any, 8888)) {
            ui->startButton->setText("停止服务器");
            ui->plainTextEdit->appendPlainText("服务器已启动，监听端口8888");
        } else {
            ui->plainTextEdit->appendPlainText("服务器启动失败：" + tcpServer->errorString());
        }
    }
}
void MainWindow::onNewConnection()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    QString clientInfo = "新客户端连接：" + clientSocket->peerAddress().toString() + ":" + QString::number(clientSocket->peerPort());
    ui->plainTextEdit->appendPlainText(clientInfo);

    // 创建客户端处理线程并启动
    ClientHandler *handler = new ClientHandler(clientSocket);
    handler->start();
}
