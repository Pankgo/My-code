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
	//bool CanChangeState = true; // 카드 뒤집을수있는지 확인
	IMAGE checkImageIndex;
	int m_ix;
	int m_iy;
	RECT m_BitMapRect;

public:
	Card();
	void Init(IMAGE Index, int x, int y);
	void Draw(HDC hdc,CHECKIMAGE check);
	bool ColliderCheck(POINT point); //카드와 마우스 위치 확인
	void ChangeState();//카드 상태 변경
	bool GetCardState() { if (m_eCardState == CARD_FRONT)return true; else return false; }//카드 상태확인
	int GetX(){ return m_ix; }
	int GetY() { return m_iy; }
	IMAGE CheckBitMap() { return checkImageIndex; }//비트맵 확인
	/*bool getChangeState() {
		return CanChangeState;
	}*/
	/*void SetChangeState(bool result) {
		CanChangeState = result;
	}*/


	~Card();
};

