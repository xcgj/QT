#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>//��ͷ�ļ�

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void slotFunc1();
private:
    QPushButton p1;//���������
    QPushButton *p2;//����ָ��������ָ��
    QPushButton p3;
};

#endif // MAINWIDGET_H
