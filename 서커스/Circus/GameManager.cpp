#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

void GameManager::Init(HWND _hwd)
{
	hwd = _hwd;
	hdc = GetDC(hwd);
	backDC = CreateCompatibleDC(hdc);

	RECT clientRect; // Ŭ���̾�Ʈ ũ��
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
	//TODO: ���⿡ �׸��� �׸��� ���� �ڵ带 �ۼ�


	///////////////////////////////////////////

	BitBlt(hdc, 0, 0, width, height, backDC, 0, 0, SRCCOPY);//�׸����Լ��߿� ��������� ó���ؼ� ���

	DeleteObject(backBitmap); // DC�� ���� X

}

void GameManager::Update(float deltatime)
{
	// TODO: ���⿡ �ڵ带 �ۼ�

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