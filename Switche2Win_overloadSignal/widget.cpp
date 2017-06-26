#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle ("主窗口");
    resize (400, 300);

    p1.setParent (this);
    p1.setText ("switch1");
    p1.move (150, 150);

    //切换到副窗口
    connect (&p1, &QPushButton::clicked, this, &Widget::mainDeal);

#if 1
    //副窗口发送了两个重载信号，先使用函数指针区分收到的信号，选择执行哪一个信号
    void (Vice::*s1)() = &Vice::ViceSignal;
    //注意加作用域，信号属于Vice类
    void (Vice::*s2)(int, QString) = &Vice::ViceSignal;

    //用函数指针确定具体响应的是副窗口哪个信号，再调用对应的槽函数
    #if 0
    connect (&v, s1, this, &Widget::viceDeal1);
    #else
    connect (&v, s2, this, &Widget::viceDeal2);
    #endif

#else
    /* Qt4信号连接
     * 槽函数必须要用slot关键字修饰
     * 缺陷：
     * SIGNAL SLOT 将函数名字转换成字符串，不进行错误检查
     * 函数名字写错编译不报错，运行出错
     */
    #if 0
    connect (&v, SIGNAL(ViceSignal()), this, SLOT(viceDeal1()));
    #else
    connect (&v, SIGNAL(ViceSignal(int,QString)), this, SLOT(viceDeal2(int,QString)));
    #endif

#endif
}

int Widget::count = 0;

void Widget::mainDeal()
{
    hide();
    v.show();
}

void Widget::viceDeal1()
{
    show();
    v.hide();
}

void Widget::viceDeal2(int a, QString s)
{
    count++;
    //QDebug() 等效于 cout，注意格式，不要忘了()
    //qDebug()文末会自动换行
    //qDebug() << a << s << count;
    qDebug() << a << s.toUtf8 ().data () << count;
    //s.toUtf8 ().data ()   :将输出的字符串转成Utf8的编码格式
    show();
    v.hide();
}

Widget::~Widget()
{
}
