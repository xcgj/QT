/*****************************************************************
 * 不在主窗口绘图，在pixmap中绘图
 *****************************************************************/
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建pixmap对象
    //指定大小
    QPixmap pix(400, 300);

    //画家指定绘图设备
    QPainter p(&pix);

    //pixmap背景填充
        //让画家填充
    //p.fillRect(0, 0, 400, 300, QBrush(Qt::white));
        //让pixmap自己填充
    pix.fill(Qt::white);

    //在pix中绘图
    p.drawPixmap(0, 0, 100, 100, QPixmap("D:/Code/QT_project/1.png"));

    //保存图图片
    pix.save("D:/Code/QT_project/2.png");


}

Widget::~Widget()
{
    delete ui;
}
