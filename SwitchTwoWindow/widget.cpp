#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置主窗口标题
    setWindowTitle ("MainWindow");

    //设置父窗口标题
    ViceWindow.setWindowTitle ("ViceWindow");

    //建立父类子类关系
    bt1.setParent (this);
    bt2 = new QPushButton(&ViceWindow);

    //按钮信息
    bt1.setText ("Hide me, show another");
    bt2->setText ("Let's play");
    bt1.move(250, 150);
    //bt2->move(250, 150);

    //实现功能
    connect(&bt1, &QPushButton::released, &ViceWindow, &QPushButton::show);
    connect(&bt1, &QPushButton::released, this, &Widget::hide);

    connect(bt2, &QPushButton::released, this, &Widget::show);
    connect(bt2, &QPushButton::released, &ViceWindow, &QPushButton::hide);
    //建议都使用一样的操作信号，否则窗口的变化会干扰操作,released,pressed
}

Widget::~Widget()
{
    if (NULL != bt2)
    {
        delete bt2;
        bt2 = NULL;
    }
}
