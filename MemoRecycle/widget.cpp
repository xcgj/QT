#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mb = new myButton(this);
    mb->setText ("aaa");
}

Widget::~Widget()
{

}
