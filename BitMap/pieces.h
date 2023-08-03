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

public:
	_Chess();
	virtual bool SetMove(Tiles tiles[], std::vector<_Chess*>pieces) = 0; // �ǽ� �����̴� �Լ�(�� �ǽ����� �����ϼ��ִ� ĭ�� �ٸ�)
	void Move(int T_x , int T_y, Tiles tiles[64]);
	void SetXY(int x, int y, IMAGE Index);// ���� �Է�
	void Draw(HDC hdc, CHECKIMAGE check); // �׸��� �Լ�
	bool ColliderCheck(POINT point); //�⹰�� ���콺 ��ġ Ȯ��
	_piecesType GetType() { return type; }
	Color GetColor() { return color; }
	int GetX() { return P_x; }
	int GetY(){ return P_y; }
	bool CheckSelect() { if (selectpieces) { return true; } return false; }
	void Catch( std::vector<_Chess*>pieces);//����ǽ��� �������
	bool CheckPieces(int x, int y, std::vector<_Chess*>pieces); // ���� �������� �˻�
	bool CheckColor(int x, int y, std::vector<_Chess*>pieces); // ���� �˻�


};