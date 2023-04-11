#include "Master.h"

class  PlayerInfo
{
	int point;
	string name;
	int stage;

public:
	void Setname(string _name)
	{
		name = _name;
	}
	void SetPoint(int _point)
	{
		point += _point;
	}
	void Setstage()
	{
		stage++;
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
	void Playerclear()
	{
		point = 0;
		name = "";
		stage = 1;
	}
};