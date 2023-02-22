#include "Mecro.h"


class Character
{
protected:
	int Hp = 100;
	string Name = " ";
	int CurExp = 0;
	int Damage = 10;
	int Money = 1000;
	int Level = 1;
public :
	void HpCal(int Damage)//hp 계산
	{
		Hp -= Damage;
	}
	int retHp()
	{
		return Hp;
	}
	int retDamage()
	{
		return Damage;
	}
	int retExp()
	{
		return CurExp;
	}
	int retMoney()
	{
		return Money;
	}
};

class Player : public Character
{
	string Weapon = " ";
	int NeedLevelExp = 100;
public:
	void load(ifstream& Load)
	{
		Load >> Name;
		Load >> Level;
		Load >> Weapon;
		Load >> Damage;
		Load >> Money;
		Load >> CurExp;

	}
	void SetName(string name)
	{
		Name = name;
	}
	bool CheckNew()//새롭게 시작하는지 안하는지 이름을 확인한다.
	{
		if (Name.size() == 0)
		{
			return false;
		}
		return true;
	}
	string retName()
	{
		return Name;
	}
	int retLevel()
	{
		return Level;
	}
	void setMoney(int money)
	{
		Money += money;
	}
	void getExp(int monsterExp)
	{
		CurExp += monsterExp;
	}
	void setLevel()
	{
		Level++;
	}
	void clearStatus()
	{
		Hp = Level * 50;
		Damage += Level;
	}

};

