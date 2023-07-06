#pragma once
#include"BitMap.h"
#include<time.h>
#include"BitMapManager.h"

enum CARD
{
	CARD_FRONT,
	CARD_REAR,
	CARD_END
};

class Card
{
private:
	CARD m_eCardState;
	BitMap* m_pBitMap[CARD_END];
	//bool CanChangeState = true; // ī�� ���������ִ��� Ȯ��
	IMAGE checkImageIndex;
	int m_ix;
	int m_iy;
	RECT m_BitMapRect;

public:
	Card();
	void Init(IMAGE Index, int x, int y);
	void Draw(HDC hdc,CHECKIMAGE check);
	bool ColliderCheck(POINT point); //ī��� ���콺 ��ġ Ȯ��
	void ChangeState();//ī�� ���� ����
	bool GetCardState() { if (m_eCardState == CARD_FRONT)return true; else return false; }//ī�� ����Ȯ��
	int GetX(){ return m_ix; }
	int GetY() { return m_iy; }
	IMAGE CheckBitMap() { return checkImageIndex; }//��Ʈ�� Ȯ��
	/*bool getChangeState() {
		return CanChangeState;
	}*/
	/*void SetChangeState(bool result) {
		CanChangeState = result;
	}*/


	~Card();
};

