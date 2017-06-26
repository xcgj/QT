#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton ViceWindow;
    QPushButton bt1;
    QPushButton *bt2;
};

#endif // WIDGET_H
