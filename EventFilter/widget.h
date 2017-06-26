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

    //事件过滤器函数
    bool eventFilter(QObject *watched, QEvent *event);
    //                      要过滤的控件        要过滤掉的事件

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
