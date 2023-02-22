#include "Mecro.h"
#include "Character.h"
#include "Monster.h"

enum Select
{
	Attack,
	SpecialAttack,
	Defence,
	Run
};
class Dongeon
{
	Monster Monster;
public:
	void MainPlay(Player *ch);
	void ShowTurn();
	void ShowGameInfo();
};