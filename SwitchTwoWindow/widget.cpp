#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //���������ڱ���
    setWindowTitle ("MainWindow");

    //���ø����ڱ���
    ViceWindow.setWindowTitle ("ViceWindow");

    //�������������ϵ
    bt1.setParent (this);
    bt2 = new QPushButton(&ViceWindow);

    //��ť��Ϣ
    bt1.setText ("Hide me, show another");
    bt2->setText ("Let's play");
    bt1.move(250, 150);
    //bt2->move(250, 150);

    //ʵ�ֹ���
    connect(&bt1, &QPushButton::released, &ViceWindow, &QPushButton::show);
    connect(&bt1, &QPushButton::released, this, &Widget::hide);

    connect(bt2, &QPushButton::released, this, &Widget::show);
    connect(bt2, &QPushButton::released, &ViceWindow, &QPushButton::hide);
    //���鶼ʹ��һ���Ĳ����źţ����򴰿ڵı仯����Ų���,released,pressed
}

Widget::~Widget()
{
    if (NULL != bt2)
    {
        delete bt2;
        bt2 = NULL;
    }
}
