#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    //重写虚函数加载图片
    void paintEvent(QPaintEvent *event);
};

#endif // WIDGET_H
