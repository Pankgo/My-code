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
	IMAGE pieces; //�ǽ� ����
	BitMap* pieces_Image; //�ǽ��̹���
	RECT pices_rect; // �԰�
	int P_x, P_y; // ���� �ǽ� ��ġ
	bool selectpieces = false;

protected:
	bool firstMove = false;

public:
	_Chess();
	virtual std::vector<POINT> SetMove(std::vector<_Chess*>pieces) = 0; // �ǽ� �����̴� �Լ�(�� �ǽ����� �����ϼ��ִ� ĭ�� �ٸ�)
	bool Move(int T_x , int T_y, Tiles tiles[64], std::vector<_Chess*> *pieces);
	void SetXY(int x, int y, IMAGE Index);// ���� �Է�
	void Draw(HDC hdc, CHECKIMAGE check); // �׸��� �Լ�
	bool ColliderCheck(POINT point,int color); //�⹰�� ���콺 ��ġ Ȯ��
	_piecesType GetType() { return type; }
	Color GetColor() { return color; }
	int GetX() { return P_x; }
	int GetY(){ return P_y; }
	bool CheckSelect() { if (selectpieces) { return true; } return false; }
	bool CheckPieces(int x, int y, std::vector<_Chess*>pieces); // ���� �������� �˻�
	bool CheckColor(int x, int y, std::vector<_Chess*>pieces); // ���� �˻�


};