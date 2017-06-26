#include "vice.h"

Vice::Vice(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle ("副窗口");
    resize (400, 300);

    p2.setParent (this);
    p2.setText ("switch2");
    p2.move (150, 150);

    connect (&p2, &QPushButton::pressed, this, &Vice::signal);

}

void Vice::signal()
{
    //副窗口的槽一次性发出2个信号，而且是重载的
    emit ViceSignal ();
    emit ViceSignal (50, "转换");
}
