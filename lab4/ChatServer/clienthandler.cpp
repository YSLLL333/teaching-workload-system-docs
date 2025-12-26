#include "clienthandler.h"

ClientHandler::ClientHandler(QTcpSocket *socket, QObject *parent)
    : QThread(parent)
    , clientSocket(socket)
{
    // 关联socket信号到当前线程的槽函数
    connect(clientSocket, &QTcpSocket::readyRead, this, &ClientHandler::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &ClientHandler::onDisconnected);

    // 加锁：将当前客户端加入全局列表
    QMutexLocker locker(&mutex);
    clients.append(this);
}

ClientHandler::~ClientHandler()
{
    clientSocket->deleteLater();
}

void ClientHandler::run()
{
    // 启动线程事件循环（处理socket信号）
    exec();
}

void ClientHandler::onReadyRead()
{
    // 读取客户端消息
    QByteArray data = clientSocket->readAll();
    QString msg = QString("[%1:%2] %3")
                      .arg(clientSocket->peerAddress().toString())
                      .arg(clientSocket->peerPort())
                      .arg(QString(data));

    // 加锁：广播消息给所有客户端
    QMutexLocker locker(&mutex);
    for (ClientHandler *client : clients) {
        client->clientSocket->write(msg.toUtf8());
    }
}

void ClientHandler::onDisconnected()
{
    QString clientInfo = "客户端断开：" + clientSocket->peerAddress().toString() + ":" + QString::number(clientSocket->peerPort());

    // 加锁：从全局列表移除当前客户端
    QMutexLocker locker(&mutex);
    clients.removeOne(this);

    // 广播“客户端断开”消息
    for (ClientHandler *client : clients) {
        client->clientSocket->write(clientInfo.toUtf8());
    }

    // 退出线程事件循环
    quit();
}
