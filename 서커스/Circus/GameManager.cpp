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

	int setx = 0;
	for (int i = 0; i < 5; i++)
	{
		background1[i].Init(hwd, setx);
		background2[i].Init(hwd, setx + 500);
		background3[i].Init(hwd, setx + 1000);
		setx += 100;
	}
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


	for (int i = 0; i < 5; i++)
	{
		background1[i].Draw(backDC);
		background2[i].Draw(backDC);
		background3[i].Draw(backDC);
	}

	///////////////////////////////////////////

	BitBlt(hdc, 0, 0, width, height, backDC, 0, 0, SRCCOPY);//�׸����Լ��߿� ��������� ó���ؼ� ���

	DeleteObject(backBitmap); // DC�� ���� X

}

void GameManager::Update(float deltatime)
{
	// TODO: ���⿡ �ڵ带 �ۼ�
	int setx = 1000;
	if (background1[4].GetX() < 0)
	{
		for (int i = 0; i < 5; i++)
		{
			background1[i].SetX(setx);
			setx += 100;
		}
	}
	if (background2[4].GetX() < 0)
	{
		setx = 0;
		for (int i = 0; i < 5; i++)
		{
			background2[i].SetX(setx);
			setx += 100;
		}
	}
	if (background3[4].GetX() < 0)
	{
		setx = 0;
		for (int i = 0; i < 5; i++)
		{
			background3[i].SetX(setx);
			setx += 100;
		}
	}
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