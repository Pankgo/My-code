#include "pieces.h"
#pragma once

class Rook : public _Chess
{

public:
	Rook() {};
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
			if (CheckPieces(curX, curY + count * 80, pieces) && down) // ��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				down = false;
			}
			if (CheckPieces(curX, curY - count * 80, pieces) && up) // ��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				up = false;
			}
			if (CheckPieces(curX + 80 * count, curY, pieces) && right) // ��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				right = false;
			}
			if (CheckPieces(curX - 80 * count, curY, pieces) && left) //��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				left = false;
			}


		}

		return moveable;
	}
	
};