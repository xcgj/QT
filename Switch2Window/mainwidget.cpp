#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle ("MainWindow");
    //�̶����ڴ�С
    resize (520, 420);

    p1 = new QPushButton(this);
    p1->setText ("hide me, show another");
    p1->move (200, 200);

    //�����ڷ����ź�
    connect(p1, &QPushButton::pressed, this, &MainWidget::MyAction);

    //�����ڽ��ո������ź�
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
