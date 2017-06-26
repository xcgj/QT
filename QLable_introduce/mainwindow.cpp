#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>
#include <QCompleter>//提示模型
#include <QStringList>//字符串列表
#include <QMovie>   //构建动画的头文件

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置文本内容
    ui->labeltxt->setText("1111111");
    //添加图片
    //Pixmap就是一个图像类
    //参数是一个文件对象，需要传入文件路径构建文件对象
    ui->labelimg->setPixmap(QPixmap("://124..png"));
    //调整图片，适配窗口
    ui->labelimg->setScaledContents(true);

    //创建一个动画对象
    QMovie *mymovie = new QMovie("://135..gif");
    //设置动画，把动画对象放在对应的标签里面
    ui->labelgif->setMovie(mymovie);
    //动画对象启动动画
    mymovie->start();
    //设置动画对象自适应标签
    ui->labelgif->setScaledContents(true);

    //设置html内容
    ui->labelurl->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    ui->labelurl->setOpenExternalLinks(true);

    //设置数码管
    ui->lcdNumber->display(123);

    //进度条
    //设置最小值
    ui->progressBar->setMinimum(0);
    //设置最大值
    ui->progressBar->setMaximum(300);
    //设置当前值
    ui->progressBar->setValue(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_10_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex(++i%4);
    /*
     * stackedWidget控件的每一页都可以用索引切换获得
     * 索引从0开始
     * setCurrentIndex()是调到对应下标的页面
     */

    QString str = ui->lineEdit->text();
    /*
     * text() 获得lineEdit中显示的字符串
     * setText() 让对象显示指定字符串
     */
    qDebug() << str;
    ui->lineEdit->setText("ABCDE");
    //设置字符间隙
    ui->lineEdit->setTextMargins(20, 5, 20, 5);
    //密文显示
    ui->lineEdit->setEchoMode(QLineEdit::Password);


    //创建列表，用户输入有提示
    ui->lineEdit_2->setText("请输入内容h");
    QStringList list;
    list << "Hello" << "hi" << "hehe";
    //模型承载列表
    QCompleter * com = new QCompleter(list, this);//指定内容和父类，初始化
    //指定不区分大小写
    com->setCaseSensitivity(Qt::CaseInsensitive);
    //将模型于lineEdit结合
    ui->lineEdit_2->setCompleter(com);
}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}
