#include "mywidget.h"
#include <QApplication>
/* ͷ�ļ��ص㣺
 * QApplication��Ӧ�ó�����
 * ͷ�ļ�û��.h
 * ͷ�ļ�������һ��
 * ǰ������ĸ��д
 */


int main(int argc, char *argv[])
{
    //����ֻ��һ��Ӧ�ó�����Ķ��� a
    QApplication a(argc, argv);

    //�Լ����������࣬�̳���QWidget�����ڻ��ࣩ
    //����myWidgetҲ��һ��������
    //w�Ǵ��ڶ���һ������
    myWidget w;

    //���ڴ���Ĭ�������صģ���Ҫ��Ϊ��ʾ
    //show�������ǽ����洰����ʾ����
    w.show();

    //exec�������ó���һֱִ�У��ȴ��û�����
    //�ȴ��¼��ķ����������и���ѭ��
    //��Ч�ڣ�
    //a.exec();
    //return 0;
    return a.exec();
}
//����
