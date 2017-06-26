#include "mywidget.h"
#include <QApplication>
/* 头文件特点：
 * QApplication：应用程序类
 * 头文件没有.h
 * 头文件和类名一样
 * 前两个字母大写
 */


int main(int argc, char *argv[])
{
    //有且只有一个应用程序类的对象 a
    QApplication a(argc, argv);

    //自己命名的子类，继承于QWidget（窗口基类）
    //所以myWidget也是一个窗口类
    //w是窗口对象，一个窗口
    myWidget w;

    //窗口创建默认是隐藏的，需要人为显示
    //show函数就是将界面窗口显示出来
    w.show();

    //exec函数是让程序一直执行，等待用户操作
    //等待事件的发生，里面有个死循环
    //等效于：
    //a.exec();
    //return 0;
    return a.exec();
}
//代码
