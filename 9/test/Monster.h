#include "Character.h"
#pragma once

class Monster : public Character
{
public:
	void setMonster(Player *py) 
	{
		Level = py->retLevel() * 3; // 몬스터 레벨 설정
		Damage = Level * 3; //레벨에 따라 피통과 데미지 가 달라진다.
		Hp = Level * 30;
		CurExp = Level * 40;
		Money = Level * 500;
	}
	
};