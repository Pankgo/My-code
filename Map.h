//겜매니저 역할
#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"MainGame.h"

class Map
{
private:
	int m_x=0;
	int m_y=0;
	int m_Width=0;
	int m_Height=0;
	PlayerInfo p1;
	PlayerInfo p2;
public: 
	void UIDraw();
	Map();
	~Map();
	
};

