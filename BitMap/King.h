#include "pieces.h"
#pragma once

class King : public _Chess
{

public:
	virtual void Set(int x, int y) override
	{
		if (y == 0)
		{
		
			SetXY(x, y, IMAGE_WhiteKing, _white,_King);
		}
		else
		{
			SetXY(x, y, IMAGE_BlackKing, _black,_King);
		}
	}
	virtual std::vector<POINT>  SetMove(std::vector<_Chess*>pieces) override
	{

		std::vector<POINT> moveable;

		int curY = GetY();
		int curX = GetX();

		int x1 = curX + 80;
		int x2 = curX - 80;
		int y1 = curY + 80;
		int y2 = curY - 80;

	//상하좌우
			if (CheckPieces(curX - 80, curY, pieces))
			{
				moveable.push_back({ curX - 80, curY });
			}
			if (CheckPieces(curX + 80, curY, pieces))
			{
				moveable.push_back({ curX + 80, curY });
			}

			if (CheckPieces(curX, curY+80, pieces))
			{
				moveable.push_back({ curX, curY +80});
			}
			if (CheckPieces(curX, curY - 80, pieces))
			{
				moveable.push_back({ curX , curY - 80});
			}

			//대각선

				if (CheckPieces(curX - 80, curY + 80, pieces))
				{
					moveable.push_back({ curX - 80, curY + 80 });
				}
				if (CheckPieces(curX - 80, curY - 80, pieces))
				{
					moveable.push_back({ curX - 80, curY - 80});
				}

				if (CheckPieces(curX + 80, curY + 80, pieces))
				{
					moveable.push_back({ curX + 80, curY + 80 });
				}
				if (CheckPieces(curX  + 80, curY-80, pieces))
				{
					moveable.push_back({ curX + 80 , curY - 80 });
				}



		return moveable;
	}
};