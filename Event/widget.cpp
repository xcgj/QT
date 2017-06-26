#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>    //键盘事件所需头文件
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动计时器
    timer1id = this->startTimer(1000);//启动后，计数的时间间隔，单位毫秒
    timer2id = this->startTimer(500);

}

Widget::~Widget()
{
    delete ui;
}

//键盘按下事件
void Widget::keyPressEvent(QKeyEvent *event)
{
    //打印ASCII码
    //qDebug() << event->key();

    //打印字符
    qDebug() << (char)event->key();

    //精确判断输入字符
    if (event->key() == Qt::Key_A)
    {
        qDebug() << "Qt::Key_A";
    }
}

//计时器事件
//计时器可以启动，也可以停止
void Widget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer1id)
    {
        //计时器
        static int time = 0;

        //设置标签显示计时器内容
        ui->label->setText(QString("<center><h1>time count:%1</h1><center>").arg(++time));

        if (time == 5)
        {
            //停止计时器
            killTimer(timer1id);
        }
    }
    if (event->timerId() == timer2id)
    {
        //计时器
        static int time = 0;

        //设置标签显示计时器内容
        ui->label_2->setText(QString("<center><h1>time count:%1</h1><center>").arg(++time));
    }
}
