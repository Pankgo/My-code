#pragma once

#include "pieces.h"

class Pawn : public _Chess
{
	bool firstMove = true;
public:
	virtual void Set(int x, int y) override
	{
		if (y == 80)
		{
			SetXY(x, y, IMAGE_WhitePawn,_white);
		}
		else
		{
			SetXY(x, y, IMAGE_BlackPawn, _black);
		}
	}
	virtual std::vector<POINT> SetMove(std::vector<_Chess*>pieces) override
	{
		/*std::vector<POINT> moveable;
		
		int curY = GetY();
		int curX = GetX();

		int x1 = curX + 80;
		int x2 = curX - 80;
		int y1 = curY + 80;
		int y2 = curY - 80;

		int forward = GetColor() ? 1 : -1;
		const int size = firstMove ? 1 : 2;
		for (int i = 0; size > i; i++)
		{
			if (CheckPieces(x2, curY + forward * 80 * (i + 1), pieces))
			{
				moveable.push_back({ x2, curY + forward * 80 * (i + 1) });
				continue;
			}

			break;
		}

		if (CheckPieces(curX + 80, curY + forward * 80, pieces))
		{
			moveable.push_back({ curX + 80, curY + forward * 80 });
		}
		if (CheckPieces(curX - 80, curY + forward * 80, pieces))
		{
			moveable.push_back({ curX - 80, curY + forward * 80 });
		}

		
		return moveable;*/
		std::vector<POINT> moveable;

		int curY = GetY();
		int curX = GetX();


		int forward = GetColor() ? 1 : -1;
		const int size = firstMove ? 2 : 1;
		firstMove = false;
		for (int i = 0; size > i; i++)
		{
			if (CheckPieces(curX, curY + forward * 80 * (i + 1), pieces) == true)
			{
				moveable.push_back({ curX, curY + forward * 80 * (i + 1) });
				continue;
			}

			break;
		}

		if (CheckPieces(curX + 80, curY + forward * 80, pieces))
		{
			moveable.push_back({ curX + 80, curY + forward * 80 });
		}
		if (CheckPieces(curX - 80, curY + forward * 80, pieces))
		{
			moveable.push_back({ curX - 80, curY + forward * 80 });
		}
		return moveable;
	}
};