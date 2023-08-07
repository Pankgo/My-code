#include "pieces.h"
#pragma once


class Queen : public _Chess
{
	struct xy {
		int x, y;
		bool pass = true;
	};

	std::vector<xy> queen;
public:
	Queen() {};
	bool SetMove(Tiles tiles[64], std::vector<_Chess*>pieces) override
	{
		int curY = GetY();//현재 퀸의 x좌표
		int curX = GetX();//현재 퀸의 y좌표

		xy newxy;

		int count = 1;//한칸씩 대각선 좌표 변화(x + count*80, y - count* 80 or x - count * 80 ; y + count * 80)
		bool plus1 = true; //왼쪽 위 대각선
		bool plus2 = true; //오른쪽 위대각선
		bool plus3 = true; //왼쪽 아래 대각선
		bool plus4 = true; //오른쪽 아래 대각선

		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;

		//대각선처리
		for (int count = 1; plus1 == true || plus2 == true || plus3 == true || plus4 == true; count++) // 맵크기에서 벗어나면안됨
		{
			x1 = curX + count * 80;
			x2 = curX - count * 80;
			y1 = curY + count * 80;
			y2 = curY - count * 80;
			switch (plus1 && !CheckPieces(x2, y2, pieces) && x2 >= 0 && y2 >=0) // 왼쪽 위 검사
			{
			case true:
				newxy.x = x2;
				newxy.y = y2;
				queen.push_back(newxy);
				if (CheckColor(x2, y2, pieces))
				{
					plus1 = false;
				}
				break;
			case false:
				plus1 = false;
				break;
			}
			switch (plus2 && !CheckPieces(x1, y2, pieces) && x1 < 640 && y2 > 0)// 오른쪽 위 검사
			{
			case true:
				newxy.x = x1;
				newxy.y = y2;
				queen.push_back(newxy);
				if (CheckColor(x1, y2, pieces))
				{
					plus2 = false;
				}
				break;
			case false:
				plus2 = false;
				break;
			}
			switch (plus3 && !CheckPieces(x2, y1, pieces)&& x2 > 0 && y1 < 640) // 왼쪽 아래 검사
			{
			case true:
				newxy.x = x2;
				newxy.y = y1;
				queen.push_back(newxy);
				if (CheckColor(x2, y1, pieces))
				{
					plus3 = false;
				}
				break;
			case false:
				plus3 = false;
				break;
			}
			switch (plus4 && !CheckPieces(x1, y1, pieces) && x1 < 640 && y1 < 640)// 오른쪽 아래 검사
			{
			case true:
				newxy.x = x1;
				newxy.y = y1;
				queen.push_back(newxy);
				if (CheckColor(x1, y1, pieces))
				{
					plus4 = false;
				}
				break;
			case false:
				plus4 = false;
				break;
			}

		}
		//상하좌우 세팅
		count = 1; plus1 = plus2 = plus3 = plus4 = true;

		for (int count = 1; plus1 == true || plus2 == true || plus3 == true || plus4 == true; count++) // 맵크기에서 벗어나면안됨
		{
			x1 = curX + count * 80;
			x2 = curX - count * 80;
			y1 = curY + count * 80;
			y2 = curY - count * 80;
			switch (plus1 && !CheckPieces(curX, y2, pieces)) // 상
			{
			case true:
				newxy.x = curX;
				newxy.y = y2;
				queen.push_back(newxy);
				if (CheckColor(curX,y2, pieces))
				{
					plus1 = false;
				}
				break;
			case false:
				plus1 = false;
				break;
			}
			switch (plus2 && !CheckPieces(curX, y1, pieces))// 하
			{
			case true:
				newxy.x = curX;
				newxy.y = y1;
				queen.push_back(newxy);
				if (CheckColor(curX, y1, pieces))
				{
					plus2 = false;
				}
				break;
			case false:
				plus2 = false;
				break;
			}
			switch (plus3 && !CheckPieces(x2, curY, pieces)) // 좌
			{
			case true:
				newxy.x = x2;
				newxy.y = curY;
				queen.push_back(newxy);
				if (CheckColor(x2, curY, pieces))
				{
					plus3 = false;
				}
				break;
			case false:
				plus3 = false;
				break;
			}
			switch (plus4 && !CheckPieces(x1, curY, pieces))// 우
			{
			case true:
				newxy.x = x1;
				newxy.y = curY;
				queen.push_back(newxy);
				if (CheckColor(x1, curY, pieces))
				{
					plus4 = false;
				}
				break;
			case false:
				plus4 = false;
				break;
			}

		}

		if (queen.size() == 0)
		{
			return false;
		}


		for (auto iter1 = queen.begin(); iter1 < queen.end(); iter1++) //타일설정
		{
			for (auto iter2 = 0; iter2 < 64; iter2++)
			{
				if (iter1->x == tiles[iter2].GetTx() && iter1->y == tiles[iter2].GetTy())
				{
					tiles[iter2].SetMoveableTiles();
				}
			}
		}

		queen.clear();
		return true;
		
		// 십자가 타일선정
	}
};