#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void func();

private:
    QPushButton p1;
    QPushButton * p2;
    int m;
};

#endif // WIDGET_H
