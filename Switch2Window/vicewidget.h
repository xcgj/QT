#ifndef VICEWIDGET_H
#define VICEWIDGET_H

#include <QWidget>
#include <QPushButton>

class ViceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ViceWidget(QWidget *parent = 0);
    ~ViceWidget();

signals://�����źŹؼ��֣�qt��չ�ؼ��֣�����C++�ؼ���
    /* �źź��������� signals �ؼ�������
     * û�з���ֵ������ �в���
     * ���趨�壬ֻҪ����
     * ʹ�÷�����
     *  emit ViceMessage ();
     */
    void ViceMessage();

public slots://�ۺ���
    void SendSlot();

private:
    QPushButton p2;

};

#endif // VICEWIDGET_H
