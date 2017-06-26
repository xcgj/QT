#include "vicewidget.h"

ViceWidget::ViceWidget(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle ("ViceWindow");
    resize (350, 220);

    p2.setText ("I'm anthoer, let's play!");
    p2.setParent (this);
    p2.move (100, 100);

    connect (&p2, &QPushButton::clicked, this, &ViceWidget::SendSlot);
    //          子控件发射信号             父控件接收信号     父控件响应信号的函数
}

void ViceWidget::SendSlot()
{
    //父控件响应后发出信号
    emit ViceMessage ();
}

//为什么显示重定义错误--无法定义指针
ViceWidget::~ViceWidget(){}
