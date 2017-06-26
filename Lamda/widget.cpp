#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle ("主窗口");
    resize (230, 150);

    p1.setParent (this);
    p1.setText ("打印");
    p1.move (50, 50);
    m = 10;

    p2 = new QPushButton(this);
    p2->setText ("指针打印");
    p2->move (100, 100);
    show();
    //测试lamda

#if 1
    connect (&p1, &QPushButton::pressed,
            [&]()
            /* 匿名函数
             * [] 把外部变量传进函数里面
             * [p1, m] 把外部的p1a和m传进来
             * [=] 把外部所有局部变量、类中所有成员以值传递的方式传进函数(只读)
             * [=]()mutable 传进来的外部变量可修改
             * [this] 类中所有成员以值传递方式传进来
             * [&] 把外部变量(不包括类中成员)以值传递方式传进来
             *      注意：当p1是指向堆空间的指针时，会产生错误，因为p1所指的内存正在使用——原理是什么？？
             */
            {
                p1.setText ("重复打印");
                qDebug() << m;
                m = m + 1;    //这里不是值传递吗？为什么没有报错
                func();
            }
            );
#else
    connect (p2, &QPushButton::clicked,
             [=](bool ParamClick)//会将clicked中的函数参数传值给PramaClick
            {
                qDebug() << ParamClick;
            }
            );
    //建议使用这种方法，能直接调用自定义槽函数，无需调用槽函数体
    //缺点是槽函数代码重用性比较差
#endif
}

Widget::~Widget()
{
    if (NULL != p2)
    {
        delete p2;
        p2 = NULL;
    }
}

void Widget::func()
{
    qDebug() << "func";
}
