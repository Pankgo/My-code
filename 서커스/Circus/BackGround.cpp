#include "BackGround.h"

void BackGround::Init(HWND hWnd, int setx)
{
	char buf[256];
	HDC hdc = GetDC(hWnd);
	for (int i = 0; i < 4; i++)
	{
		sprintf_s(buf, "서커스//back_%d.bmp", i+1);
		backgroundbit[i].Init(hdc, buf);
	}
	x = setx;
}

void BackGround::Draw(HDC hdc)
{
	backgroundbit[people1].Stretch(hdc, x, y, height, width); // 박수안치는 관중 그리기
	x -= 100;

}
