#include "Tiles.h"

void Tiles::Draw(HDC hdc, CHECKIMAGE check, bool moveabletiles)
{
	tiles_Image->Stretch(hdc, t_x, t_y, Tile);
	if (_tileInfo == plusmoveable)
	{
		alphabitmap->Alpha(hdc, t_x, t_y, Tile);
	}
	
	
}

void Tiles::Init(IMAGE Index,int x,int y)
{
	_tileInfo = only;
	tiles_Image = BitMapManager::GetInstance()->GetImage(Index);
	alphabitmap = BitMapManager::GetInstance()->GetImage(IMAGE_MOVEABLETILE);
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

	if (PtInRect(&_tile, point) && _tileInfo == plusmoveable)
	{

		return true;
	}
	return false;
}
