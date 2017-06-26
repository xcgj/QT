#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QDebug>

class myButton : public QPushButton
{
    Q_OBJECT
public:
    //此函数指定用QWidget作为父类，是为了窗口继承
    explicit myButton(QWidget *parent = 0);

    ~myButton();
signals:

public slots:

};

#endif // MYBUTTON_H
