#include "Dongeon.h"

void Dongeon::ShowTurn()
{
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 <<". " << menu[i] << " ";
	}
	cout << endl;
}
void Dongeon::ShowGameInfo(Player ch)
{
	cout << " 현재 캐릭터 hp : " << ch.retHp() << " Level : " << ch.retLevel() << "공격력  : " << ch.retDamage();
	if (ch.retSpecialChance() == Chance)//특수공격이 가능한지 불가능한지 확인하여 출력을 달리한다.
	{
		cout << " 특수공격 가능";
	}
	else
	{
		cout << " 특수공격 불가{"<<3-ch.retSpecialChance()<<"회 남음}";
	}
	cout << endl;

	cout << " 현재 몬스터 hp : " << Monster.retHp() << "공격력 : " << Monster.retDamage()<<endl;
}



void Dongeon::MainPlay(Player *ch)
{
	int Number = 0;
	int select;
	int BossTurn;
	int nomalPDamage = ch->retDamage();//일반공격 설정
	int specialPDamage = nomalPDamage *2;//특수 공격 설정
	int checkbosspattern;
	int nomalMDamage = Monster.retDamage();
	int specialMDamage = nomalMDamage * 1.5f;
	bool playerDefence = false;//방어기회
	bool MonsterDefence = false;//방어기회
	int result = 0;
	Monster.setMonster(ch);//몬스터 설정
	ch->setPlayer();

	while (Monster.retHp() > 0 && ch->retHp()>0)
	{
		system("cls");
		ShowTurn();
		ShowGameInfo(*ch);

		BossTurn = rand() % 7+1;//랜덤숫자를 배출하여 1~7 까지 나오게 한뒤 7일 경우 특수공격 5인경우 방어로 설정
		cin >> select;
		if (select == SpecialAttack && ch->retSpecialChance() != Chance)//만약 특수공격을 골랐을때 특수공격기회가 없을 경우 선택못하도록한다.
		{
			cout << "특수 공격이 불가능합니다.";
			system("pause");
			continue;
		}
		switch (select)
		{
		case Attack:
			cout << "플레이어 일반공격!\n";
			break;
		case SpecialAttack:
			cout << "플레이어 특수공격!\n";//특수공격이 실행될경우 다시 기회를 초기화 시킨다.
			ch->getChance(-3);
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

		if(BossTurn == BossSpecial)
		{
			cout << "몬스터 특수공격!\n";
			checkbosspattern = SpecialAttack;
		
		}
		else if (BossTurn == BossDefence)
		{
			cout << "몬스터 공격방어!\n";
			MonsterDefence = true;
		}
		else
		{
			cout << "몬스터 일반공격!\n";
			checkbosspattern = Attack;
		}

		if (playerDefence)//플레이어 방어유무 확인하여 플레이어가 일반공격일경우 무시 특수 공격인경우 절반으로 감소
		{
			if (checkbosspattern == SpecialAttack)
			{
				result = specialMDamage / 2;
			}
			else 
			{
				result = 0;
			}
		}
		else
		{
			if (checkbosspattern == SpecialAttack)
			{
				result = specialMDamage;
			}
			else if(checkbosspattern == Attack)
			{
				result = nomalMDamage;
			}
		}
		
		ch->HpCal(result);

		result = nomalPDamage;
		if (MonsterDefence)//몬스터 방어유무 확인하여 플레이어가 일반공격일경우 무시 특수 공격인경우 절반으로 감소
		{
			result = 0;
			if (select == SpecialAttack)
			{
				result = specialPDamage / 2;
			}
		}
		if (result != 0 && select == Attack )//특수공격기회를 주는것은 일반공격 && 데미지가 0이 아니어야한다
		{
			ch->getChance(1);
		}
		Monster.HpCal(result);
		system("pause");
	}
	system("cls");

	if (Monster.retHp() <=0)//몬스터 체력을 확인하여 0일경우 게임종료
	{
		cout << "몬스터 사냥 성공 !";
		ch->getExp(Monster.retExp());
		if (ch->retExp() / 100 == ch->retLevel())
		{
			ch->LevelUp();
			ch->setMoney(Monster.retMoney());
		}

	}
	else if(ch->retHp() <= 0)
	{
		cout << "몬스터 사냥 실패 ! ";
	}
	system("pause");
}