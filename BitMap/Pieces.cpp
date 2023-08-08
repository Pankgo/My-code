#include "pieces.h"

_Chess::_Chess(){}

void _Chess::Draw(HDC hdc, CHECKIMAGE check)// 그리는 함수
{
	pieces_Image->Draw(hdc, P_x, P_y, check,false);

}

bool _Chess::Move(int T_x, int T_y, Tiles tiles[64], std::vector<_Chess*> *pieces) // 선택된 타일의 xy좌표를 가져와 피스 좌표 변환
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
	for (auto iter = pieces->begin(); iter < pieces->end(); iter++) // 상대피스 잡기
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
		color = _white;
		type = _Queen;
		break;
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

bool _Chess::ColliderCheck(POINT point,int _color) //기물과 마우스 위치 확인
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
	for (auto iter1 = pieces.begin(); iter1 < pieces.end(); iter1++) //타일설정
	{
		if (x == (*iter1)->GetX() && y == (*iter1)->GetY() )// 해당 위치에 피스가 있을경우 리턴
		{
			if((*iter1)->GetColor() != GetColor())//같은 색상이 아닐경우 리턴
			{
				return true;
			}
			return false; // 같은 색상일 경우 false리턴
		}
	}
	return true; // 피스가 없어도 이동가능하니 true
}


