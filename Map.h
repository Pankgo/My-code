#pragma once
#include"Mecro.h"
#include"MapDraw.h"
class Map
{
private:
	int m_ix;
	int m_iy;
	int m_iWidth;
	int m_iHeight;
public:
	void MapDraw();

	Map();
	~Map();
};
