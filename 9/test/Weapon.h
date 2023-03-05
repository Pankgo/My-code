#include "Mecro.h"

class Weapon
{
	int Damage;
	int Value;
	string Name;

public :
	void setitem(string name, int damage, int value)
	{
		Damage = damage;
		Value = value;
		Name = name;
	}
	int retDamage()
	{
		return Damage;
	}
	int retValue()
	{
		return Value;
	}
	string retName()
	{
		return Name;
	}
};