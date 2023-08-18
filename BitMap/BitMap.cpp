#include "BitMap.h"



BitMap::BitMap()
{
}

void BitMap::Init(HDC hdc,char* FileName)
{
	MemDC = CreateCompatibleDC(hdc);
	m_BitMap = (HBITMAP)LoadImageA(NULL, FileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);	
	SelectObject(MemDC, m_BitMap);
	BITMAP BitMap_Info;
	GetObject(m_BitMap, sizeof(BitMap_Info), &BitMap_Info);
	m_Size.cx = BitMap_Info.bmWidth;
	m_Size.cy = BitMap_Info.bmHeight;
}
void BitMap::Stretch(HDC hdc, int x, int y,int check)
{
	int height, width;
	switch (check)
	{
	case Start:
	case Try:
		height = 100; width = 100;
		break;
	default:
		height = 80; width = 80;
		break;
	}

	StretchBlt(hdc, x, y, width, height, MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);

}
void BitMap::Trans(HDC hdc, int x, int y,int check)
{
	int height, width;
	if (check == Start || check == Try)
	{
		height = 100; width = 100;
	}
	else
	{
		height = 80; width = 80;
	}

	TransparentBlt(hdc, x, y, width, height, MemDC, 0, 0, m_Size.cx, m_Size.cy, RGB(255, 0, 255));
}
void BitMap::Alpha(HDC hdc, int x, int y,int check)
{
	int height, width;
	if (check == Start || check == Try)
	{
		height = 100; width = 100;
	}
	else
	{
		height = 80; width = 80;
	}

	BLENDFUNCTION bf;
	ZeroMemory(&bf, sizeof(bf));
	bf.SourceConstantAlpha = 100; 
	//StretchBlt(hdc, x, y, width, height, MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);

	AlphaBlend(hdc, x, y, width, height, MemDC, 0, 0, m_Size.cx,  m_Size.cy, bf);
}

BitMap::~BitMap()
{
	DeleteObject(m_BitMap);
	DeleteDC(MemDC);
}
