#include "Master.h"

class  PlayerInfo
{
	int point;
	string name;
	int stage;
	int life = 7;

public:
	bool operator <(PlayerInfo compare)
	{
		if (this->stage < compare.Getstage())
		{
			return true;
		}
		return false;
	}
	bool operator ==(PlayerInfo compare)
	{
		if (this->stage == compare.Getstage())
		{
			if (this->point < compare.GetPoint())
			{
				return true;
			}
			return false;
		}
		return false;
	}
	void SetLife(int _life)
	{
		life += _life;
	}
	int getLife()
	{
		return life;
	}
	void Setname(string _name)
	{
		name = _name;
	}
	void SetPoint(int _point)
	{
		point += _point;
	}
	void ResetPoint(int _point)
	{
		point = _point;
	}
	void Setstage(int _stage)
	{
		stage = _stage;
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