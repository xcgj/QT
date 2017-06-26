#include <QApplication>

#include <QWidget>//窗口控件基类

#include <QPushButton>//窗口按钮类

int main(int argc, char **argv)
{
    QApplication test(argc, argv);

    QWidget w;

    w.setWindowTitle ("xcgj");//设置窗口标题
    w.setWindowTitle (QString("C01"));//加QString和不加为什么没区别
#if 0
    w.show ();//显示窗口


    QPushButton p;
    p.setText ("RBMW");//设置窗口内容
    p.show ();//不写不显示按钮窗口
    /* 如果不指定父对象，对象和对象（窗口和窗口）是独立的，不嵌套
     * 若a指定b为它的父对象，a窗口会放在b窗口上
     * 指定方式
     *  1）setParent（）
     *  2）构造函数传参
     * 指定父对象后只需要显示父对象窗口
     */

#endif
# if 1
    //方式1：
    QPushButton p;
    p.setText ("RBMW");//设置窗口内容
    p.setParent (&w);//设置父对象
    p.move (200, 200);//移动窗口位置，以像素点为单位，左上角为原点

    //方式2：
    QPushButton p2(&w);//设置父对象
    p2.setText ("yjc");//设置窗口内容
    p2.move (100, 100);//移动窗口位置，以像素点为单位，左上角为原点


    w.show ();

#endif
    test.exec ();
    return 0;
}
