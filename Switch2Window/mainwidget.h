#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "vicewidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void MyAction();
    void DealMessage();
private:
    QPushButton * p1;
    ViceWidget vw;
};

#endif // MAINWIDGET_H
