#include "pieces.h"
#pragma once

class King : public _Chess
{
public:
	virtual std::vector<POINT>  SetMove(std::vector<_Chess*>pieces) override
	{

		std::vector<POINT> moveable;

		int curY = GetY();
		int curX = GetX();

		int x1 = curX + 80;
		int x2 = curX - 80;
		int y1 = curY + 80;
		int y2 = curY - 80;

		for (int i = 0; i < 1; i++) //상하좌우 세팅
		{
			switch (i)
			{
			case 0:
				if (CheckPieces(curX - 80, curY, pieces))
				{
					moveable.push_back({ curX - 80, curY });
				}
				if (CheckPieces(curX + 80, curY, pieces))
				{
					moveable.push_back({ curX + 80, curY });
				}
				break;
			case 1:
				if (CheckPieces(curX, curY+80, pieces))
				{
					moveable.push_back({ curX, curY +80});
				}
				if (CheckPieces(curX, curY, pieces))
				{
					moveable.push_back({ curX , curY - 80});
				}
				break;
			}
		}

		for (int i = 0; i < 1; i++) //대각선 세팅
		{
			switch (i)
			{
			case 0:
				if (CheckPieces(curX - 80, curY + 80, pieces))
				{
					moveable.push_back({ curX - 80, curY + 80 });
				}
				if (CheckPieces(curX - 80, curY - 80, pieces))
				{
					moveable.push_back({ curX - 80, curY - 80});
				}
				break;
			case 1:
				if (CheckPieces(curX + 80, curY + 80, pieces))
				{
					moveable.push_back({ curX + 80, curY + 80 });
				}
				if (CheckPieces(curX  + 80, curY-80, pieces))
				{
					moveable.push_back({ curX + 80 , curY - 80 });
				}
				break;
			}
		}
		


		return moveable;
	}
};