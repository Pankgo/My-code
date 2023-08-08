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
void BitMap::Draw(HDC hdc, int x, int y, int check,bool moveabletiles)
{
	int height, width;
	switch (check)
	{
	case Start:height = 100, width = 100; break; //시작버튼
	case Background:height = m_Size.cy, width = m_Size.cx;  break; //배경
	case Try: height = 100, width = 100;  break;//다시시작버튼
	case Tile: height = 80, width = 80; break; // 타일
	case Pieces: height = 80, width = 80;  break;
	}

	switch (check)
	{
	case Pieces:
		TransparentBlt(hdc, x, y, width, height, MemDC, 0, 0, m_Size.cx, m_Size.cy, RGB(255, 0, 255));
		break;
	case Tile:
		if (moveabletiles)
		{
			BLENDFUNCTION bf;
			ZeroMemory(&bf, sizeof(bf));
			bf.SourceConstantAlpha = 100; // 원하는 값(0 ~ 255)
			AlphaBlend(hdc, 100, 100, 50, 50, MemDC, 0, 0, 32, 32, bf);

		}
		else
		{
			StretchBlt(hdc, x, y, width, height, MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
		}
		
	default:
		StretchBlt(hdc, x, y, width, height, MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
	}

}
	

BitMap::~BitMap()
{
	DeleteObject(m_BitMap);
	DeleteDC(MemDC);
}
