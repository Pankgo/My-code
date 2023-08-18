#pragma once

#include "BitMapManager.h"
#include "Tiles.h"

#define  MAXCHESSWIDTH 560
#define	 MAXCHESSHEIGHT 560


 enum Color
{
	_black,
	_white
};

enum _piecesType
{
	_King,
	_Queen,
	_Knight,
	_Rook,
	_Bishop,
	_Pawn
};

class _Chess {

	HDC MemDC;
	BitMap* pieces_Image; //피스이미지
	HBITMAP m_BitMap;
	SIZE m_Size;
	Color color;
	_piecesType type;
	RECT pices_rect; // 규격
	int P_x, P_y; // 현재 피스 위치
	bool selectpieces = false;
	int height = 80, width = 80;
	bool enemypieces = false;


public:
	_Chess();
	virtual std::vector<POINT> SetMove(std::vector<_Chess*>pieces) = 0; // 피스 움직이는 함수(각 피스마다 움직일수있는 칸이 다름)
	virtual void Set( int x, int y) = 0;

	bool Move(int T_x , int T_y, Tiles tiles[64], std::vector<_Chess*> *pieces);
	void Draw(HDC hdc, CHECKIMAGE check); // 그리는 함수

	void SetXY(int x, int y, IMAGE index,Color _color, _piecesType _type);// 정보 입력
	bool ColliderCheck(POINT point,int color); //기물과 마우스 위치 확인

	_piecesType GetType() { return type; }
	Color GetColor() { return color; }

	int GetX() { return P_x; }
	int GetY(){ return P_y; }

	bool CheckSelect() { if (selectpieces) { selectpieces = false; return true; } return false; }
	bool CheckPieces(int x, int y, std::vector<_Chess*>pieces); // 같은 색상인지 검사
	bool Checkenemy(){ return enemypieces; }
	void Changeselectpieces() { selectpieces = false; }

};