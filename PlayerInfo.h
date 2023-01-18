#pragma once
#include"Mecro.h"

class PlayerInfo//플레이어 정보
{

	int p_back = 5;//무르기 횟수
	int py = 10;//초기 시작 위치 y값 
	int px = 10;//초기 시작 위치 x값
	int turn = 1;



public:
	inline int retPx()
	{
		return(px);
	}
	inline int retPy()
	{
		return(py);
	}
	void Plusx(int i) {//플레이어 x값 더하기
		px += i;
	}
	void Plusy(int i) {//플레이어 y값 더하기
		py += i;
	}
	void Subx(int i) {//플레이어 x값 뺴기
		px -= i;
	}
	void Suby(int i) {//플레이어 y값 빼기
		py -= i;
	}
	void StartTurn()
	{
		turn = 0;
	}
	void EndTurn()
	{
		turn = 0;
	}
	int RetTurn()
	{
		return turn;
	}



};