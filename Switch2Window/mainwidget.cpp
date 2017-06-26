#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle ("MainWindow");
    //固定窗口大小
    resize (520, 420);

    p1 = new QPushButton(this);
    p1->setText ("hide me, show another");
    p1->move (200, 200);

    //主窗口发送信号
    connect(p1, &QPushButton::pressed, this, &MainWidget::MyAction);

    //主窗口接收副窗口信号
    connect (&vw, &ViceWidget::ViceMessage, this, &MainWidget::DealMessage);
}

void MainWidget::MyAction()
{
    hide();
    vw.show();
}

void MainWidget::DealMessage()
{
    show();
    vw.hide();
}

MainWidget::~MainWidget()
{
    if(NULL != p1)
    {
        delete p1;
        p1 = NULL;
    }
}
