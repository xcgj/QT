#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    p1.setText ("close");//内容
    p1.setParent (this);//指定的父类
    p1.move (50, 50);//位移

    p2 = new QPushButton(this);//构造时就指定父类
    p2->setText ("change");//内容

    p3.setText ("hide");
    p3.setParent (this);
    p3.move (100, 100);

    connect(&p1, &QPushButton::pressed, this, &MainWidget::close);
    /* &p1:信号发出者，指针类型
     * &QPushButton::pressed:处理的信号，格式：
     *      &信号发送者的类型::信号名字
     * this:信号接收者
     * &MainWidget::close:槽函数（信号处理函数），格式：
     *      &信号接收者的类型::槽函数的名字
     */

    /* 自定义槽：和普通函数的用法没有区别
     * Qt5自定义槽函数的特点：可以是任意的成员函数(常用)，普通全局函数，静态函数
     * 槽函数的 参数 和 返回值 要和信号一致
     * 由于信号都是没有返回值的，所以槽函数一定没有返回值
     */
    //槽是父类
    connect(p2, &QPushButton::released, this, &MainWidget::slotFunc1);
    //槽是其他子类
    connect(&p3, &QPushButton::released, &p3, &QPushButton::hide);
    //同一个信号发送者，多个信号接收者
    connect(p2, &QPushButton::released, &p3, &QPushButton::show);
}

void MainWidget::slotFunc1()
{
    p2->setText ("xcgj");
}

MainWidget::~MainWidget()
{
    if (NULL != p2)
    {
        delete p2;
        p2 = NULL;
    }
}
