#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "weapon.h"
#include "monster.h"

class hero
{
public:
	hero();
	void heroequipweapon(weapon *w);
	int heroattackmonster(monster *m);
	bool iscrit();

public:
	//Ѫ��
	int Basehp;
	//����
	int Baseefense;
	//����������
	int Basedamage;
	//������
	int Basecritrate;
	//�����˺�
	int Basedcritdamage;
	//������
	int Baseevasionrate;
	//����
	weapon *pWeapon;
	//����
	string name;
};