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
		for (int i = -1; i < 2; i++) // �ʱ� �̵��Ҽ��ִ���ġ����
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

		int kingcount = 0; // ��δ� �������̴��� Ȯ��
		for (int i = 0; i < 8; i++) // ���� ������ �ǽ��� ������� �������� ���ϵ����Ѵ�.
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


		for (int i = 0; i < 8; i++) //Ÿ�ϼ���
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