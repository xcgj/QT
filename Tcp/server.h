#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>   //监听套接字
#include <QTcpSocket>   //通信套接字，建立好连接的套接字，只有服务器需要两个套接字

namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = 0);
    ~server();

private slots:
    void on_buttonsend_clicked();

    void on_buttonclose_clicked();

private:
    Ui::server *ui;

    QTcpServer *tcpserver;//监听套接字对象
    QTcpSocket *tcpsocket;//通信套接字
};

#endif // SERVER_H
