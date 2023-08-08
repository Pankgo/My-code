#pragma once

#include "pieces.h"

class BiShop : public _Chess
{

public:
	virtual std::vector<POINT> SetMove(std::vector<_Chess*>pieces) override
	{
		std::vector<POINT> moveable;

		int curY = GetY();
		int curX = GetX();

		int x1 = curX + 80;
		int x2 = curX - 80;
		int y1 = curY + 80;
		int y2 = curY - 80;

		bool left1 = true;
		bool left2 = true;
		bool right1 = true;
		bool right2 = true;



		int count = 1;

		for (int count = 1; count < 8; count++)
		{
			if (CheckPieces(curX - 80 * count, curY + count * 80, pieces) && left1) // (-,+) 대각선
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				left1 = false;
			}
			if (CheckPieces(curX - 80 * count, curY - count * 80, pieces) && left2) // (-,-) 대각선
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				left2 = false;
			}
			if (CheckPieces(curX + 80 * count, curY - count * 80, pieces) && right1) // (+,-) 대각선
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				right1 = false;
			}
			if (CheckPieces(curX + 80 * count, curY + count * 80, pieces) && right2) // (+,+) 대각선
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				right2 = false;
			}
		}


		return moveable;
	}
};