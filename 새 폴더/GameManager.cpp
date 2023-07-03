#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

GameManager::GameManager()
{
	BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //��׶��� �̹��� ����
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_DOG);//���۹�ư����
	Back_X = 0, Back_y = 0;
	startb_x = 150,startb_y = 300;
	
	BackGroundRect.left = 500;
	BackGroundRect.top = 500;
	BackGroundRect.right = 700;
	BackGroundRect.bottom = 700;

	startRect.left = 0;
	startRect.top = 0;
	startRect.right = 30;
	startRect.bottom = 30;


}

bool GameManager::PageCheck() {//������Ȯ��
	if (CurrStatue == Start)
		return true;
	return false;
}
bool GameManager::GameStartCheck(POINT point)
{
	if (PtInRect(&startRect, point))
	{
		if (CurrStatue == Start)
			CurrStatue = Game;
		return true;
	}
	return false;
}
void GameManager::PageDraw(HDC hdc)//������ Ȯ�� �� �׷�����
{
	BackGround->Draw(hdc, Back_X, Back_y);
	if (CurrStatue == Start)
		StartP(hdc);
	else
		GameP(hdc);
}
void GameManager::StartP(HDC hdc)//����ȭ�� ������
{
	/*for (int i = 0; i < NORMAL; i++)
	{
		int randImage = rand()%11;
		switch ((IMAGE)randImage)
		{
			case IMAGE_DOG:
				break;
			case IMAGE_DOG:
				break;
			case IMAGE_DOG:
				break;
			case IMAGE_DOG:
				break;
			case IMAGE_DOG:
				break;
			case IMAGE_DOG:
				break;
			case IMAGE_DOG:
				break;
			case IMAGE_DOG:
				break;

		}
	}*/
	startbutton->Draw(hdc, startb_x, startb_y);
}
void GameManager::GameP(HDC hdc)//����ȭ�� ������
{
	
}
GameManager::~GameManager()
{

}

void GameManager::Init(HWND hWnd)
{
	cards = new Card[NORMAL];
	BitMapManager::GetInstance()->Init(hWnd);
	delete[] cards;
}
