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
    //重写鼠标点击事件，验证忽略的信号被父组件接收
    void mousePressEvent(QMouseEvent *event);

    //关闭事件
    void closeEvent(QCloseEvent *e);


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
