#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"MainGame.h"

class Map
{
private:
	int m_ix;
	int m_iy;
	int m_iWidth;
	int m_iHeight;
	int stone;
public: 
	void UIDraw();
	Map();
	~Map();
};

