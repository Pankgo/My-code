#include "Master.h"

class  PlayerInfo
{
	int playerLife = 7;
	int point;
	string name;
	int stage;

public:
	void Setname(string _name)
	{
		name = _name;
	}
	void SetLife()
	{
		playerLife--;
	}
	void SetPoint(int _point)
	{
		point += _point;
	}
	void Setstage()
	{
		stage++;
	}
	int getLife()
	{
		return playerLife;
	}
	string getName()
	{
		return name;
	}
	int Getstage()
	{
		return stage;
	}
	int GetPoint()
	{
		return point;
	}
};