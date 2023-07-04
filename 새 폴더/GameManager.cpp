#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

GameManager::GameManager()
{
	BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //백그라운드 이미지 생성
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_DOG);//시작버튼생성
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

page GameManager::PageCheck() {//페이지확인
	if (CurrStatue == Start)
		return Start;
	return Game;
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
	BackGround->Draw(hdc, Back_X, Back_y,BACKGROUND);
	if (CurrStatue == Start)
		StartP(hdc);
	else
		GameP(hdc);
}
void GameManager::StartP(HDC hdc)//시작화면 페이지
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
	startbutton->Draw(hdc, startb_x, startb_y,STARTBUTTON);
}
void GameManager::GameP(HDC hdc)//게임화면 페이지
{
	
}
GameManager::~GameManager()
{

}

bool GameManager::CardCheck(POINT point)//카드체크
{
	return true;
}
bool GameManager::ColliderCheck(POINT point)//시작화면에서 시작버튼이미지 눌렀는지확인
{
	/*if (PtInRect(&startRect, point))
	{
		return true;
	}
	return false; */
	return true;
}
void GameManager::Init(HWND hWnd)
{
	BitMapManager::GetInstance()->Init(hWnd);
	cards.clear();
}
