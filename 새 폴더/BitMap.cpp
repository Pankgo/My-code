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
void BitMap::Draw(HDC hdc, int x, int y, int check)
{
	int height, width;
	if (check == 1)//���
	{
		height = m_Size.cy, width= m_Size.cx;
	}
	else if (check == 0)//���۹�ư
	{
		height = 100, width = 100;
	}
	else  if (check == 2) // �ٽý��۹�ư
	{
		height = 100, width = 100;
	}
	else//ī��
	{
		height = 80, width = 80;
	}
	StretchBlt(hdc, x, y, width, height, MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
}

BitMap::~BitMap()
{
	DeleteObject(m_BitMap);
	DeleteDC(MemDC);
}
