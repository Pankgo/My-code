#pragma once
#include"Mecro.h"

class PlayerInfo//플레이어 정보
{

	int p_back = 5;//무르기 횟수
	int py = 5;//초기 시작 위치 y값 
	int px = 5;//초기 시작 위치 x값
	int turn = 1;
	string Mouse = "";
	string Stone = "";



public:
	inline int retPx()
	{
		return(px);
	}
	inline int retPy()
	{
		return(py);
	}
	void Setx(int i) {//플레이어 x값 더하기
		px += i;
	}
	void Sety(int i) {//플레이어 y값 더하기
		py += i;
	}
	void StartTurn()
	{
		turn = 1;
	}
	void EndTurn()
	{
		turn = 0;
	}
	int RetTurn()
	{
		return turn;
	}
	void SetMouse(string mouse)
	{
		Mouse = mouse;
	}
	void SetStone(string stone)
	{
		Stone = stone;
	}



};