#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>   //通信套接字

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    ~client();

private slots:
    void on_buttonsend_clicked();

    void on_buttonconnect_clicked();

    void on_buttonclose_clicked();

private:
    Ui::client *ui;
    QTcpSocket * tcpsocket;
};

#endif // CLIENT_H
