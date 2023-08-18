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
	BitMap* alphabitmap;

	tile tile;
	RECT _tile;

	tiles_state _tileInfo;

public:
	void Init(IMAGE Index,int x,int y);
	void Draw(HDC hdc, CHECKIMAGE check, bool moveabletiles); // �׸��� �Լ�

	void SetMoveableTiles();
	bool ColliderCheck(POINT point); //�⹰�� ���콺 ��ġ Ȯ��

	int GetTx() { return t_x; }
	int GetTy() { return t_y; }
	tiles_state Getstate() { return _tileInfo; }
};