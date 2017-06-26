#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class myWidget : public QWidget//F1跳到帮助文档
{
    Q_OBJECT//信号与槽 需要用到

public:
    myWidget(QWidget *parent = 0);//F4切换函数实现
    ~myWidget();
};

#endif // MYWIDGET_H
