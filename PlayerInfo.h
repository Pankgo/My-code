#pragma once
#include"Mecro.h"

class PlayerInfo//�÷��̾� ����
{

	int p_back = 5;//������ Ƚ��
	int turn = 1;
	
	int py = 20;//�ʱ� ���� ��ġ y�� 
	int px = 20;//�ʱ� ���� ��ġ x��
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