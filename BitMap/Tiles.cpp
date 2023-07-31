#include "Tiles.h"

void Tiles::Draw(HDC hdc, CHECKIMAGE check, bool moveabletiles)
{
	switch (_tileInfo)
	{
	case only:
		tiles_Image[only]->Draw(hdc, t_x, t_y, check);
		break;
	case plusmoveable :
		tiles_Image[plusmoveable]->Draw(hdc, t_x, t_y, check);
		break;
	}
	
}

void Tiles::Init(IMAGE Index,int x,int y)
{
	_tileInfo = only;
	tiles_Image[only] = BitMapManager::GetInstance()->GetImage(Index);
	tiles_Image[plusmoveable] = BitMapManager::GetInstance()->GetImage(IMAGE_MOVEABLETILE);
	t_x = x;
	t_y = y;
	_tile.left = x;
	_tile.top = y;
	_tile.right = _tile.left + 80;
	_tile.bottom = _tile.top + 80;
	switch (Index)
	{
	case IMAGE_BLACKTILE:
		tile = black;
		break;
	default:
		tile = white;

	}
}

void Tiles::SetMoveableTiles()
{
	if (_tileInfo == only)
	{
		_tileInfo = plusmoveable;
	}
	else
	{
		_tileInfo = only;
	}
}

bool Tiles::ColliderCheck(POINT point)
{
	if (_tileInfo == plusmoveable)
	{
		SetMoveableTiles();
		return true;
	}
	return false;
}
