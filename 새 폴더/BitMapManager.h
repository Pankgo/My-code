#pragma once
#include"BitMap.h"
#include<vector>

enum IMAGE
{
	IMAGE_START,
	IMAGE_DOG = 0,
	IMAGE_TIGER,
	IMAGE_DUCK,
	IMAGE_ELEPHANT,
	IMAGE_COW,
	IMAGE_HORSE,
	IMAGE_CAT,
	IMAGE_MONKEY,
	IMAGE_FROG,
	IMAGE_CHICKEN,
	IMAGE_COUNT,
	IMAGE_BLACK = IMAGE_COUNT,
	IMAGE_BACKGROUND,
	IMAGE_STARTBUTTON,
	IMAGE_TRY,
	IMAGE_END
	
};
enum CHECKIMAGE
{
	STARTBUTTON,
	BACKGROUND,
	TRY,
	CARDIMAGE
};

class BitMapManager
{
private:
	BitMap* m_parrBitMap;
	static BitMapManager* m_hThis;
public:
	static BitMapManager* GetInstance()
	{
		if (m_hThis == NULL)
			m_hThis = new BitMapManager;
		return m_hThis;
	}
	BitMap* GetImage(IMAGE index)
	{
		return &m_parrBitMap[index];
	}
	BitMapManager();
	void Init(HWND hWnd);
	~BitMapManager();
};

