#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>//类头文件

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void slotFunc1();
private:
    QPushButton p1;//创建类对象
    QPushButton *p2;//创建指向类对象的指针
    QPushButton p3;
};

#endif // MAINWIDGET_H
