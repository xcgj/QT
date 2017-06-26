#include "mainwindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
#include <QTextEdit>
#include <QDockWidget>
#include <QMessageBox>//标准对话框
#include <QFileDialog>//文件对话框
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle ("标准对话框和文件对话框");//主窗标题
    //菜单栏
    QMenuBar * mb = menuBar ();
    this->setMenuBar (mb);
    QMenu * qm = mb->addMenu ("对话框");
    QAction * a1 = qm->addAction ("标准");
    QAction * a2 = qm->addAction ("文件");
    //工具栏
    QToolBar * tb = this->addToolBar ("工具栏");
    tb->addAction (a1);
    tb->addAction (a2);
    //状态栏
    QLabel * l1 = new QLabel(this);
    l1->setText ("label 1");

    QStatusBar * sb = this->statusBar ();
    sb->addWidget (l1);
    sb->addPermanentWidget (new QLabel("label 2", this));
    //核心控件
    QTextEdit * te = new QTextEdit(this);
    this->setCentralWidget (te);
    //浮动窗口
    QDockWidget * dw = new QDockWidget(this);
    dw->setWindowTitle ("浮动窗口");

    QTextEdit * ted = new QTextEdit(dw);//dw可以换成this，区别在哪？
    dw->setWidget(ted);

    this->addDockWidget (Qt::LeftDockWidgetArea, dw);

    //===================对话框实现==================//
    QAction * a3 = qm->addAction ("关于");
    QAction * a4 = qm->addAction ("问题");

    connect (a3, &QAction::triggered, [=]()
    {
        QMessageBox::about (this, "关于Qt", "不告诉你");
        //                  父类指针，窗口标题，窗口内容
    });

    connect (a4, &QAction::triggered, [=]()
    {
        int ret = QMessageBox::question (
                    this,   //父类指针
                    "问题",  //窗口标题
                    "瞅啥？", //窗口内容
                    QMessageBox::Ok, //可不写，默认值是Yes，这个,可以换成|
                    QMessageBox::No);//可不写，默认值是No

        switch (ret)
        {
        case QMessageBox::Ok:
            qDebug() << "看帅哥";
            break;
        case QMessageBox::No:
            qDebug() << "看母的";
            break;
        default:
            break;
        }
    });

    connect (a2, &QAction::triggered, [=]()
    {
        QString path = QFileDialog::getOpenFileName (
                    this,   //父类指针
                    "open", //窗口标题
                    "./",  //打开目录
                    "all(*.*);;source(*.cpp *.h);;text(*.txt)"
                    );//分类查找文件
        qDebug() << path;
    });
}
//结论：
//菜单栏、工具栏、状态栏、核心控件、浮动窗口都是用主窗口的set函数来生成的
//在主窗口所属控件上再增加功能，需要用对应的控件调用add函数实现这些功能
MainWindow::~MainWindow()
{
}
