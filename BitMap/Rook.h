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
		int curY = GetY();//���� ���� y��ǥ
		int curX = GetX();//���� ���� x��ǥ
		
		int count = 1;//��ĭ�� �����¿� ��ǥ ��ȭ(x + count*80, y - count* 80 or x - count * 80 ; y + count * 80)
		bool plus1 = true; //��
		bool plus2 = true; //��
		bool plus3 = true; //��
		bool plus4 = true; //��

		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;

		xy newxy;
		
		for (int count = 1; plus1 == true || plus2 == true || plus3 == true || plus4 == true; count++) // ��ũ�⿡�� �����ȵ�
		{
			x1 = curX + count * 80;
			x2 = curX - count * 80;
			y1 = curY + count * 80;
			y2 = curY - count * 80;
			switch (plus1 && CheckPieces(curX, y2, pieces)) // ��
			{
			case true:
				newxy.x = curX;
				newxy.y = y2;
				rook.push_back(newxy);
				if (CheckColor(curX, y2, pieces))
				{
					plus1 = false;
				}
				break;
			case false:
				plus1 = false;
				break;
			}
			switch (plus2 && CheckPieces(curX, y1, pieces))// ��
			{
			case true:
				newxy.x = curX;
				newxy.y = y1;
				rook.push_back(newxy);
				if (CheckColor(curX, y1, pieces))
				{
					plus2 = false;
				}
				break;
			case false:
				plus2 = false;
				break;
			}
			switch (plus3 && CheckPieces(x2, curY, pieces)) // ��
			{
			case true:
				newxy.x = x2;
				newxy.y = curY;
				rook.push_back(newxy);
				if (CheckColor(x2, curY, pieces))
				{
					plus3 = false;
				}
				break;
			case false:
				plus3 = false;
				break;
			}
			switch (plus4 && CheckPieces(x1, curY, pieces))// ��
			{
			case true:
				newxy.x = x1;
				newxy.y = curY;
				rook.push_back(newxy);
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

		if (rook.size() == 0)
		{
			return false;
		}

		for (auto iter1 = rook.begin(); iter1 < rook.end(); iter1++) //Ÿ�ϼ���
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