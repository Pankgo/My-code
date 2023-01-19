//겜매니저 역할
#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"MainGame.h"
#include"PlayerInfo.h"
#include <vector>

class Map
{
private:
	int m_x=0;
	int m_y=0;
	int m_Width=20;
	int m_Height=20;
	std::vector<Point> stoneList;
	int wincheck[45][90] ={0,};
	PlayerInfo p1;
	PlayerInfo p2;
public: 
	void UIDraw();
	Map();
	~Map();
	inline int retMW()
	{
		return m_Width;
	}
	inline int retMH()
	{
		return m_Height;
	}
	
};

