#include<stdio.h>
#include<Windows.h>
#include"pieces.h"
#include"time.h"
#include <string>
#include <vector>
#include "BitMap.h"

//������ Ʋ ���� ������ �־�ߵȴ�


enum page//ȭ������
{
	Start,
	Game,
	End
};

class GameManager
{
	static GameManager* GameM;
	struct Getxy //ī�弼�ÿ� �ʿ��� xy��ǥ ����ü
	{
		int x, y;
	};


	BitMap* startbutton; // ���۹�ư�̹���
	BitMap* BackGround; // ��׶����̹���
	BitMap* tryagain; // Ʈ���̾�չ�ư

	RECT startRect;
	RECT BackGroundRect;
	RECT tryAgain;

	int startb_x, startb_y;//���۹�ư��ġ
	int Back_X, Back_y;//��׶��� ��ġ
	int try_x, try_y;
	int cardcount = 0; //ī��� ���µǾ��ִ��� Ȯ��
	int CurrStatue;//����������
	bool gamestop = false;

public:
	static GameManager* GetInstance()
	{
		if (GameM == NULL)
			GameM = new GameManager;
		return GameM;
	}
	void GameStart();//����ȭ���ΰ�� ���ӽ������� ���º���
	page PageCheck();//������ ����Ȯ��
	void PageDraw(HDC hdc);//���� ������ �׸���
	GameManager();
	void GameP(HDC hdc);//����������
	void StartP(HDC hdc);//����������
	void EndP(HDC hdc);
	~GameManager();
	bool ColliderCheck(POINT point, HWND hWnd);
	void Init(HWND hWnd)
	{
		BitMapManager::GetInstance()->Init(hWnd);

	}

	void GameStop(HWND hWnd);
	void GoHome();
	bool GetGameStop() { return gamestop; }
};