#pragma once
#include"BitMap.h"
#include<vector>

enum IMAGE
{
	IMAGE_START,
	IMAGE_BlackKing = 0,
	IMAGE_BlackQueen,
	IMAGE_BlackHorse,
	IMAGE_BlackRook,
	IMAGE_BlackBishop,
	IMAGE_BlackPawn,
	IMAGE_WhiteKing,
	IMAGE_WhiteQueen,
	IMAGE_WhiteHorse,
	IMAGE_WhiteRook,
	IMAGE_WhiteBishop,
	IMAGE_WhitePawn,
	IMAGE_BACKGROUND,
	IMAGE_STARTBUTTON,
	IMAGE_TRY,
	IMAGE_WHITETILE,
	IMAGE_BLACKTILE,
	
	IMAGE_END

};
enum CHECKIMAGE
{
	STARTBUTTON,
	BACKGROUND,
	TRY,
	TILE,
	PiecesIMAGE
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
