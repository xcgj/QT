#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //========================================================
    /* setStyleSheet的()里面是字符串
     * QLabel{color:red;}
     * 控件{属性 : 值 ; }
     */
    //改变mylabel标签的颜色，即使设置了通用模板，也要按此显示
    ui->mylabel->setStyleSheet("QLabel{color:red;"                  //前景色
                               "background-color:rgb(0,123,255);"   //背景色
                               "background-image:url(://1.png)}");  //设置背景图片，自动平铺

    //设置背景图片，自适应大小，不裁剪
    ui->label2->setStyleSheet("border-image:url(://1.png)}");

    //设置背景图片，自适应大小，裁剪
    //30 30 30 30 stretch stretch
    //上下左右从图片边缘各裁剪30个像素点，中间部分拉伸
    ui->label3->setStyleSheet("border-image:url(://1.png) 60 30 30 30 stretch stretch;}");

    //改变全部QLabel标签的颜色，通用模板
    this->setStyleSheet("QLabel{color:green;"
                        "background-color:rgb(0,255,123);}");

    //========================================================
    //伪状态
    //hover:移动到按钮上
    //pressed:点击按钮
    //QMovie * gif = new QMovie("://2.gif");
    ui->pushButton->setStyleSheet(
                "QPushButton{"
                "border: 2px outset red;"       //按钮边框向外扩展2个像素点，填充红色
                "border-image:url(://4.jpg);"   //按钮添加背景图片
                "}"
                "QPushButton:hover{"
                "border-image:url(://2.gif);"   //鼠标移动到按钮上显示另一张图片
                "}"                             //无法显示 gif 动图效果，怎么解决？
                "QPushButton:pressed{"
                "border-image:url(://3.jpg);"   //点击按钮显示另一张图片
                "}");


}

MainWindow::~MainWindow()
{
    delete ui;
}
