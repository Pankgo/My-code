#pragma once
#pragma comment(lib, "msimg32.lib") 
#include<Windows.h>

enum type
{
Start,
Background,
Try,
Tile,
Pieces

};



class BitMap
{
private:
	HDC MemDC;
	HBITMAP m_BitMap;
	SIZE m_Size;
	HBITMAP alphaBitmap;
public:
	void Init(HDC hdc, char* FileName);
	void Alpha(HDC hdc, int x, int y,int check);
	void Trans(HDC hdc, int x, int y,int check);
	void Stretch(HDC hdc, int x, int y,int check);
	inline SIZE GetSize()
	{
		return m_Size;
	}
	BitMap();
	~BitMap();
};
