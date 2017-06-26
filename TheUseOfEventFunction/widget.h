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

protected:
    //重写event()函数事件
    bool event(QEvent * e);

    //计时器
    void timerEvent(QTimerEvent *e);

    //键盘按键
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;

    //计时器id
    int timeid;
};

#endif // WIDGET_H
