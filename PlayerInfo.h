#pragma once
#include"Mecro.h"

class PlayerInfo//�÷��̾� ����
{

	int p_back = 5;//������ Ƚ��
	int py = 10;//�ʱ� ���� ��ġ y�� 
	int px = 10;//�ʱ� ���� ��ġ x��
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
	void Plusx(int i) {//�÷��̾� x�� ���ϱ�
		px += i;
	}
	void Plusy(int i) {//�÷��̾� y�� ���ϱ�
		py += i;
	}
	void Subx(int i) {//�÷��̾� x�� ����
		px -= i;
	}
	void Suby(int i) {//�÷��̾� y�� ����
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