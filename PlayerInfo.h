#pragma once
#include"Mecro.h"

class PlayerInfo//플레이어 정보
{

	int p_back = 5;//무르기 횟수
	int turn = 1;
	
	int py = 20;//초기 시작 위치 y값 
	int px = 20;//초기 시작 위치 x값
	int stonepx[100] = { 0, };
	int stonepy[100] = { 0, };



public:
	inline int retPx()
	{
		return(px);
	}
	inline int retPy()
	{
		return(py);
	}
	void Plusx(int i) {
		px += i;
	}
	void Plusy(int i) {
		py += i;
	}
	void Subx(int i) {
		px -= i;
	}
	void Suby(int i) {
		py -= i;
	}



};