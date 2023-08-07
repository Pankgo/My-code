#include "pieces.h"
#pragma once



class Horse : public _Chess
{

public:

	std::vector<POINT>  SetMove(std::vector<_Chess*>pieces) override
	{
		std::vector<POINT> moveable;

		int curY = GetY();
		int curX = GetX();

		int x1 = curX + 80;
		int x2 = curX - 80;
		int y1 = curY + 80;
		int y2 = curY - 80;



	}
};