/*****************************************************************
 * 不在主窗口绘图，在QPicture中绘图
 *****************************************************************/

#include "widget.h"
#include <QPainter>
#include <QPicture>

#include <QPixmap>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPicture pic;
    QPainter p;
    p.begin(&pic);

    p.drawPixmap(0, 0, 100, 100, QPixmap("D:/Code/QT_project/1.png"));

    p.end();

    //二进制格式保存
    pic.save("D:/Code/QT_project/4.png");
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    //创建画家画图
    QPainter p(this);//画在当前窗口上

    //=========读取QPicture二进制图片=============
#if 0
    QPicture pic;

    //加载图片
    pic.load("D:/Code/QT_project/4.png");

    p.drawPicture(0, 0, pic);
#endif

    //==========QPixmap和QImage转换=============
#if 0
    //pixmap转image
    QPixmap pix;
    pix.load("D:/Code/QT_project/1.png");

    QImage tmp = pix.toImage();
    p.drawImage(0, 0, tmp);
#endif
    //image转pixmap
    QImage i;
    i.load("D:/Code/QT_project/1.png");

    //静态成员函数
    QPixmap tmp = QPixmap::fromImage(i);
    p.drawPixmap(0, 0, tmp);
}
