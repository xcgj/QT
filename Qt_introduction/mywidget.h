#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class myWidget : public QWidget//F1���������ĵ�
{
    Q_OBJECT//�ź���� ��Ҫ�õ�

public:
    myWidget(QWidget *parent = 0);//F4�л�����ʵ��
    ~myWidget();
};

#endif // MYWIDGET_H
