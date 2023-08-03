#include "pieces.h"
#pragma once


class Pawn : public _Chess
{
	

public:
	bool SetMove(Tiles tiles[64], std::vector<_Chess*>pieces) override
	{
		int curY = GetY();
		int curX = GetX();
		switch (GetColor())
		{
		case _white:

			if (curY == 80) // 초기 화이트폰 위치인지 확인
			{
				for (int i = 0; i < 64; i++)
				{

					if (tiles[i].GetTx() == curX && tiles[i].GetTy() == curY + 80  || tiles[i].GetTx() == curX && tiles[i].GetTy() == curY + 160 ) // 반복문을 돌려 나이츠의 움직일수있는 판의 좌표와 
					{														//동일한 판들의 정보(범위 여부) 보여줌 , 처음 폰이 움직일때는 최대 2칸까지 이동가능
						tiles[i].SetMoveableTiles();
						
					}
				}
			}
			else
			{
				for (int i = 0; i < 64; i++)
				{
					if (tiles[i].GetTy() == curY + 80 && tiles[i].GetTx() == curX) // 반복문을 돌려 나이츠의 움직일수있는 판의 좌표와 
					{														//동일한 판들의 정보(범위 여부) 보여줌
						tiles[i].SetMoveableTiles();
					}
				}
			}

			break;
		case _black:
			if (curY == 480) // 초기 블랙폰 위치인지 확인
			{
				for (int i = 0; i < 64; i++)
				{
					if (tiles[i].GetTx() == curX && tiles[i].GetTy() == curY - 80 || tiles[i].GetTx() == curX && tiles[i].GetTy() == curY - 160) // 반복문을 돌려 나이츠의 움직일수있는 판의 좌표와 
					{														//동일한 판들의 정보(범위 여부) 보여줌 , 처음 폰이 움직일때는 최대 2칸까지 이동가능
						tiles[i].SetMoveableTiles();

					}
				}
			}
			else
			{
				for (int i = 0; i < 64; i++)
				{
					if (tiles[i].GetTy() == curY - 80 && tiles[i].GetTx() == curX) // 반복문을 돌려 나이츠의 움직일수있는 판의 좌표와 
					{														//동일한 판들의 정보(범위 여부) 보여줌
						tiles[i].SetMoveableTiles();
					}
				}
			}
			
			break;
		}

		return true;
	}
};