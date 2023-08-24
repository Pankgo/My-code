#pragma once
#pragma comment(lib, "msimg32.lib") 
#include<Windows.h>



class BitMap
{
private:
	HDC MemDC;
	HBITMAP m_BitMap;
	HBITMAP OldBitmap; 
	SIZE m_Size;
public:
	void Init(HDC hdc, char* FileName);
	void Stretch(HDC hdc, int x, int y, int height, int width);
	void Trans(HDC hdc, int x, int y, int height, int width);
	inline SIZE GetSize()
	{
		return m_Size;
	}
	BitMap();
	~BitMap();
};
