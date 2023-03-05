#include "Mecro.h"
#pragma once

class Character
{
protected:
	int Hp = 150;
	string Name = "";
	int CurExp = 0;
	int Damage = 10;
	int Money = 1000;
	int Level = 1;
public :
	void HpCal(int Damage)//hp ���
	{
		//Hp -= Damage;
		Hp = max(Hp - Damage, 0);
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
	int orginHp = Hp;
	string Weapon = "���� ���Ⱑ �����ϴ�";
	int NeedLevelExp = 100;
	int SpecialAttackChance = 0;//Ư�� ���� ��ȸ
public:
	void setPlayer()
	{
		Hp = orginHp;
		SpecialAttackChance = 0;
	}
	void load(ifstream& Load)
	{
		Load >> Name;
		Load >> Level;
		Load >> Weapon;
		Load >> Damage;
		Load >> Money;
		Load >> CurExp;

	}
	void Save(ofstream& Save)
	{
		Save << Name <<endl;
		Save << Level <<endl;
		Save << Weapon << endl;
		Save << Damage << endl;
		Save << Money << endl;
		Save << CurExp << endl;

	}
	void LevelUp()
	{
		Level++;
		Hp += Level *100;
		orginHp = Hp;
		Damage += 5;
	}
	void SetName(string name)
	{
		Name = name;
	}
	bool CheckNew()//���Ӱ� �����ϴ��� ���ϴ��� �̸��� Ȯ���Ѵ�.
	{
		if (Name.size() == 0)
		{
			return true;
		}
		return false;
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
	void clearStatus()
	{
		Hp = Level * 50;
		Damage += Level;
	}
	void getItem(string weapon)
	{
		Weapon = weapon;
	}
	void setDam(int Dam)
	{
		Damage += Dam;
	}
	string retWeapon()
	{
		return Weapon;
	}
	int retSpecialChance()//����Ȱ����� �������� Ȯ��
	{
		return SpecialAttackChance;
	}
	void getChance(int num)//����Ȱ��ݱ�ȸ ����
	{
		if (SpecialAttackChance != 3 || num == -3)
		{
			SpecialAttackChance += num;
		}
	}

};

