#include "dragonsword.h"
#include <ctime>


dragonsword::dragonsword()
{
	//�����˺�
	Basedamage = 30;
	//���������˺��ӳ�
	Basecritdamage = 100;
	//����������������
	Basecritrate = 40;
	//�������ܼ���
	Baseevasionrate = 30;
	//��������
	name = "������";
	//��ѣ����
	stunrate = 30;
	//��ѣ�غ�
	stunround = 1;
}

void dragonsword::weaponskills(monster *m)
{
	srand((unsigned int)time(NULL));

	int rate1 = rand() % 100 + 1;
	int rate2 = rand() % 100 + 1;

	if (stunrate < rate1)
	{
		return;
	}
	m->stunround = this->stunround;
	if (Baseevasionrate < rate2)
	{
		return;
	}
	m->attackmiss = true;

}