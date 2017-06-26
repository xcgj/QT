#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置整个应用程序的setStyleSheet都以此为参考
    //a.setStyleSheet();

    MainWindow w;
    w.show();

    return a.exec();
}
