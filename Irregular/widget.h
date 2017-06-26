#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //重写画图虚函数
    void paintEvent(QPaintEvent *event);

    //重写鼠标事件
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;

    //提供一个点，计算坐标差值
    QPoint p;
};

#endif // WIDGET_H
