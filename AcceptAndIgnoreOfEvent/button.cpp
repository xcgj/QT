#include "button.h"
#include <QMouseEvent>
#include <QDebug>

button::button(QWidget *parent) : QPushButton(parent)
{

}

void button::mousePressEvent(QMouseEvent *e)
{
#if 0   //接受完信号不传递，信号中断
    //button是按钮pushButton的父类，父类的函数处理信号
    if (e->button() == Qt::LeftButton)
    {
        qDebug() << "按下按钮，按钮的父类函数先处理信号";    //信号的接收
        //处理完成后，信号中断了，因为这里没有继续发出
    }
    else
    {
        //不处理，继续发出信号
        QPushButton::mousePressEvent(e);//信号的忽略
    }
#elif 0 //接受完信号继续传递，信号延续
    //button是按钮pushButton的父类，父类的函数处理信号
    if (e->button() == Qt::LeftButton)
    {
        qDebug() << "按下按钮，按钮的父类函数先处理信号";    //信号的接收
        //处理完成后，信号中断了，因为这里没有继续发出
    }
    else
    {
        //不处理，继续发出信号    //信号的忽略
    }

    //继续发出信号，防止信号中断，信号是发给了父类QPushButton还是QWidget？
    //是发给了父类QPushButton，因为函数指定了父类传递： QPushButton::
    QPushButton::mousePressEvent(e);
#elif 1 //接受完信号再忽略，信号传给谁的问题
    //button是按钮pushButton的父类，父类的函数处理信号
    if (e->button() == Qt::LeftButton)
    {
        qDebug() << "按下按钮，按钮的父类函数先处理信号";    //信号的接收

        //这里的忽略具有继续发送信号的效果
        e->ignore();//忽略，信号继续往下传递，传给了谁？
        //事件传递给了 父组件(Widget，父窗口)，而不是给父类(QPushButton)
        //不是继承关系类的传递
    }
    else
    {
        //不处理，继续发出信号
        QPushButton::mousePressEvent(e);//信号的忽略
    }
#endif
}
