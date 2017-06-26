#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = 0);

    //实现虚函数继承
protected:
    //虚函数不能用F1查询使用方法，需要在基类中查询

    //=======================鼠标事件
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *ev);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *ev);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev);
    //进入窗口区域
    void enterEvent(QEvent *event);
    //离开窗口区域
    void leaveEvent(QEvent *event);
signals:

public slots:
};

#endif // MYLABEL_H
