#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

#include <QDebug>//打印

#include "vice.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots://qt4的槽函数必须加的关键字和访问权限，qt5不用加
    void mainDeal();
    void viceDeal1();
    void viceDeal2(int, QString);

private:
    QPushButton p1;
    Vice v;
    static int count;
};

#endif // WIDGET_H
