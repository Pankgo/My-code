#include "GameManager.h"

GameManager::GameManager()
{
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_DOG);//���۹�ư����
	startb_x = 500;
	startb_y = 500;
	startRect.left = 500;
	startRect.top = 500;
	startRect.right = 1000;
	startRect.bottom = 1000;

}
bool GameManager::PageCheck() {
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
	if (CurrStatue == Start)
		StartP(hdc);
	else
		GameP(hdc);
}
void GameManager::StartP(HDC hdc)//����ȭ�� ������
{
	startbutton->Draw(hdc, startb_x, startb_y);
}
GameManager::~GameManager()
{
}
void GameManager::GameP(HDC hdc)//����ȭ�� ������
{

}
