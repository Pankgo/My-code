#include "pieces.h"
#pragma once


class Pawn : public _Chess
{
	struct xy {
		int x, y;
		bool pass = true;
	};
	xy pawn[4];//������ �����ϼ� �ִ� ĭ �ִ� 2ĭ �밢���� ���� ������� �밢�� �� 2ĭ

public:
	bool SetMove(Tiles tiles[64], std::vector<_Chess*>pieces) override
	{
		xy newxy;
		newxy.pass = true;

		int pawncount = 0;
		int curY = GetY();
		int curX = GetX();

		int x1 = curX + 80;
		int x2 = curX - 80;
		int y1 = curY + 80;
		int y2 = curY - 80;


		switch (GetColor())
		{
		case _white:
			switch (!CheckPieces(curX, y1, pieces) ) // ��
			{
			case true:
				newxy.x = curX;
				newxy.y = y1;
				pawn[0] = newxy;
				break;
			default:
				pawn[0].pass = false;
				pawncount++;
			}
			switch (CheckPieces(x2, y1, pieces) && CheckColor(x2, y1, pieces)) // ���� �Ʒ� �˻�
			{
			case true:
				newxy.x = x2;
				newxy.y = y1;
				pawn[2] = newxy;
				break;
			default:
				pawn[2].pass = false;
				pawncount++;
			}
			switch (CheckPieces(x1, y1, pieces) && CheckColor(x1,y1,pieces))// ������ �Ʒ� �˻� ����ǽ� ������� ������
			{
			case true:
				newxy.x = x1;
				newxy.y = y1;
				pawn[3] = newxy;
				break;
			default:
				pawn[3].pass = false;
				pawncount++;
			}
			switch (!CheckPieces(curX, y1+80, pieces) && curY == 80)// 2ĭ �����ϼ��ִ���Ȯ��
			{
			case true:
				newxy.x = curX;
				newxy.y = y1+80;
				pawn[1] = newxy;
				break;
			default:
				pawn[1].pass = false;
				pawncount++;
			}

			break;
		case _black:
			switch (!CheckPieces(curX, y2, pieces)) // ��
			{
			case true:
				newxy.x = curX;
				newxy.y = y2;
				pawn[0] = newxy;
				break;
			default:
				pawn[0].pass = false;
				pawncount++;
			}
			switch (CheckPieces(x2, y1, pieces) && CheckColor(x2, y1, pieces)) // ���� �밢�� �˻�
			{
			case true:
				newxy.x = x2;
				newxy.y = y1;
				pawn[2] = newxy;
				break;
			default:
				pawn[2].pass = false;
				pawncount++;
			}
			switch (CheckPieces(x1, y2, pieces) && CheckColor(x1, y2, pieces))// ������ �밢�� ����ǽ� ������� ������
			{
			case true:
				newxy.x = x1;
				newxy.y = y2;
				pawn[3] = newxy;
				break;
			default:
				pawn[3].pass = false;
				pawncount++;
			}
			switch (!CheckPieces(curX, y2-80, pieces) && curY == 480)// 2ĭ �����ϼ��ִ���Ȯ��
			{
			case true:
				newxy.x = curX;
				newxy.y = y2-80;
				pawn[1] = newxy;
				break;
			default:
				pawn[1].pass = false;
				pawncount++;
			}

			break;
		}
		if (pawncount == 4)
		{
			return false;
		}

		for (int i = 0; i < 4; i++) //Ÿ�ϼ���
		{
			for (int iter = 0; iter < 64; iter++)
			{
				if (pawn[i].pass == true && pawn[i].x == tiles[iter].GetTx() && pawn[i].y == tiles[iter].GetTy())
				{
					tiles[iter].SetMoveableTiles();
				}
			}
		}

		
		return true;
	}
};