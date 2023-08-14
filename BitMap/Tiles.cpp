#include "Tiles.h"

void Tiles::Draw(HDC hdc, CHECKIMAGE check, bool moveabletiles)
{
	switch (_tileInfo)
	{
	case only:
		tiles_Image->Stretch(hdc, t_x, t_y, Tile);
		break;
	case plusmoveable :
		tiles_Image->Stretch(hdc, t_x, t_y, Tile);
		tiles_Image->Alpha(hdc, t_x, t_y, Tile);
		break;
	}
	
}

void Tiles::Init(IMAGE Index,int x,int y)
{
	_tileInfo = only;
	tiles_Image = BitMapManager::GetInstance()->GetImage(Index);
	alphaBitmap = (HBITMAP)LoadImage(NULL, L"RES//017.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
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
