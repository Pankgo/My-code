#include "Merch.h"
#include "Block.h"
#include "Snake.h"

enum play
{
	Start = 1,
	End
};


class Gamemanager
{
	int insideWall = 10;
	Block block;
	SnakeInfo snake;
	int map_Width = 40;
	int map_Height = 30;
	int map[30][40];

public:
	Gamemanager();
	void MapDraw();//맵그리기
	void GamePlay();//게임플레이
	void UIDraw();//초기 시작화면
	void Menu(); // 메뉴
	void CheckCrash();//충돌확인



};