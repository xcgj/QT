#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //背景色
    ui->label->setStyleSheet("QLabel{"
                             "background-color:rgb(123,123,123);"
                             "}");

    //安装label过滤器，参数：指定哪个父对象来处理
    //this：在当前父对象窗口中进行过滤操作
    ui->label->installEventFilter(this);

    //鼠标进入
    ui->label->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

//创建过滤器，首先需要安装过滤器才能使用这个创建的
bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    //发现了Label的对象，开始监控，看看有没有需要过滤的事件
    if (watched == ui->label)
    {
        //判断事件
        if (event->type() == QEvent::MouseMove)
        {
            //将事件转换为鼠标事件
            QMouseEvent * mmv = static_cast<QMouseEvent *>(event);
            //响应事件
            ui->label->setText(QString("mouse move:%1,%2").arg(mmv->x()).arg(mmv->y()));
            //不让事件继续传播
            return true;
        }
        else
        {
            return QWidget::eventFilter(watched, event);
        }
    }
    else
    {
        //其他类继续指定发送给父类操作（和原来的操作方法一样）
        return QWidget::eventFilter(watched, event);
    }
    //return QWidget::eventFilter(watched, event);//可直接写这一句，省略以上两句return
}
