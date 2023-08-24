#include <Windows.h>
#include "BackGround.h"
#include <vector>

#define WINDOWWIDTH 1000
#define WINDOWHEIGHT 500


class GameManager
{
	static GameManager* GameM;

	GameManager() {}


	HWND hwd;
	HDC hdc, backDC;

	int width, height;

	BackGround background1[5];
	BackGround background2[5];
	BackGround background3[5];


	HBITMAP MyCreateDIBSection(HDC hdc, int width, int height)
	{
		BITMAPINFO bm_info;
		ZeroMemory(&bm_info.bmiHeader, sizeof(BITMAPINFOHEADER));
		bm_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		// color bits : 1, 4, 8, 16, 24, 32
		// 1:흑백, 4:16색, 8:256색, 16:2^15색, 24,31:2^24색
		bm_info.bmiHeader.biBitCount = 24;
		bm_info.bmiHeader.biWidth = width; // 너비, 비트맵의 가로 픽셀 수.
		bm_info.bmiHeader.biHeight = height;// 높이, 비트맵의 세로 픽셀 수.
		bm_info.bmiHeader.biPlanes = 1; // 1로 고정, 반드시 1이어야 한다.
		LPVOID pBits;
		return CreateDIBSection(hdc, &bm_info, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
	}


public:
	static GameManager* GetInstance()
	{
		if (GameM == NULL)
			GameM = new GameManager;
		return GameM;
	}

	void Init(HWND _hwd);
	void Draw();
	void Update(float deltatime);
	void Release();
	void Destroy();
};