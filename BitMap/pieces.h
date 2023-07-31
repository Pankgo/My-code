#include "BitMapManager.h"
#include "Tiles.h"
#pragma once


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

	Color color;
	_piecesType type;
	IMAGE pieces; //피스 구분
	BitMap* pieces_Image; //피스이미지
	RECT pices_rect; // 규격
	int P_x, P_y; // 현재 피스 위치

public:
	_Chess();
	virtual void Move(std::vector <Tiles>* tiles, std::vector<std::shared_ptr<_Chess>>pieces) = 0; // 피스 움직이는 함수(각 피스마다 움직일수있는 칸이 다름)
	void SetXY(int x, int y, IMAGE Index);// 정보 입력
	void Draw(HDC hdc, CHECKIMAGE check); // 그리는 함수
	bool ColliderCheck(POINT point); //기물과 마우스 위치 확인
	_piecesType GetType() { return type; }
	Color GetColor() { return color; }
	int GetX() { return P_x; }
	int GetY(){ return P_y; }



};