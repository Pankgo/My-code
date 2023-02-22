#include "Dongeon.h"

void Dongeon::ShowTurn()
{
	cout << "1. 일반 공격 ";
	cout << "2. 특수 공격 ";
	cout << "3. 방어 ";
	cout << "4. 도망치기 ";
}
void Dongeon::ShowGameInfo()
{

}



void Dongeon::MainPlay(Player *ch)
{
	int Number = 0;
	int select;
	int BossTurn;
	int nomalPDamage = ch->retDamage();//일반공격 설정
	int specialPDamage = nomalPDamage *2;//특수 공격 설정
	int nomalMDamage = Monster.retDamage();
	int specialMDamage = nomalMDamage * 1.5f;
	bool playerDefence = false;//방어기회
	bool MonsterDefence = false;//방어기회
	int result = 0;
	while (Monster.retHp() == 0 || ch->retHp()==0)
	{
		system("cls");
		ShowTurn();

		BossTurn = rand() % 3;
		cin >> select;

		switch (select)
		{
		case Attack:
			cout << "플레이어 일반공격!\n";
			break;
		case SpecialAttack:
			cout << "플레이어 특수공격!\n";
			break;
		case Defence:
			cout << "플레이어 공격방어!\n";
			playerDefence = true;
			break;
		case Run:
			cout << "도망쳤습니다!\n";
			system("pause");
			return;
		}

		switch (BossTurn)
		{
		case Attack:
			cout << "몬스터 일반공격!\n";
			break;
		case SpecialAttack:
			cout << "몬스터 특수공격!\n";
			break;
		case Defence:
			cout << "몬스터 공격방어!\n";
			MonsterDefence = true;
			break;

		}

		result = nomalMDamage;
		if (playerDefence)
		{
			result = 0;
			if (BossTurn == SpecialAttack)
			{
				result = specialMDamage / 2;
			}
		}
		ch->HpCal(result);

		result = nomalPDamage;
		if (MonsterDefence)
		{
			result = 0;
			if (select == SpecialAttack)
			{
				result = specialPDamage / 2;
			}
		}
		Monster.HpCal(result);
		system("pause");
	}
	system("cls");

	if (Monster.retHp() == 0)
	{
		cout << "몬스터 사냥 성공 !";
		ch->getExp(Monster.retExp());
		if (ch->retExp() / 100 == ch->retLevel() + 1)
		{
			ch->setLevel();
			ch->setMoney(Monster.retMoney());
		}

	}
	else
	{
		cout << "몬스터 사냥 실패 ! ";
	}

}