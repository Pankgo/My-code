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
			SetXY(x, y, IMAGE_WhitePawn,_white,_Pawn);
		}
		else
		{
			SetXY(x, y, IMAGE_BlackPawn, _black, _Pawn);
		}
	}
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
			if (CheckPieces(curX, curY + forward * 80 * (i + 1), pieces) )
			{
				if (!Checkenemy()) // 상대피스가 있어도 폰은 대각선으로밖에 못움직인다.
				{
					moveable.push_back({ curX, curY + forward * 80 * (i + 1) });
					continue;
				}
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