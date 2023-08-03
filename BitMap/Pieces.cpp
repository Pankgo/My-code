#include "pieces.h"

_Chess::_Chess(){}

void _Chess::Draw(HDC hdc, CHECKIMAGE check)// 그리는 함수
{
	pieces_Image->Draw(hdc, P_x, P_y, check);

}

void _Chess::Move(int T_x, int T_y, Tiles tiles[64]) // 선택된 타일의 xy좌표를 가져와 피스 좌표 변환
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
}

void _Chess::SetXY(int x, int y, IMAGE Index)
{
	switch (Index) // 후에 선택되었을때 피스 색깔 및 종류를 구분짓기 위해 세팅
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
		break;
	case IMAGE_BlackPawn:
		color = _black;
		type = _Pawn;
		break;
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

bool _Chess::ColliderCheck(POINT point) //기물과 마우스 위치 확인
{
	if (PtInRect(&pices_rect, point)) 
	{ 
		selectpieces = true;
		return true; 
	}
	return false;
}

void _Chess::Catch(std::vector<_Chess*>pieces) // 상대피스잡을경우
{

}

bool _Chess::CheckColor(int x, int y, std::vector<_Chess*> pieces)
{
	for (auto iter1 = pieces.begin(); iter1 < pieces.end(); iter1++) //타일설정
	{
		if (x == (*iter1)->GetX() && y == (*iter1)->GetY())// 해당 위치에 피스가 있을경우 리턴
		{
			if (GetColor() != (*iter1)->GetColor())
			{
				return true;
			}
			return false;
		}
	}
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
	for (auto iter1 = pieces.begin(); iter1 < pieces.end(); iter1++) //타일설정
	{
		if (x == (*iter1)->GetX() && y == (*iter1)->GetY() )// 해당 위치에 피스가 있을경우 리턴
		{
			if (GetColor() != (*iter1)->GetColor())
			{
				return true;
			}
			return false;
		}
	}
	return true;
}


