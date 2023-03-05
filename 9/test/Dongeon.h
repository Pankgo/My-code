#include "Mecro.h"
#include "Character.h"
#include "Monster.h"
#define BossSpecial 7
#define BossDefence 5
#define Chance 3

#pragma once

enum Select
{
	Attack=1,
	SpecialAttack,
	Defence,
	Run
};
class Dongeon
{
	string menu[4] = { "일반 공격 ", "특수 공격 ", "방어 ", "도망치기 " };
	Monster Monster;
public:
	void MainPlay(Player *ch);
	void ShowTurn();
	void ShowGameInfo(Player ch);
};