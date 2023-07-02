#include "GameManager.h"

GameManager::GameManager()
{
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_DOG);//시작버튼생성
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
void GameManager::PageDraw(HDC hdc)//페이지 확인 후 그려내기
{
	if (CurrStatue == Start)
		StartP(hdc);
	else
		GameP(hdc);
}
void GameManager::StartP(HDC hdc)//시작화면 페이지
{
	startbutton->Draw(hdc, startb_x, startb_y);
}
GameManager::~GameManager()
{
}
void GameManager::GameP(HDC hdc)//게임화면 페이지
{

}
