#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class button : public QPushButton
{
    Q_OBJECT
public:
    explicit button(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // BUTTON_H
