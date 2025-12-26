#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void onConnected();           // 连接服务器成功
    void onReadyRead();           // 接收服务器消息

    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;
};
#endif // MAINWINDOW_H
