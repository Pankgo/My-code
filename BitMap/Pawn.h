#pragma once

#include "pieces.h"

class Pawn : public _Chess
{
	bool firstMove = true;

public:
	virtual std::vector<POINT> SetMove(std::vector<_Chess*>pieces) override
	{
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

		if (CheckPieces(curX + 80, curY + forward * 80, pieces) )
		{
			moveable.push_back({ curX + 80, curY + forward * 80 });
		}
		if (CheckPieces(curX - 80, curY + forward * 80, pieces) )
		{
			moveable.push_back({ curX - 80, curY + forward * 80 });
		}

		
		return moveable;
	}
};