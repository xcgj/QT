#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QCloseEvent>  //关闭事件的头文件
#include <QMessageBox>  //标准对话框，用来接静态函数

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //在主窗口中，按下pushButton发出信号，并处理
    connect(ui->pushButton, &button::clicked, [=]()
    {
        qDebug() << "button按钮被按下";  //接收并处理这个信号的对象是主窗口QWidget吗？
    });
}

//重写鼠标点击事件，验证忽略的信号被父组件接收
void Widget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        qDebug() << "忽略的信号被父组件接收";
    }

}

//关闭事件
void Widget::closeEvent(QCloseEvent *e)
{
    //问题对话框，弹出消息
    int ret = QMessageBox::question(this, "question", "确定关闭窗口吗？");//后面有两个默认参数，是yes和no按钮
    // 返回值                         父对象    标题           内容
    //返回值是后面两个默认参数

    if (ret == QMessageBox::Yes)
    {
        //关闭窗口
        //处理关闭窗口事件(接收到了close()信号)，接收后事件不会再往其他地方传递
        e->accept();
    }
    else
    {
        //不关闭窗口
        //忽略接收到的close()信号，事件传给父组件处理，如果没有找到接收的对象，close()信号就是无效的
        e->ignore();

    }
}

Widget::~Widget()
{
    delete ui;
}
