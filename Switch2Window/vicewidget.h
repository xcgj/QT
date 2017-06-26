#ifndef VICEWIDGET_H
#define VICEWIDGET_H

#include <QWidget>
#include <QPushButton>

class ViceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ViceWidget(QWidget *parent = 0);
    ~ViceWidget();

signals://发射信号关键字，qt拓展关键字，不是C++关键字
    /* 信号函数必须用 signals 关键字声明
     * 没有返回值，可以 有参数
     * 无需定义，只要声明
     * 使用方法：
     *  emit ViceMessage ();
     */
    void ViceMessage();

public slots://槽函数
    void SendSlot();

private:
    QPushButton p2;

};

#endif // VICEWIDGET_H
