/*****************************************************************
 * 当tcpserver监听到有新的连接的信号传过来，调用槽函数用tcpsocket去接收信息
 * 从tcpsocket提取信息，在显示窗口显示内容，并且显示传输内容
 * 发送内容时调用tcpsocket的write函数将内容写入
 * 需要安全判断，避免野指针
 *****************************************************************/
#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);

    setWindowTitle("服务器(端口:1111)");

    //初始化，安全检测
    tcpserver = NULL;
    tcpsocket = NULL;

    //监听套接字
    tcpserver = new QTcpServer(this);//指定父对象，内存自动回收
    tcpserver->listen(QHostAddress::Any, 1111);
    //       通配地址，绑定当前网卡所有的IP地址  端口

    //服务器和客户端建立连接
    connect(tcpserver, &QTcpServer::newConnection, [=](){
        //取出建立好连接的套接字，内存由客户端分配
        //由服务器的监听套接字提取
        tcpsocket = tcpserver->nextPendingConnection();

        //获取对方的ip和端口，这些信息存储在接收到的tcpsocket中
        //网络地址转换
        QString ip = tcpsocket->peerAddress().toString();
        //端口
        qint16 port = tcpsocket->peerPort();

        //显示内容
        QString temp = QString("ip:%1 port:%2 成功连接").arg(ip).arg(port);
        ui->read->setText(temp);


                //服务器接收客户端的数据
                //使用通信套接字
                connect(tcpsocket, &QTcpSocket::readyRead, [=](){
                    //从通信套接字中取出内容
                    QByteArray array = tcpsocket->readAll();
                    ui->read->append(array);//追加内容
                });
    });


}

server::~server()
{
    delete ui;
}

//服务器向客户端发送内容
void server::on_buttonsend_clicked()
{
    if (NULL == tcpsocket)
    {
        return;
    }

    //获取编辑区的内容
    QString s = ui->write->toPlainText();

    //给客户端发送数据，使用tcpsocket
    //先转一下格式，转成char*
    tcpsocket->write( s.toUtf8().data() );
}

void server::on_buttonclose_clicked()
{
    if (NULL == tcpsocket)
    {
        return;
    }

    //先主动和客户端断开连接
    tcpsocket->disconnectFromHost();

    //关闭连接
    tcpsocket->close();

    tcpsocket = NULL;
}
