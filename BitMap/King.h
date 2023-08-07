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

		int kingcount = 0;

		int x1 = curX + 80;
		int x2 = curX - 80;
		int y1 = curY + 80;
		int y2 = curY - 80;


		//�밢�� ����
		switch (CheckPieces(x2, y2, pieces)) // ���� �� �˻�
		{
		case true:
			_newxy.x = x2;
			_newxy.y = y2;
			king[0] = _newxy;
			break;
		default:
			kingcount++;
			king[0].pass= false;
		}
		switch (CheckPieces(x1, y2, pieces))// ������ �� �˻�
		{
		case true:
			_newxy.x = x1;
			_newxy.y = y2;
			king[1] = _newxy;
			break;
		default:
			king[1].pass = false;
			kingcount++;
		}
		switch ( CheckPieces(x2, y1, pieces)) // ���� �Ʒ� �˻�
		{
		case true:
			_newxy.x = x2;
			_newxy.y = y1;
			king[2] = _newxy;
			break;
		default:
			king[2].pass = false;
			kingcount++;
		}
		switch (CheckPieces(x1, y1, pieces))// ������ �Ʒ� �˻�
		{
		case true:
			_newxy.x = x1;
			_newxy.y = y1;
			king[3] = _newxy ;
			break;
		default:
			king[3].pass = false;
			kingcount++;
		}
		//�����¿�
		switch (CheckPieces(curX, y2, pieces)) // ��
		{
		case true:
			_newxy.x = curX;
			_newxy.y = y2;
			king[4] = _newxy;
			break;
		default:
			king[4].pass = false;
			kingcount++;
		}
		switch (CheckPieces(curX, y1, pieces))// ��
		{
		case true:
			_newxy.x = curX;
			_newxy.y = y1;
			king[5] = _newxy;
			break;
		default:
			king[5].pass = false;
			kingcount++;
		}
		switch (CheckPieces(x2, curY, pieces)) // ��
		{
		case true:
			_newxy.x = x2;
			_newxy.y = curY;
			king[6] = _newxy;
			break;
		default:
			king[6].pass = false;
			kingcount++;
		}
		switch (CheckPieces(x1, curY, pieces))// ��
		{
		case true:
			_newxy.x = x1;
			_newxy.y = curY;
			king[7] = _newxy;
			break;
		default:
			king[7].pass = false;
			kingcount++;
		}

		if (kingcount == 8)
		{
			return false;
		}
		for (int i = 0; i < 8; i++) //Ÿ�ϼ���
		{
			for (int iter = 0; iter < 64; iter++)
			{
				if ( king[i].pass == true && king[i].x == tiles[iter].GetTx() && king[i].y == tiles[iter].GetTy())
				{
					tiles[iter].SetMoveableTiles();
				}
			}
		}

		return true;
	}
};