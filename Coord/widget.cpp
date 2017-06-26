#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    /* 子窗口坐标系统相对于父窗口
     * 原点是屏幕左上角(不包括边框)，x向右增，y向下增
     * 超出范围被隐藏
     */
    move(0, 0);
    resize(300, 300);

    QPushButton * p1 = new QPushButton(this);
    p1->move(20, 30);
    p1->resize (200, 200);

    QPushButton * p2 = new QPushButton(p1);
    p2->move(-50, -50);
    p2->resize (100, 100);
}

Widget::~Widget()
{

}
