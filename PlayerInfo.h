#pragma once
#include"Mecro.h"

class PlayerInfo//�÷��̾� ����
{

	int p_back = 5;//������ Ƚ��
	int py = 5;//�ʱ� ���� ��ġ y�� 
	int px = 5;//�ʱ� ���� ��ġ x��
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



};