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
	string menu[4] = { "�Ϲ� ���� ", "Ư�� ���� ", "��� ", "����ġ�� " };
	Monster Monster;
public:
	void MainPlay(Player *ch);
	void ShowTurn();
	void ShowGameInfo(Player ch);
};