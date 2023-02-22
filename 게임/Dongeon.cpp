#include "Dongeon.h"

void Dongeon::ShowTurn()
{
	cout << "1. �Ϲ� ���� ";
	cout << "2. Ư�� ���� ";
	cout << "3. ��� ";
	cout << "4. ����ġ�� ";
}
void Dongeon::ShowGameInfo()
{

}



void Dongeon::MainPlay(Player *ch)
{
	int Number = 0;
	int select;
	int BossTurn;
	int nomalPDamage = ch->retDamage();//�Ϲݰ��� ����
	int specialPDamage = nomalPDamage *2;//Ư�� ���� ����
	int nomalMDamage = Monster.retDamage();
	int specialMDamage = nomalMDamage * 1.5f;
	bool playerDefence = false;//����ȸ
	bool MonsterDefence = false;//����ȸ
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
			cout << "�÷��̾� �Ϲݰ���!\n";
			break;
		case SpecialAttack:
			cout << "�÷��̾� Ư������!\n";
			break;
		case Defence:
			cout << "�÷��̾� ���ݹ��!\n";
			playerDefence = true;
			break;
		case Run:
			cout << "�����ƽ��ϴ�!\n";
			system("pause");
			return;
		}

		switch (BossTurn)
		{
		case Attack:
			cout << "���� �Ϲݰ���!\n";
			break;
		case SpecialAttack:
			cout << "���� Ư������!\n";
			break;
		case Defence:
			cout << "���� ���ݹ��!\n";
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
		cout << "���� ��� ���� !";
		ch->getExp(Monster.retExp());
		if (ch->retExp() / 100 == ch->retLevel() + 1)
		{
			ch->setLevel();
			ch->setMoney(Monster.retMoney());
		}

	}
	else
	{
		cout << "���� ��� ���� ! ";
	}

}