#include "BackGround.h"

void BackGround::Init(HWND hWnd, int setx)
{
	char buf[256];
	HDC hdc = GetDC(hWnd);
	for (int i = 0; i < 4; i++)
	{
		sprintf_s(buf, "��Ŀ��//back_%d.bmp", i+1);
		backgroundbit[i].Init(hdc, buf);
	}
	x = setx;
}

void BackGround::Draw(HDC hdc)
{
	backgroundbit[people1].Stretch(hdc, x, y, height, width); // �ڼ���ġ�� ���� �׸���
	x -= 100;

}
