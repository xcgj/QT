#include "widget.h"
#include "ui_widget.h"
#include <QPainter> //画家
#include <QPixmap>  //图片
#include <QPen>     //画笔
#include <QBrush>   //画刷填充

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)//不写参数Qt不会报错
{
    //=============画笔基本操作===================
    //先定义出一个画家
    //指定当前窗口（主窗口）为绘图设备
#if 1
    QPainter p(this);
#else   //另一种初始化方式
    QPainter p;//创建画家对象
    p.begin(this);//指定当前窗口为绘图设备
    //绘图操作
    //p.drawxxx();
    p.end();
#endif

    //画背景图，一定要先画
#if 0
    p.drawPixmap(0, 0, width(), height(), QPixmap("D:/Code/QT_project/1.png"));
    //                                  设置大小自适应   放在当前路径，并没有添加资源
#else
    p.drawPixmap(rect(), QPixmap("D:/Code/QT_project/1.png"));
    //        自动获取窗口大小
#endif

    //画笔
    QPen pen;
    pen.setWidth(10);//设置线宽
    pen.setColor(Qt::red);//设置画笔颜色
    pen.setColor(QColor(123,123,123));//RBG设置颜色
    pen.setStyle(Qt::DotLine);//设置画笔模式

    //画刷
    QBrush brush;
    brush.setColor(Qt::red);//颜色
    brush.setStyle(Qt::BDiagPattern);//填充模式

    //把画笔和画刷给画家
    p.setPen(pen);
    p.setBrush(brush);

    //画直线
    p.drawLine(50, 100, 200, 100);  //横线
    p.drawLine(50, 100, 50, 250);   //竖线

    //画矩形
    p.drawRect(150, 150, 100, 50);
    //           坐标     x长  y宽

    //画圆，需要提供圆心，水平方向半径，垂直方向半径
    p.drawEllipse(QPoint(300, 100), 50, 100);

    //=================画图 更新窗口==============
    //载入图片
    QString path("D:/Code/QT_project/1.gif");
    p.drawPixmap(x, 100, 100, 100, QPixmap(path));
    //           起点坐标  宽度  高度   图片


}

void Widget::on_pushButton_clicked()
{
    x += 20;
    if (x > width() - 100)
    {
        x = 0;
    }

    //手动刷新窗口，让窗口重绘
    //也可以在参数中填入坐标指定刷新区域
    update();   //间接调用了paintEven()函数
}
