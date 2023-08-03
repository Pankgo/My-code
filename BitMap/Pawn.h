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

			if (curY == 80) // �ʱ� ȭ��Ʈ�� ��ġ���� Ȯ��
			{
				for (int i = 0; i < 64; i++)
				{

					if (tiles[i].GetTx() == curX && tiles[i].GetTy() == curY + 80  || tiles[i].GetTx() == curX && tiles[i].GetTy() == curY + 160 ) // �ݺ����� ���� �������� �����ϼ��ִ� ���� ��ǥ�� 
					{														//������ �ǵ��� ����(���� ����) ������ , ó�� ���� �����϶��� �ִ� 2ĭ���� �̵�����
						tiles[i].SetMoveableTiles();
						
					}
				}
			}
			else
			{
				for (int i = 0; i < 64; i++)
				{
					if (tiles[i].GetTy() == curY + 80 && tiles[i].GetTx() == curX) // �ݺ����� ���� �������� �����ϼ��ִ� ���� ��ǥ�� 
					{														//������ �ǵ��� ����(���� ����) ������
						tiles[i].SetMoveableTiles();
					}
				}
			}

			break;
		case _black:
			if (curY == 480) // �ʱ� ���� ��ġ���� Ȯ��
			{
				for (int i = 0; i < 64; i++)
				{
					if (tiles[i].GetTx() == curX && tiles[i].GetTy() == curY - 80 || tiles[i].GetTx() == curX && tiles[i].GetTy() == curY - 160) // �ݺ����� ���� �������� �����ϼ��ִ� ���� ��ǥ�� 
					{														//������ �ǵ��� ����(���� ����) ������ , ó�� ���� �����϶��� �ִ� 2ĭ���� �̵�����
						tiles[i].SetMoveableTiles();

					}
				}
			}
			else
			{
				for (int i = 0; i < 64; i++)
				{
					if (tiles[i].GetTy() == curY - 80 && tiles[i].GetTx() == curX) // �ݺ����� ���� �������� �����ϼ��ִ� ���� ��ǥ�� 
					{														//������ �ǵ��� ����(���� ����) ������
						tiles[i].SetMoveableTiles();
					}
				}
			}
			
			break;
		}

		return true;
	}
};