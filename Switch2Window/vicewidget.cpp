#include "vicewidget.h"

ViceWidget::ViceWidget(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle ("ViceWindow");
    resize (350, 220);

    p2.setText ("I'm anthoer, let's play!");
    p2.setParent (this);
    p2.move (100, 100);

    connect (&p2, &QPushButton::clicked, this, &ViceWidget::SendSlot);
    //          �ӿؼ������ź�             ���ؼ������ź�     ���ؼ���Ӧ�źŵĺ���
}

void ViceWidget::SendSlot()
{
    //���ؼ���Ӧ�󷢳��ź�
    emit ViceMessage ();
}

//Ϊʲô��ʾ�ض������--�޷�����ָ��
ViceWidget::~ViceWidget(){}
