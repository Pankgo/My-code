#pragma once
#include"Mecro.h"

class PlayerInfo//�÷��̾� ����
{

	int p_back = 5;//������ Ƚ��
	int py = 10;//�ʱ� ���� ��ġ y�� 
	int px = 10;//�ʱ� ���� ��ġ x��
	int turn = 1;
	string Mouse = "";
	string Stone = "";
	int backchance = 10;



public:
	void Startp()
	{
		px = 10;
		py = 10;
	}
	inline int retPx()
	{
		return(px);
	}
	inline int retPy()
	{
		return(py);
	}
	void Setx(int i) {//�÷��̾� x�� ���ϱ�
		px += i;
	}
	void Sety(int i) {//�÷��̾� y�� ���ϱ�
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
	string RetStone()
	{
		return Stone;
	}
	string RetMouse()
	{
		return Mouse;
	}
	void Back()
	{
		if (backchance != 0)
		{
			backchance--;
		}
	}
	void Back(int i)
	{
		backchance = i;
	}
	int RetBack()
	{
		return backchance;
	}



};