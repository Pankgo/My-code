#include "Character.h"

class Monster : public Character
{
public:
	Monster() 
	{
		Level = 5 * 10; // ���� ���� ����
		Damage = Level * 5;
		Hp = Level * 100;
		CurExp = Level * 10;
		Money = Level * 500;
	}
};