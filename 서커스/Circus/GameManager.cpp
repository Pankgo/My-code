#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

void GameManager::Init(HWND _hwd)
{
	hwd = _hwd;
	hdc = GetDC(hwd);
	backDC = CreateCompatibleDC(hdc);

	RECT clientRect; // 클라이언트 크기
	GetClientRect(hwd, &clientRect);

	height = clientRect.bottom+1;
	width = clientRect.right+1;
}

void GameManager::Release()
{
	DeleteDC(backDC);
	ReleaseDC(hwd, hdc);
}

void GameManager::Draw()
{
	HBITMAP backBitmap = MyCreateDIBSection(hdc, width, height);
	SelectObject(backDC, backBitmap);

	///////////////////////////////////////////
	//TODO: 여기에 그림을 그리기 위한 코드를 작성


	///////////////////////////////////////////

	BitBlt(hdc, 0, 0, width, height, backDC, 0, 0, SRCCOPY);//그리는함수중에 가장빠르게 처리해서 사용

	DeleteObject(backBitmap); // DC는 삭제 X

}

void GameManager::Update(float deltatime)
{
	// TODO: 여기에 코드를 작성

	Draw();
}
void GameManager::Destroy()
{
	if (GameM != NULL)
	{
		delete GameM;
		GameM = NULL;
	}
}