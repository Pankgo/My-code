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
	bool selectpieces = false;

protected:
	bool firstMove = false;

public:
	_Chess();
	virtual std::vector<POINT> SetMove(std::vector<_Chess*>pieces) = 0; // 피스 움직이는 함수(각 피스마다 움직일수있는 칸이 다름)
	bool Move(int T_x , int T_y, Tiles tiles[64], std::vector<_Chess*> *pieces);
	void SetXY(int x, int y, IMAGE Index);// 정보 입력
	void Draw(HDC hdc, CHECKIMAGE check); // 그리는 함수
	bool ColliderCheck(POINT point,int color); //기물과 마우스 위치 확인
	_piecesType GetType() { return type; }
	Color GetColor() { return color; }
	int GetX() { return P_x; }
	int GetY(){ return P_y; }
	bool CheckSelect() { if (selectpieces) { return true; } return false; }
	bool CheckPieces(int x, int y, std::vector<_Chess*>pieces); // 같은 색상인지 검사
	bool CheckColor(int x, int y, std::vector<_Chess*>pieces); // 색깔 검사


};