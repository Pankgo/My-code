#include <iostream>
#include "BitMapManager.h"


enum PIECES
{
	PIECES_MOVE,
	PIECES_NONMOVE,
	PIECES_END
};



class Chess {

	IMAGE pices; //피스 구분
	BitMap* pices_Image; //피스이미지
	RECT pices_rect; // 규격
	int P_x, P_y; // 현재 피스 위치
	PIECES mypieces_state;//피스가 움직일수 있는지 없는지확인
	

public:
	Chess();
	virtual void Move(); // 피스 움직이는 함수(각 피스마다 움직일수있는 칸이 다름)
	void Init(IMAGE Index, int x, int y); // 정보 입력
	void Draw(HDC hdc, CHECKIMAGE check); // 그리는 함수
	bool ColliderCheck(POINT point); //기물과 마우스 위치 확인






};