#include "mybutton.h"

myButton::myButton(QWidget *parent) :
    QPushButton(parent)
{
}

myButton::~myButton ()
{
    qDebug() << "myButton析构函数被调用";
}
