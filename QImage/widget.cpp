/*****************************************************************
 * 不在主窗口绘图，在QImage中绘图
 *****************************************************************/

#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //定义绘图设备
    //QImage(int width, int height, Format format)
    //可以指定透明背景
    QImage i(4000, 3000, QImage::Format_ARGB32);//A:透明通道

    //创建画家
    QPainter p;
    p.begin(&i);//指定绘图设备

    //绘图
    p.drawImage(0, 0, QImage("D:/Code/QT_project/1.png"));

    //对绘图设备指定区域操作
    for (int k = 0; k < 50; ++k)
    {
        for (int j = 0; j < 50; ++j)
        {
            i.setPixel(QPoint(k, j), qRgb(255, 0, 0));

            //获取像素点
            //返回值是qRgb
            //i.pixel(QPoint(k, j));
        }
    }

    p.end();

    //保存图片
    i.save("D:/Code/QT_project/3.png");
}

Widget::~Widget()
{
    delete ui;
}
