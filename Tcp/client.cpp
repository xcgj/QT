#include "client.h"
#include "ui_client.h"
#include <QHostAddress>

client::client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);

    setWindowTitle("客户端");

    tcpsocket = NULL;

    //分配控件，指定父对象自动释放
    tcpsocket = new QTcpSocket(this);

    //连接信息返回
    //如果成功和对方建立了连接， 通信套接字 会自动触发connected()，触发后自动进入槽函数
    connect(tcpsocket, &QTcpSocket::connected, [=](){
        ui->read->setText("与服务器连接成功！");
    });

    //接收信息
    connect(tcpsocket, &QTcpSocket::readyRead, [=](){
        //获取对方发送的内容
        QByteArray array = tcpsocket->readAll();
        ui->read->append(array);
    });
}

client::~client()
{
    delete ui;
}

//发送数据
void client::on_buttonsend_clicked()
{
    //获取编辑框内容
    QString s = ui->write->toPlainText();

    //发送数据
    tcpsocket->write( s.toUtf8().data() );
}

//tcpsocket调用connectToHost函数请求服务器连接
void client::on_buttonconnect_clicked()
{
    //先获取服务器ip 端口
    //本机ip地址：192.168.19.113
    QString ip = ui->ip->text();
    qint16 port = ui->port->text().toInt();

    //主动和服务器建立连接
    tcpsocket->connectToHost(QHostAddress(ip), port);
}

void client::on_buttonclose_clicked()
{
    //主动断开连接
    tcpsocket->disconnectFromHost();
    tcpsocket->close();
}
