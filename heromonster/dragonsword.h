#pragma once
#include"weapon.h"
#include<ctime>


class dragonsword : public weapon
{
	
public:
	dragonsword();
	void weaponskills(monster *m);
public:
	//��ѣ����
	int stunrate;
	//��ѣ�غ�
	int stunround;
};