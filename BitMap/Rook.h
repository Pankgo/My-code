#include "pieces.h"
#pragma once

class Rook : public _Chess
{

	struct xy {
		int x, y;
	};
	std::vector<xy> rook;
public:
	Rook() {};
	bool SetMove(Tiles tiles[64], std::vector<_Chess*>pieces) override
	{
		int curY = GetY();//현재 룩의 y좌표
		int curX = GetX();//현재 룩의 x좌표
		bool checkX1 = true;
		bool checkX2 = true;
		bool checkY1 = true;
		bool checkY2 = true;

		xy newxy;
		


		for (int X = 1; curX + X*80 < 640 || curX - X * 80 > 0; X++) // y좌표에서 그대로에서 x타일만 변화며 움직일수있는 타일설정
		{
			newxy.y = curY;
			int newx = curX + X * 80;
			switch (checkX1)
			{
			case true:
				for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
				{
					if ((*iter)->GetX() == newx && (*iter)->GetY() == curY  || newx > 640)
					{
						if ((*iter)->GetColor() != GetColor())
						{
							newxy.x = newx;
							rook.push_back(newxy);
						}
						checkX1 = false;

					}
				}
				break;
			}
			if (checkX1) // 검사를 통해 해당x좌표에서 같은 색깔의 피스가 있다면 그 뒤로는 삽입못하게 막는다.
			{
				newxy.x = newx;
				rook.push_back(newxy);
			}
			newx = curX - X * 80;
			switch (checkX2)
			{
			case true:
				for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
				{
					if ((*iter)->GetX() == newx && (*iter)->GetY() == curY || newx < 0 )
					{
						if ((*iter)->GetColor() != GetColor())
						{
							newxy.x = newx;
							rook.push_back(newxy);
						}
						 checkX2 = false;

					}
				}
				break;
			}
			if (checkX2)
			{
				newxy.x = newx;
				rook.push_back(newxy);
			}

		}

		for (int Y = 1; curY + Y * 80 < 640 || curY - Y * 80 > 0; Y++) // x좌표에서 그대로에서 y타일만 변화며 움직일수있는 타일설정
		{
			newxy.x = curX;
			int newy = curY + Y * 80;
			switch (checkY1)
			{
			case true:
				for (auto iter = pieces.begin(); iter < pieces.end(); iter++)// 검사를 통해 해당좌표에서 같은 색깔의 피스가 있다면 그 뒤로는 삽입못하게 막는다.
				{
					if ((*iter)->GetY() == newy && (*iter)->GetX() == curX  || newy > 640)
					{
						if ((*iter)->GetColor() != GetColor())
						{
							newxy.y = newy;
							rook.push_back(newxy);
						}
						checkY1 = false;

					}
				}
				break;
			}
			if (checkY1)
			{
				newxy.y = newy;
				rook.push_back(newxy);
			}

			newy = curY - Y * 80;
			switch (checkY2)
			{
			case true:
				for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
				{
					if ((*iter)->GetX() == curX && (*iter)->GetY() == newy  || newy < 0)
					{
						if ((*iter)->GetColor() != GetColor())
						{
							newxy.y = newy;
							rook.push_back(newxy);
						}
						checkY2 = false;

					}
				}
				break;
			}

			if (checkY2)
			{
				newxy.y = newy;
				rook.push_back(newxy);
			}
			
		}

		if (rook.size() == 0)
		{
			return false;
		}

		for (auto iter1 = rook.begin(); iter1 < rook.end(); iter1++) //타일설정
		{
			for (int iter = 0; iter < 64; iter++)
			{
				if (iter1->x == tiles[iter].GetTx() && iter1->y == tiles[iter].GetTy() )
				{
					tiles[iter].SetMoveableTiles();
				}
			}
		}
		rook.clear();
		return true;
	}
	
};