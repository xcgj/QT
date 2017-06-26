#include "hero.h"
#include <ctime>

hero::hero()
{
	//Ѫ��
	Basehp = 2000;
	//����
	Baseefense = 80;
	//����������
	Basedamage = 300;
	//������
	Basecritrate = 0;
	//�����˺��ӳ�
	Basedcritdamage = 0;
	//������
	Baseevasionrate = 0;
	//����
	pWeapon = NULL;
	//����
	name = "invorke";
}
void hero::heroequipweapon(weapon *w)
{
	if (this->pWeapon == w)
	{
		return;
	}
	if (this->pWeapon != NULL)
	{
		this->Basedamage -= this->pWeapon->getBasedamage();
		this->Basecritrate -= this->pWeapon->getBasecritrate();
		this->Basedcritdamage -= this->pWeapon->getBasecritdamage();
		this->Baseevasionrate -= this->pWeapon->getBaseevasionrate();
	}
	this->pWeapon = w;
	//װ�����������Ӣ�����Ա仯
	this->Basedamage += this->pWeapon->getBasedamage();
	this->Basecritrate += this->pWeapon->getBasecritrate();
	this->Basedcritdamage += this->pWeapon->getBasecritdamage();
	this->Baseevasionrate += this->pWeapon->getBaseevasionrate();
}
int hero::heroattackmonster(monster *m)
{
	if (this->pWeapon != NULL)
	{
		this->pWeapon->weaponskills(m);
	}

	int totaldamage = Basedamage;
	if (iscrit())
	{
		cout << "����!" << endl;
		totaldamage += totaldamage * Basedcritdamage / 100;//�޸���
	}

	totaldamage -= m->Basedefense;
	m->Basehp -= totaldamage;

	cout << "Ӣ��" << this->name << "�Թ���" << m->name << "�����" << totaldamage << "���˺�" << endl;
	cout << "����Ѫ����" << m->Basehp << endl;
	return m->Basehp;
}

bool hero::iscrit()
{
	srand((unsigned)time(NULL));

	int rate = rand() % 100;

	if (rate < Basecritrate)
	{
		return true;
	}
	return false;
}