#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QThread>
#include <QTcpSocket>
#include <QMutex>
#include <QList>

class ClientHandler : public QThread
{
    Q_OBJECT
public:
    explicit ClientHandler(QTcpSocket *socket, QObject *parent = nullptr);
    ~ClientHandler();

    // 静态成员：管理所有客户端（需线程同步）
    static QList<ClientHandler*> clients;
    static QMutex mutex;

protected:
    void run() override; // 线程执行函数

private slots:
    void onReadyRead();   // 读取客户端消息
    void onDisconnected();// 客户端断开连接

private:
    QTcpSocket *clientSocket;
};

// 静态成员初始化
QList<ClientHandler*> ClientHandler::clients;
QMutex ClientHandler::mutex;

#endif // CLIENTHANDLER_H
