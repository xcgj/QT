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
    //=========================键盘事件
    //键盘按下事件
    void keyPressEvent(QKeyEvent *event);
    //计时器事件
    void timerEvent(QTimerEvent *event);
private:
    Ui::Widget *ui;

    //计时器区分id
    int timer1id;
    int timer2id;
};

#endif // WIDGET_H
