#include "Character.h"
#pragma once

class Monster : public Character
{
public:
	void setMonster(Player *py) 
	{
		Level = py->retLevel() * 3; // ���� ���� ����
		Damage = Level * 3; //������ ���� ����� ������ �� �޶�����.
		Hp = Level * 30;
		CurExp = Level * 40;
		Money = Level * 500;
	}
	
};