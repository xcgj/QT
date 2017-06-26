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
    //重写绘图事件的虚函数
    //如果在窗口绘图，必须放在绘图事件里实现
    //绘图事件内部在窗口需要重绘的时候，会自动调用，不像计时器那样还要手动start
    //窗口重绘：窗口状态改变，变大变小等
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    int x;
};

#endif // WIDGET_H
