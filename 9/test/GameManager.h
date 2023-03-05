
#pragma once
#include "Mecro.h"
#include "Character.h"
#include "Monster.h"
#include "Dongeon.h"
#include "Shop.h"
#include "MapDraw.h"

enum CheckSave
{
	NonSave,
	Save
};
enum GameSelect
{
	Start =1,
	Shopping,
	Return,
	CurSave

};
class GameManager
{
	Shop shop;
	Player player;
	Dongeon dongeon;
	MapDraw mapDraw;
	int File[6] = {0};
	int Game_Height = 100;
	int Game_Width = 100;
public:
	GameManager();
	void UIDraw();// 게임 시작하기전 메인화면 드로잉
	void StartGame();//게임 시작하기
	bool LoadGame();//파일불러오기
	void UsingShop();//상점
	void Dongeon();//게임
	void MainMenu();
	void SubMenu();
	void GameSave();


};