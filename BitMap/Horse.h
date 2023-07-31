#include "pieces.h"
#pragma once



class Horse : public _Chess
{
	struct xy {
		int x, y;
	};
	std::vector<xy>horse;

public:

	void Move(std::vector<Tiles>* tiles, std::vector<std::shared_ptr<_Chess>>pieces) override
	{
		int curX = GetX();
		int curY = GetY();
		xy _xy;

		for (int x=-2; x <3; x++) // �� �ǽ��� �����ϼ� �ִ� ��ǥ ����;
		{
			_xy.x = curX + x * 80;
			if (_xy.x >= 0 )
			{
				switch (x)
				{
				case 1:
					_xy.y = curY - 160;
					horse.push_back(_xy);
					_xy.y = curY + 160;
					horse.push_back(_xy);
					break;
				case -1:
					_xy.y = curY - 160;
					horse.push_back(_xy);
					_xy.y = curY + 160;
					horse.push_back(_xy);
					break;
				case -2:
					_xy.y = curY - 80;
					horse.push_back(_xy);
					_xy.y = curY + 80;
					horse.push_back(_xy);
					break;
				case 2:
					_xy.y = curY - 80;
					horse.push_back(_xy);
					_xy.y = curY + 80;
					horse.push_back(_xy);
					break;
				}
			}
			

		}
		int length = 0;
		int maxSize = horse.size();
		bool stop = false;
		for (auto iter2 = horse.begin(); length< maxSize; length++)
		{
			for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
			{
				if ((*iter)->GetX() == iter2->x && (*iter)->GetY() == iter2->y) // �ݺ����� ���� ���� �����ǵ��� �ǽ����� ��ǥ�� 
				{
					horse.erase(iter2);
					maxSize = horse.size();
					stop = true;
					break;

				}
			}
			if (!stop)
			{
				iter2++;
			}
		}

		for (auto iter = horse.begin(); iter < horse.end(); iter++)
		{
			for (auto iter2 = tiles->begin(); iter2 < tiles->end(); iter2++)
			{
				if (iter->x == iter2->GetTx() && iter->y== iter2->GetTy()) // �ݺ����� ���� �������� �����ϼ��ִ� ���� ��ǥ�� 
				{														//������ �ǵ��� ����(���� ����) ������
					iter2->SetMoveableTiles();
				}
			}
		}


	}
};