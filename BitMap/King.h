#include "pieces.h"
#pragma once

class King : public _Chess
{
	struct xy {
		int x, y;
		bool pass = true;
	};
	xy king[8];
public:
	bool SetMove(Tiles tiles[64], std::vector<_Chess*>pieces) override
	{
		int curY = GetY();
		int curX = GetX();
		xy _newxy;
		_newxy.pass = true;
		int count = 0;
		for (int i = -1; i < 2; i++) // 초기 이동할수있는위치세팅
		{
			for (int j = -1; j < 2; j++)
			{
				_newxy.x = curX + -80 * i;
				_newxy.y = curY + -80 * i;
				if (_newxy.x != 0 && _newxy.y != 0)
				{
					king[count++] = _newxy;
				}
			}
		}

		int kingcount = 0; // 모두다 못움직이는지 확인
		for (int i = 0; i < 8; i++) // 같은 색깔의 피스가 있을경우 움직이지 못하도록한다.
		{
			for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
			{
				if (king[i].x == (*iter)->GetX() && king[i].y == (*iter)->GetY() && GetColor() == (*iter)->GetColor())
				{
					king[i].pass = false;
					kingcount++;
				}
			}
		}
		if (kingcount == 8)
		{
			return false;
		}


		for (int i = 0; i < 8; i++) //타일설정
		{
			for (int iter = 0; iter < 64; iter++)
			{
				if (king[i].x == tiles[iter].GetTx()&& king[i].y == tiles[iter].GetTy())
				{
					tiles[iter].SetMoveableTiles();
				}
			}
		}

		return true;
	}
};