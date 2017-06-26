#include "widget.h"
#include "ui_widget.h"
#include  <QPainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //去窗口边框，使之只显示图片
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //              在原来的标记上增加的属性        原来的标记

    //把窗口背景设置为透明
    setAttribute(Qt::WA_TranslucentBackground);

    //此时运行窗口，无法移动，需要重写鼠标事件
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap("D:/Code/QT_project/11.png"));
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    //当前点击坐标-坐标差值获得左上角坐标
    if (e->buttons() & Qt::LeftButton)
    //if (e->buttons() && Qt::LeftButton)   //为什么这样也行
    {
        move(e->globalPos() - p);
    }
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    //左键移动，右键关闭
    if (e->button() == Qt::RightButton)
    {
        close();
    }
    else if (e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}
