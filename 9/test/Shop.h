#include "Mecro.h"
#include "Character.h"
#include "Weapon.h"
#include "MapDraw.h"
#define Exit 6
#define MaxItemCount 5

#pragma once
enum sequence
{
	First,
	Second,
	Third,
	Fourth,
	Last
};
enum itemList
{
	Bow =1,
	Dagger,
	Sword,
	Wand,
	Hammer
};


class Shop
{
	MapDraw map;
	Weapon BowList[5];//"Bow","Dagger","Sword","Wand","Hammer"
	Weapon DaggerList[5];
	Weapon SwordList[5];
	Weapon WandList[5];
	Weapon HammerList[5];

public :
	void PtrWeapon(int Number);
	void ShopMenu();
	void SetData();
	void showItem(Player* player);
	void UsingShop(Player* player,int list);
};