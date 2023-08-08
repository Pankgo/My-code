#pragma once

#include "pieces.h"

class Pawn : public _Chess
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

		
		return moveable;
	}
};