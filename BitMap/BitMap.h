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
public:
	void Init(HDC hdc, char* FileName);
	void Draw(HDC hdc, int x, int y, int check, bool moveabletiles);
	inline SIZE GetSize()
	{
		return m_Size;
	}
	BitMap();
	~BitMap();
};
