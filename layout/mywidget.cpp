#include "mywidget.h"

#include <QSpinBox>     //选值框
#include <QSlider>      //滑动器
#include <QHBoxLayout>  //水平布局头文件

mywidget::mywidget(QWidget *parent) : QWidget(parent)
{
    //=====================================================
    //创建选值框对象，指定父对象
    QSpinBox * qsb = new QSpinBox(this);

    //=====================================================
    /* 滑条
     * QSlider(Qt::Orientation orientation, QWidget *parent = Q_NULLPTR)
     *               滑动方向                        指定父对象
     * 滑动方向：Qt::Vertical and Qt::Horizontal
     */
    QSlider * qsl = new QSlider(Qt::Horizontal, this);

    //=====================================================
    //将上面两个控件加入布局
    //先创建布局管理器对象
        //本例没有指定父对象，如果指定，会在mywidget中，如果不指定，需要在后面手动指定
    QHBoxLayout * qbl = new QHBoxLayout(/*this*/);
    //再添加小部件，自动按顺序添加
    qbl->addWidget(qsb);
    qbl->addWidget(qsl);
    //没有指定父对象，现在需要手动添加
    setLayout(qbl);
    //去ui界面将这个类提升。。。
    /*
     * 关于全局提升：
     * 可将继承于相同基类的其他控件提升为该控件类型
     * 如：将另外一个Widget(基类是QWidget)控件提升为mywidget(基类是QWidget)，
     * 但是不能将pushbutton(基类是QPushButton)提升为mywidget
     */

    //=====================================================
    //选值框改变滑块
    /* 加入信号和槽
     * qsb的信号有重载的：
     * void valueChanged(int i)
     * void valueChanged(const QString &text)
     * 选择信号需要用函数指针来指定
     */
    connect(qsb,
            static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),//强转类型
            qsl,
            &QSlider::setValue);

    //滑块改变选值框
    connect(qsl,
            &QSlider::valueChanged,
            qsb,
            &QSpinBox::setValue);
}
