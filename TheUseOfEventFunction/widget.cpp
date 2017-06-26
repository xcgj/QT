#include "widget.h"
#include "ui_widget.h"
#include <QEvent>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动计时器
    timeid = this->startTimer(500);
}

//计时器
void Widget::timerEvent(QTimerEvent *e)
{
    if (e->timerId() == timeid)
    {
        static int count = 0;

        //设置计时器显示内容
        ui->label->setText(QString("<center><h1>timecount ： %1</h1></center>").arg(++count));
    }
}

//键盘按键
void Widget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_B)
    {
        qDebug() << "B被按下";
    }
}

//重写event()函数事件
//Type type() const
//Type中枚举了各种事件
bool Widget::event(QEvent * e)
{
    /*
    //e是事件对象
    //事件分发，用e判断事件的类型
    switch( e->type() )
    {
    case QEvent::Close:
        closeEvent(e);//传入事件对象
        break;
    case QEvent::MouseMove:
        mouseMoveEvent(e);
        break;
    //……
    }
    */
    if (e->type() == QEvent::Timer)
    {
        //干掉计时器
        //如果返回true，事件停止传播，计时器停止工作
        //QTimerEvent *ev = static_cast<QTimerEvent *>(e);
        //timeEvent(ev);
        return true;
    }
    else if (e->type() == QEvent::KeyPress)
    {
        //类型转换
        QKeyEvent * ev = static_cast<QKeyEvent *>(e);
        //只有在按下B的时候，才事件转发
        if (ev->key() == Qt::Key_B)
        {
            return QWidget::event(e);
        }
        //其余事件终止
        return true;
        //意思是按其他键没反应，除了B按键
    }
    else
    {
        //让其他事件继续按照原来的方式传播
        return QWidget::event(e);
    }
}

Widget::~Widget()
{
    delete ui;
}
