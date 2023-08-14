#pragma once
#include <iostream>
#include "BitMapManager.h"


enum tile
{
	black,
	white
};
enum tiles_state
{
	only,
	plusmoveable
};

class Tiles
{
	int t_x, t_y;
	BitMap* tiles_Image;
	tile tile;
	RECT _tile;
	tiles_state _tileInfo;
	HBITMAP m_BitMap;
	HBITMAP alphaBitmap;

public:
	void Draw(HDC hdc, CHECKIMAGE check, bool moveabletiles); // 그리는 함수
	void Init(IMAGE Index,int x,int y);
	void SetMoveableTiles();
	int GetTx() { return t_x; }
	bool ColliderCheck(POINT point); //기물과 마우스 위치 확인
	int GetTy() { return t_y; }
	tiles_state Getstate() { return _tileInfo; }
};