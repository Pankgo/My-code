
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
	void UIDraw();// ���� �����ϱ��� ����ȭ�� �����
	void StartGame();//���� �����ϱ�
	bool LoadGame();//���Ϻҷ�����
	void UsingShop();//����
	void Dongeon();//����
	void MainMenu();
	void SubMenu();
	void GameSave();


};