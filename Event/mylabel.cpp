#include "mylabel.h"
#include <QMouseEvent>//鼠标事件头文件
#include <QDebug>

mylabel::mylabel(QWidget *parent) : QLabel(parent)
{
    //在构造函数中设置默认追踪鼠标位置，不需要按一下才记录位置
    this->setMouseTracking(true);
}

//鼠标点击事件
void mylabel::mousePressEvent(QMouseEvent *ev)
{
    //本地坐标（当前窗口坐标）
    int x = ev->x();
    int y = ev->y();

    //Qt下的格式化字符串函数
    /*
     * QString s = QString("abc %1 abc %2").arg(123).arg("xcgj");
     * s = abc 123 abc xcgj
     */

    //判断左键按下还是右键按下
    if (ev->button() == Qt::LeftButton) //左键按下
    {
        qDebug() << "左键按下";
    }
    else if (ev->button() == Qt::RightButton)   //右键按下
    {
        qDebug() << "右键按下";
    }
    else if (ev->button() == Qt::MiddleButton)  //中间键
    {
        qDebug() << "中键按下";
    }

    //嵌套html语句处理字符串
    QString str = QString("<center><h1>"
    //                      居中    标题1
                          "Mouse Press:(%1,  %2)"
                          "</h1></center>")
                          .arg(x).arg(y);
    //设定标签内容
    this->setText(str);

    //设置完成去ui界面提升Label标签
    //Label提升之前是QLabel创建的对象
    //提升之后变成了mylabel的对象，变成了QLabel子类的子类
}

//鼠标释放事件
void mylabel::mouseReleaseEvent(QMouseEvent *ev)
{
    int x = ev->x();
    int y = ev->y();

    QString str = QString("<center><h1>Mouse Release:(%1, %2)</h1></center>").arg(x).arg(y);

    this->setText(str);
    //上一个函数若提升为全局，这里不用再次提升
}

//鼠标移动事件
void mylabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString str = QString("<center><h1>Mouse Move:(%1, %2)</h1></center>").arg(ev->x()).arg(ev->y());

    this->setText(str);
}

void mylabel::enterEvent(QEvent *)
{
    QString str = QString("<h1>Mouse Enter Window</h1>");

    this->setText(str);
}

//离开窗口区域
void mylabel::leaveEvent(QEvent *event)
{
    QString str = QString("<center><h1>Mouse Leave Window</h1></center>");

    this->setText(str);
}
