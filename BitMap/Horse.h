#include "pieces.h"
#pragma once



class Horse : public _Chess
{
public:
	virtual void Set(int x, int y) override
	{
		if (y == 0)
		{
			SetXY(x, y, IMAGE_WhiteHorse,_white,_Knight);
		}
		else
		{
			SetXY(x, y, IMAGE_BlackHorse,_black, _Knight);
		}
	}
	virtual std::vector<POINT>  SetMove(std::vector<_Chess*>pieces) override
	{
		std::vector<POINT> moveable;

		int curY = GetY();
		int curX = GetX();

		int count = 1;

		if (CheckPieces(curX - 80, curY - 80 * 2 , pieces) ) // (-,+) 대각선
		{
			moveable.push_back({ curX - 80, curY - 80 * 2 });
		}
		if (CheckPieces(curX + 80 * count, curY - count * 80 * 2, pieces)) // (-,+) 대각선
		{
			moveable.push_back({ curX + 80 * count, curY - count * 80 * 2 });
		}
		if (CheckPieces(curX - 80 * count, curY + count * 80 * 2, pieces)) // (-,+) 대각선
		{
			moveable.push_back({ curX - 80 * count, curY + count * 80 * 2 });
		}
		if (CheckPieces(curX + 80 * count, curY + count * 80 * 2, pieces)) // (-,+) 대각선
		{
			moveable.push_back({ curX + 80 * count, curY + count * 80 * 2 });
		}
	

		if (CheckPieces(curX - 80 * count * 2, curY - count * 80 , pieces)) // (-,+) 대각선
		{
			moveable.push_back({ curX - 80 * count * 2, curY - count * 80 });
		}
		if (CheckPieces(curX - 80 * count * 2, curY + count * 80 , pieces)) // (-,+) 대각선
		{
			moveable.push_back({ curX - 80 * count * 2, curY + count * 80 });
		}
		if (CheckPieces(curX + 80 * count *2, curY + count * 80, pieces)) // (-,+) 대각선
		{
			moveable.push_back({ curX + 80 * count * 2, curY + count * 80 });
		}
		if (CheckPieces(curX + 80 * count *2 , curY - count * 80 , pieces)) // (-,+) 대각선
		{
			moveable.push_back({ curX + 80 * count * 2 , curY - count * 80 });
		}

		return moveable;


	}
};