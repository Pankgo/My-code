#include<stdio.h>
#include<Windows.h>
#include"Card.h"
#define CARDMAX 12


class GameManager
{
	enum page//ȭ������
	{
		Start,
		Game,
	};
	BitMap* startbutton;
	RECT startRect;
	int startb_x;
	int startb_y;
	int CurrStatue;//����������
	//Card Image[CARDMAX];
	
public:
	bool GameStartCheck(POINT point);//���ӽ��� �������� Ȯ��
	bool PageCheck();//������ ����Ȯ��
	void PageDraw(HDC hdc);//���� ������ �׸���
	GameManager();
	void GameP(HDC hdc);//����������
	void StartP(HDC hdc);//����������
	~GameManager();
};

