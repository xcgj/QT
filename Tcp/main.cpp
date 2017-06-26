#include "server.h"
#include <QApplication>

#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server w;
    w.show();

    //把客户端窗口显示出来
    client c;
    c.show();

    return a.exec();
}
