#include "pieces.h"
#pragma once



class Horse : public _Chess
{
	struct xy {
		int x, y;
		bool pass = true;
	};
	xy horse[8];

public:

	bool SetMove(Tiles tiles[64], std::vector<_Chess*>pieces) override
	{
		int curX = GetX();
		int curY = GetY();
		xy _xy;
		_xy.pass = true;

		for (int x=-2; x <3; x++) // �� �ǽ��� �����ϼ� �ִ� ��ǥ ����;
		{
			_xy.x = curX + x * 80;
			if (_xy.x >= 0 && _xy.x < 640 )
			{
				switch (x)
				{
				case 1:
					_xy.y = curY - 160;
					if (_xy.y <= 0)
					{
						_xy.pass = false;
						
					}
					else
					{
						_xy.pass = true;
					}
					horse[4] = _xy;
					_xy.y = curY + 160;
					if (_xy.y > 640)
					{
						_xy.pass = false;
					}
					else
					{
						_xy.pass = true;
					}
					horse[5] = _xy;
					break;
				case -1:
					_xy.y = curY - 160;
					if (_xy.y <= 0)
					{
						_xy.pass = false;

					}
					else
					{
						_xy.pass = true;
					}
					horse[2] = _xy;
					_xy.y = curY + 160;
					if (_xy.y > 640)
					{
						_xy.pass = false;
					}
					else
					{
						_xy.pass = true;
					}
					horse[3] = _xy;
					break;
				case -2:
					_xy.y = curY - 80;
					if (_xy.y <= 0)
					{
						_xy.pass = false;

					}
					else
					{
						_xy.pass = true;
					}
					horse[0] = _xy;
					_xy.y = curY + 80;
					if (_xy.y > 640)
					{
						_xy.pass = false;
					}
					else
					{
						_xy.pass = true;
					}
					horse[1] = _xy;
					break;
				case 2:
					_xy.y = curY - 80;
					if (_xy.y <= 0)
					{
						_xy.pass = false;

					}
					else
					{
						_xy.pass = true;
					}
					horse[6] = _xy;
					_xy.y = curY + 80;
					if (_xy.y > 640)
					{
						_xy.pass = false;
					}
					else
					{
						_xy.pass = true;
					}
					horse[7] = _xy;
					break;
				}
			}
			else
			{
				_xy.pass = false;
			}
			

		}

		int knightcount = 0; // ��� �� �������̴� ���� Ȯ��
		for (int i = 0; i < 8; i++)
		{
			for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
			{
				if (horse[i].x == (*iter)->GetX() && horse[i].y == (*iter)->GetY())
				{
					if (GetColor() == (*iter)->GetColor())
					{
						horse[i].pass = false;
					}
				}
			}
		}
		
		if (knightcount == 8)
		{
			return false;
		}



		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j< 64; j++)
			{
				if (horse[i].x == tiles[j].GetTx() && horse[i].y == tiles[j].GetTy() && horse[i].pass == true) // �ݺ����� ���� �������� �����ϼ��ִ� ���� ��ǥ�� 
				{														//������ �ǵ��� ����(���� ����) ������
					tiles[j].SetMoveableTiles();
				}
			}
			horse[i].x = NULL;
			horse[i].y = NULL;
			horse[i].pass = true;
		}
		
		return true;
	}
};