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
	BitMap* pieces_Image; //�ǽ��̹���
	HBITMAP m_BitMap;
	SIZE m_Size;
	Color color;
	_piecesType type;
	RECT pices_rect; // �԰�
	int P_x, P_y; // ���� �ǽ� ��ġ
	bool selectpieces = false;
	int height = 80, width = 80;
	bool enemypieces = false;


public:
	_Chess();
	virtual std::vector<POINT> SetMove(std::vector<_Chess*>pieces) = 0; // �ǽ� �����̴� �Լ�(�� �ǽ����� �����ϼ��ִ� ĭ�� �ٸ�)
	virtual void Set( int x, int y) = 0;

	bool Move(int T_x , int T_y, Tiles tiles[64], std::vector<_Chess*> *pieces);
	void Draw(HDC hdc, CHECKIMAGE check); // �׸��� �Լ�

	void SetXY(int x, int y, IMAGE index,Color _color, _piecesType _type);// ���� �Է�
	bool ColliderCheck(POINT point,int color); //�⹰�� ���콺 ��ġ Ȯ��

	_piecesType GetType() { return type; }
	Color GetColor() { return color; }

	int GetX() { return P_x; }
	int GetY(){ return P_y; }

	bool CheckSelect() { if (selectpieces) { selectpieces = false; return true; } return false; }
	bool CheckPieces(int x, int y, std::vector<_Chess*>pieces); // ���� �������� �˻�
	bool Checkenemy(){ return enemypieces; }
	void Changeselectpieces() { selectpieces = false; }

};