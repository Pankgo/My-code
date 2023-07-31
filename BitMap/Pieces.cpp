#include "pieces.h"

_Chess::_Chess(){}

void _Chess::Draw(HDC hdc, CHECKIMAGE check)// �׸��� �Լ�
{
	pieces_Image->Draw(hdc, P_x, P_y, check);

}

void _Chess::Move(int T_x, int T_y) // ���õ� Ÿ���� xy��ǥ�� ������ �ǽ� ��ǥ ��ȯ
{
	P_x = T_x;
	P_y = T_y;
}

void _Chess::SetXY(int x, int y, IMAGE Index)
{
	switch (Index) // �Ŀ� ���õǾ����� �ǽ� ���� �� ������ �������� ���� ����
	{
	case IMAGE_BlackKing :
		color = _black;
		type = _King;
		break;
	case IMAGE_WhiteKing:
		color = _white;
		type = _King;
		break;
	case IMAGE_BlackQueen:
		color = _black;
		type = _Queen;
		break;
	case IMAGE_WhiteQueen:
		color = _black;
		type = _Queen;
	case IMAGE_BlackHorse:
		color = _black;
		type = _Knight;
		break;
	case IMAGE_WhiteHorse:
		color = _white;
		type = _Knight;
		break;
	case IMAGE_BlackBishop:
		color = _black;
		type = _Bishop;
		break;
	case IMAGE_WhiteBishop:
		color = _white;
		type = _Bishop;
		break;
	case IMAGE_BlackRook:
		color = _black;
		type = _Rook;
		break;
	case IMAGE_WhiteRook:
		color = _white;
		type = _Rook;
		break;
	case IMAGE_WhitePawn:
		color = _white;
		type = _Pawn;
	case IMAGE_BlackPawn:
		color = _black;
		type = _Pawn;
	}
	pieces = Index;
	pieces_Image = BitMapManager::GetInstance()->GetImage(Index);
	P_x = x;
	P_y = y;
	pices_rect.left = x;
	pices_rect.top = y;
	pices_rect.right = pices_rect.left + 80;
	pices_rect.bottom = pices_rect.top + 80;
}

bool _Chess::ColliderCheck(POINT point) //�⹰�� ���콺 ��ġ Ȯ��
{
	if (PtInRect(&pices_rect, point)) 
	{ 
		selectpieces = true;
		return true; 
	}
	return false;
}
