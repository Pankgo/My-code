#include "pieces.h"
#pragma once

class Rook : public _Chess
{
public:
	Rook() {};
	virtual void Set(int x, int y) override
	{
		if (y == 0)
		{
			SetXY(x, y, IMAGE_WhiteRook,_white,_Rook);
		}
		else
		{
			SetXY(x, y, IMAGE_BlackRook,_black, _Rook);
		}
	}
	virtual std::vector<POINT>  SetMove(std::vector<_Chess*>pieces) override
	{

		std::vector<POINT> moveable;

		int curY = GetY();
		int curX = GetX();

		bool down = true;
		bool up = true;
		bool right = true;
		bool left = true;


		for (int count = 1; count < 8; count++)
		{
			if (CheckPieces(curX, curY + count * 80, pieces) && down) // го
			{
				moveable.push_back({ curX, curY + count * 80 });
				if (Checkenemy())
				{
					down = false;
				}
			}
			else
			{
				down = false;
			}
			if (CheckPieces(curX, curY - count * 80, pieces) && up) // ╩С
			{
				moveable.push_back({ curX, curY - count * 80 });
				if (Checkenemy())
				{
					up = false;
				}
			}
			else
			{
				up = false;
			}
			if (CheckPieces(curX + 80 * count, curY, pieces) && right) // ©Л
			{
				moveable.push_back({ curX + 80 * count, curY });
				if (Checkenemy())
				{
					right = false;
				}
			}
			else
			{
				right = false;
			}
			if (CheckPieces(curX - 80 * count, curY, pieces) && left) //аб
			{
				moveable.push_back({ curX - 80 * count, curY });
				if (Checkenemy())
				{
					left = false;
				}
			}
			else
			{
				left = false;
			}


		}

		return moveable;
	}
	
};