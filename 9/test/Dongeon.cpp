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
	cout << " ���� ĳ���� hp : " << ch.retHp() << " Level : " << ch.retLevel() << "���ݷ�  : " << ch.retDamage();
	if (ch.retSpecialChance() == Chance)//Ư�������� �������� �Ұ������� Ȯ���Ͽ� ����� �޸��Ѵ�.
	{
		cout << " Ư������ ����";
	}
	else
	{
		cout << " Ư������ �Ұ�{"<<3-ch.retSpecialChance()<<"ȸ ����}";
	}
	cout << endl;

	cout << " ���� ���� hp : " << Monster.retHp() << "���ݷ� : " << Monster.retDamage()<<endl;
}



void Dongeon::MainPlay(Player *ch)
{
	int Number = 0;
	int select;
	int BossTurn;
	int nomalPDamage = ch->retDamage();//�Ϲݰ��� ����
	int specialPDamage = nomalPDamage *2;//Ư�� ���� ����
	int checkbosspattern;
	int nomalMDamage = Monster.retDamage();
	int specialMDamage = nomalMDamage * 1.5f;
	bool playerDefence = false;//����ȸ
	bool MonsterDefence = false;//����ȸ
	int result = 0;
	Monster.setMonster(ch);//���� ����
	ch->setPlayer();

	while (Monster.retHp() > 0 && ch->retHp()>0)
	{
		system("cls");
		ShowTurn();
		ShowGameInfo(*ch);

		BossTurn = rand() % 7+1;//�������ڸ� �����Ͽ� 1~7 ���� ������ �ѵ� 7�� ��� Ư������ 5�ΰ�� ���� ����
		cin >> select;
		if (select == SpecialAttack && ch->retSpecialChance() != Chance)//���� Ư�������� ������� Ư�����ݱ�ȸ�� ���� ��� ���ø��ϵ����Ѵ�.
		{
			cout << "Ư�� ������ �Ұ����մϴ�.";
			system("pause");
			continue;
		}
		switch (select)
		{
		case Attack:
			cout << "�÷��̾� �Ϲݰ���!\n";
			break;
		case SpecialAttack:
			cout << "�÷��̾� Ư������!\n";//Ư�������� ����ɰ�� �ٽ� ��ȸ�� �ʱ�ȭ ��Ų��.
			ch->getChance(-3);
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

		if(BossTurn == BossSpecial)
		{
			cout << "���� Ư������!\n";
			checkbosspattern = SpecialAttack;
		
		}
		else if (BossTurn == BossDefence)
		{
			cout << "���� ���ݹ��!\n";
			MonsterDefence = true;
		}
		else
		{
			cout << "���� �Ϲݰ���!\n";
			checkbosspattern = Attack;
		}

		if (playerDefence)//�÷��̾� ������� Ȯ���Ͽ� �÷��̾ �Ϲݰ����ϰ�� ���� Ư�� �����ΰ�� �������� ����
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
		if (MonsterDefence)//���� ������� Ȯ���Ͽ� �÷��̾ �Ϲݰ����ϰ�� ���� Ư�� �����ΰ�� �������� ����
		{
			result = 0;
			if (select == SpecialAttack)
			{
				result = specialPDamage / 2;
			}
		}
		if (result != 0 && select == Attack )//Ư�����ݱ�ȸ�� �ִ°��� �Ϲݰ��� && �������� 0�� �ƴϾ���Ѵ�
		{
			ch->getChance(1);
		}
		Monster.HpCal(result);
		system("pause");
	}
	system("cls");

	if (Monster.retHp() <=0)//���� ü���� Ȯ���Ͽ� 0�ϰ�� ��������
	{
		cout << "���� ��� ���� !";
		ch->getExp(Monster.retExp());
		if (ch->retExp() / 100 == ch->retLevel())
		{
			ch->LevelUp();
			ch->setMoney(Monster.retMoney());
		}

	}
	else if(ch->retHp() <= 0)
	{
		cout << "���� ��� ���� ! ";
	}
	system("pause");
}