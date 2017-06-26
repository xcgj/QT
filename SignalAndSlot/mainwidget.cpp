#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    p1.setText ("close");//����
    p1.setParent (this);//ָ���ĸ���
    p1.move (50, 50);//λ��

    p2 = new QPushButton(this);//����ʱ��ָ������
    p2->setText ("change");//����

    p3.setText ("hide");
    p3.setParent (this);
    p3.move (100, 100);

    connect(&p1, &QPushButton::pressed, this, &MainWidget::close);
    /* &p1:�źŷ����ߣ�ָ������
     * &QPushButton::pressed:������źţ���ʽ��
     *      &�źŷ����ߵ�����::�ź�����
     * this:�źŽ�����
     * &MainWidget::close:�ۺ������źŴ�����������ʽ��
     *      &�źŽ����ߵ�����::�ۺ���������
     */

    /* �Զ���ۣ�����ͨ�������÷�û������
     * Qt5�Զ���ۺ������ص㣺����������ĳ�Ա����(����)����ͨȫ�ֺ�������̬����
     * �ۺ����� ���� �� ����ֵ Ҫ���ź�һ��
     * �����źŶ���û�з���ֵ�ģ����Բۺ���һ��û�з���ֵ
     */
    //���Ǹ���
    connect(p2, &QPushButton::released, this, &MainWidget::slotFunc1);
    //������������
    connect(&p3, &QPushButton::released, &p3, &QPushButton::hide);
    //ͬһ���źŷ����ߣ�����źŽ�����
    connect(p2, &QPushButton::released, &p3, &QPushButton::show);
}

void MainWidget::slotFunc1()
{
    p2->setText ("xcgj");
}

MainWidget::~MainWidget()
{
    if (NULL != p2)
    {
        delete p2;
        p2 = NULL;
    }
}
