#include "BitMap.h"
#include <stdio.h>

enum backgroundImage // 배경이미지 순서도
{
	greenfield,
	elephant,
	people1,
	people2

};

class BackGround
{
	BitMap backgroundbit[4];
	RECT backgroundRect;
	int height = 100, width = 100;
	int x = 0, y = 0;

public :
	void Init(HWND hWnd,int setx);
	void Draw(HDC hdc);
	int GetX()
	{
		return x;
	}
	void SetX(int setx)
	{
		x = setx;
	}
};