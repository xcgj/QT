#include <QApplication>

#include <QWidget>//���ڿؼ�����

#include <QPushButton>//���ڰ�ť��

int main(int argc, char **argv)
{
    QApplication test(argc, argv);

    QWidget w;

    w.setWindowTitle ("xcgj");//���ô��ڱ���
    w.setWindowTitle (QString("C01"));//��QString�Ͳ���Ϊʲôû����
#if 0
    w.show ();//��ʾ����


    QPushButton p;
    p.setText ("RBMW");//���ô�������
    p.show ();//��д����ʾ��ť����
    /* �����ָ�������󣬶���Ͷ��󣨴��ںʹ��ڣ��Ƕ����ģ���Ƕ��
     * ��aָ��bΪ���ĸ�����a���ڻ����b������
     * ָ����ʽ
     *  1��setParent����
     *  2�����캯������
     * ָ���������ֻ��Ҫ��ʾ�����󴰿�
     */

#endif
# if 1
    //��ʽ1��
    QPushButton p;
    p.setText ("RBMW");//���ô�������
    p.setParent (&w);//���ø�����
    p.move (200, 200);//�ƶ�����λ�ã������ص�Ϊ��λ�����Ͻ�Ϊԭ��

    //��ʽ2��
    QPushButton p2(&w);//���ø�����
    p2.setText ("yjc");//���ô�������
    p2.move (100, 100);//�ƶ�����λ�ã������ص�Ϊ��λ�����Ͻ�Ϊԭ��


    w.show ();

#endif
    test.exec ();
    return 0;
}
