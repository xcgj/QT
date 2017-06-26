#include "mainwindow.h"
#include <QMenuBar>//菜单栏
#include <QMenu>//菜单
#include <QAction>//菜单动作
#include <QToolBar>//工具栏
#include <QPushButton>
#include <QDebug>
#include <QLabel>//标签
#include <QStatusBar>//状态栏
#include <QTextEdit>//文本编辑
#include <QDockWidget>//浮动窗口
#include <QDialog>//对话框

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle ("模态和非模态");
    //创建菜单栏、工具栏、状态栏、核心控件、动态窗口
    //菜单栏：
   QMenuBar * mb = new QMenuBar;
   // QMenuBar * mb = menuBar ();//菜单栏

    setMenuBar (mb);//写不写效果一样，最好写一下

    QMenu * m = mb->addMenu ("窗口");//菜单
    QAction * mt = m->addAction("模态");//菜单动作1
    m->addSeparator ();//当前菜单分割线
    QAction * nmt = m->addAction("非模态");//菜单动作2

    //工具栏：
    QToolBar * tb = addToolBar ("工具栏");
    tb->addAction(mt);
    tb->addAction(nmt);

    QPushButton * p = new QPushButton(tb);
    p->setText ("吃瓜群众");
    tb->addWidget (p);//增加控件，不这么做按钮会顶格，覆盖其他内容
    connect (p, &QPushButton::clicked, [=]()
    {
        qDebug() << "看戏";
    }
    );

    //状态栏：
    QLabel * l1 = new QLabel(this);
    l1->setText ("lable 1");
    //QStatusBar * sb = new QStatusBar;//这么写没有状态栏
    QStatusBar * sb = statusBar ();
    sb->addWidget (l1);

    sb->addWidget (new QLabel("lable 2", this));

    sb->addPermanentWidget (new QLabel("lable 3", this));

    //核心控件
    QTextEdit * te = new QTextEdit(this);
    this->setCentralWidget (te);

    //浮动窗口
    QDockWidget * dw = new QDockWidget(this);
    dw->setWindowTitle ("浮动窗口");

    QTextEdit * dte = new QTextEdit(dw);
    dw->setWidget (dte);

    this->addDockWidget (Qt::LeftDockWidgetArea, dw);
    //总结：
    //待添加的控件需要不仅要先初始化完毕，还要让上一级窗口主动调用这个控件才行


    //模态对话框触发
    //模态：只有当前窗口可执行操作
    connect (mt, &QAction::triggered,//模态
             [=]()
            {
                QDialog d;//对话框对象
                d.exec ();//等待用户执行操作才能继续执行下一步
                qDebug() << "我是模态，我的操作窗口已经执行完毕";
            }
            );
    connect (nmt, &QAction::triggered,//非模态
             //非模态有3种执行方式：
             [=]()
            {
#if 0
                //1 栈局部变量，生命周期只是此作用域，看不到对话框显示，无法满足要求
                QDialog d1;
                d1.show();
                qDebug() << "我是非模态栈局部变量d1，我的操作窗口已经发出";
#elif 0//推荐
                //2 成员变量
                d2.show();
                qDebug() << "我是非模态成员变量d2，我的操作窗口已经发出";
#elif 0
                //3 堆局部变量指定父类，程序终止才会释放，如果多次使用造成内存占用
                QDialog * d3 = new QDialog(this);//指定父对象，内存自动回收
                d3->show();
                qDebug() << "我是非模态堆局部变量d3，我的操作窗口已经发出";
#else//推荐
                //4 堆局部变量，及时释放
                QDialog * d4 = new QDialog;
                d4->setAttribute (Qt::WA_DeleteOnClose);//窗口关闭后就释放
                d4->show();
                qDebug() << "我是非模态堆局部变量4，我的操作窗口已经发出";
#endif
            }
            );
}

MainWindow::~MainWindow()
{

}
