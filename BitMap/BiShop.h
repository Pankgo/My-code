#include "pieces.h"

class BiShop : public _Chess
{

	struct xy {
		int x, y;
		bool pass = true;
	}; 
	std::vector<xy> bishop;

public:
	std::vector<POINT>  SetMove(std::vector<_Chess*>pieces) override
	{
		int curY = GetY();
		int curX = GetX();
		
		int count = 1;//��ĭ�� �밢�� ��ǥ ��ȭ(x + count*80, y - count* 80 or x - count * 80 ; y + count * 80)
		bool plus1 = true; //���� �� �밢��
		bool plus2 = true; //������ ���밢��
		bool plus3 = true; //���� �Ʒ� �밢��
		bool plus4 = true; //������ �Ʒ� �밢��
		
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;

		xy newxy;
		newxy.pass = true;



		for(int count = 1; plus1 == true || plus2 == true || plus3 == true || plus4 == true; count++) // ��ũ�⿡�� �����ȵ�
		{
			x1 = curX + count * 80;
			x2 = curX - count * 80;
			y1 = curY + count * 80;
			y2 = curY - count * 80;
			switch (plus1&&CheckPieces(x2, y2, pieces)) // ���� �� �˻�
			{
			case true:
				newxy.x = x2;
				newxy.y = y2;
				bishop.push_back(newxy);
				if (CheckColor(x2, y2, pieces))
				{
					plus1 = false;
				}
				break;
			case false:
				plus1 = false;
				break;
			}
			switch (plus2 && CheckPieces(x1, y2, pieces))// ������ �� �˻�
			{
			case true:
				newxy.x = x1;
				newxy.y = y2;
				bishop.push_back(newxy);
				if (CheckColor(x1, y2, pieces))
				{
					plus2 = false;
				}
				break;
			case false:
				plus2 = false;
				break;
			}
			switch (plus3 && CheckPieces(x2, y1, pieces)) // ���� �Ʒ� �˻�
			{
			case true:
				newxy.x = x2;
				newxy.y = y1;
				bishop.push_back(newxy);
				if (CheckColor(x2, y1, pieces))
				{
					plus3 = false;
				}
				break;
			case false:
				plus3 = false;
				break;
			}
			switch (plus4 && CheckPieces(x1, y1, pieces))// ������ �Ʒ� �˻�
			{
			case true:
				newxy.x = x1;
				newxy.y = y1;
				bishop.push_back(newxy);
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

		if (bishop.size() == 0)
		{
			return false;
		}

		for (auto iter1 = bishop.begin(); iter1 < bishop.end(); iter1++) //Ÿ�ϼ���
		{
			for (auto iter2 = 0; iter2 < 64; iter2++)
			{
				if (iter1->x == tiles[iter2].GetTx() && iter1->y == tiles[iter2].GetTy())
				{
					tiles[iter2].SetMoveableTiles();
				}
			}
		}
		bishop.clear();
		return true;
	}



};