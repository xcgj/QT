#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    //指定画家和绘图设备
    QPainter p(this);

    //QPixmap
    p.drawPixmap(0, 0, QPixmap("D:\\Code\\QT_project\\1.gif"));
    //QBitmap
    p.drawPixmap(50, 0, QBitmap("D:\\Code\\QT_project\\1.gif"));

    QPixmap p1;
    p1.load("D:\\Code\\QT_project\\1.gif");//加载图片
    p.drawPixmap(0, 60, p1);

    QBitmap b;
    b.load("D:\\Code\\QT_project\\1.gif");//加载图片
    p.drawPixmap(50, 60, b);
}
