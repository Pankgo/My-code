#pragma once

#include "pieces.h"

class Queen : public _Chess
{
	
public:
	virtual void Set(int x, int y) override
	{
		if (y == 0)
		{
			
			SetXY(x, y,IMAGE_WhiteQueen,_white,_Queen);
		}
		else
		{
		
			SetXY(x, y, IMAGE_BlackQueen,_black, _Queen);
		}
	}
	virtual std::vector<POINT>  SetMove(std::vector<_Chess*>pieces) override
	{

		std::vector<POINT> moveable;

		int curY = GetY();
		int curX = GetX();

		bool down = true; // 상하좌우
		bool up = true;
		bool right = true;
		bool left = true;

		bool left1 = true; // 대각선
		bool left2 = true;
		bool right1 = true;
		bool right2 = true;


		for (int count = 1; count < 8; count++)
		{
			if (CheckPieces(curX, curY + count * 80, pieces) && down) // 하
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
			if (CheckPieces(curX, curY - count * 80, pieces) && up) // 상
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
			if (CheckPieces(curX + 80 * count, curY, pieces) && right) // 우
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
			if (CheckPieces(curX - 80 * count, curY, pieces) && left) //좌
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



		for (int count = 1; count < 8; count++)
		{
			if (CheckPieces(curX - 80 * count, curY + count * 80, pieces) && left1) // (-,+) 대각선
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
				if (Checkenemy())
				{
					left1 = false;
				}
			}
			else
			{
				left1 = false;
			}
			if (CheckPieces(curX - 80 * count, curY - count * 80, pieces) && left2) // (-,-) 대각선
			{
				moveable.push_back({ curX - 80 * count, curY - count * 80 });
				if (Checkenemy())
				{
					left2 = false;
				}
			}
			else
			{
				left2 = false;
			}
			if (CheckPieces(curX + 80 * count, curY - count * 80, pieces) && right1) // (+,-) 대각선
			{
				moveable.push_back({ curX + 80 * count, curY - count * 80 });
				if (Checkenemy())
				{
					right1 = false;
				}
			}
			else
			{
				right1 = false;
			}
			if (CheckPieces(curX + 80 * count, curY + count * 80, pieces) && right2) // (+,+) 대각선
			{
				moveable.push_back({ curX + 80 * count, curY + count * 80 });
				if (Checkenemy())
				{
					right2 = false;
				}
			}
			else
			{
				right2 = false;

			}
		}

		return moveable;
	}
};