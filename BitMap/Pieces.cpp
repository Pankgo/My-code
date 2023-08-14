#include "pieces.h"

_Chess::_Chess(){}

void _Chess::Draw(HDC hdc, CHECKIMAGE check)// �׸��� �Լ�
{
	pieces_Image->Trans(hdc, P_x, P_y, check);
}

bool _Chess::Move(int T_x, int T_y, Tiles tiles[64], std::vector<_Chess*> *pieces) // ���õ� Ÿ���� xy��ǥ�� ������ �ǽ� ��ǥ ��ȯ
{
	selectpieces = false;
	P_x = T_x;
	P_y = T_y;
	pices_rect.left = T_x;
	pices_rect.top = T_y;
	pices_rect.right = pices_rect.left + 80;
	pices_rect.bottom = pices_rect.top + 80;
	for (int i = 0; i < 64; i++)
	{
		if (tiles[i].Getstate() == plusmoveable)
		{
			tiles[i].SetMoveableTiles();
		}
	}
	for (auto iter = pieces->begin(); iter < pieces->end(); iter++) // ����ǽ� ���
	{
		if ((*iter)->GetX() == P_x && (*iter)->GetY() == P_y && (*iter)->GetColor() != color)
		{
			if ((*iter)->GetType() == _King)
			{
				return true;
			}
			pieces->erase(iter);
			return false;
		}
	}
	return false;
}

void _Chess::SetXY(int x, int y,IMAGE index,Color _color, _piecesType _type)
{
	type = _type;
	color = _color;
	P_x = x;
	P_y = y;
	pices_rect.left = x;
	pices_rect.top = y;
	pices_rect.right = pices_rect.left + 80;
	pices_rect.bottom = pices_rect.top + 80;
	pieces_Image = BitMapManager::GetInstance()->GetImage(index);

}

bool _Chess::ColliderCheck(POINT point,int _color) //�⹰�� ���콺 ��ġ Ȯ��
{
	if (PtInRect(&pices_rect, point) && _color == color) 
	{ 
		selectpieces = true;
		return true; 
	}
	return false;
}



bool _Chess::CheckPieces(int x, int y, std::vector<_Chess*> pieces)
{
	if (x < 0 || x > 560)
	{
		return false;
	}
	if (y < 0 || y > 560)
	{
		return false;
	}
	for (auto iter1 = pieces.begin(); iter1 < pieces.end(); iter1++) //Ÿ�ϼ���
	{
		if (x == (*iter1)->GetX() && y == (*iter1)->GetY() )// �ش� ��ġ�� �ǽ��� ������� ����
		{
			if((*iter1)->GetColor() != GetColor())//���� ������ �ƴҰ�� ����
			{
				return true;
			}
			return false; // ���� ������ ��� false����
		}
	}
	if (type == _Pawn && P_x != x)
	{
		return false;
	}
	return true; // �ǽ��� ��� �̵������ϴ� true
}


