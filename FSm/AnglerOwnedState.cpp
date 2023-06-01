#include "AnglerOwnedState.h"
#include "EntityNames.h"
#include "ConsoleUtils.h"

EnterFishAndFishing* EnterFishAndFishing::Instance()
{
	static EnterFishAndFishing instance;
	return &instance;
}

void EnterFishAndFishing::Enter(Angler* pAngler)
{
	if (pAngler->Location() != Location_Type::fish)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":�����ͷ� �ɾ��" << std::endl;

		pAngler->ChangeLocation(Location_Type::fish);
	}
}

void EnterFishAndFishing::Excute(Angler* pAngler)
{
	if (pAngler->CheckCount() == COUNT_FISHING)
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << "����⸦ ��Ҵ�!" << std::endl;
		pAngler->SetFishCarried(1);
		pAngler->CountFishing(-1); // �ٽ��ʱ�ȭ
	}
	else
	{
		pAngler->CountFishing(1);
	}

	
	pAngler->IncreaseHungry();
	pAngler->IncreaseThirsty();
	pAngler->IncreaseFatigue();

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << "������..." << std::endl;

	// ������ ����� �Ǹ�
	if (pAngler->FishCarried() == MAX_FISH)
	{
		// ������ �Ǹ�.
		pAngler->ChangeState(VisitShopAndBuyOrSell::Instance());
	}
	else
	{
		if (pAngler->Thirsty())	// ���� ������,
		{
			// �񸶸� �ؼҸ� ���� �ൿ.
			pAngler->ChangeState(QuenchThirst::Instance());
		}
		if (pAngler->Hungry())
		{
			// �񸶸� �ؼҸ� ���� �ൿ.
			pAngler ->ChangeState(QuenchHungry::Instance());
		}
		if (pAngler->Fatigued())
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << "�ǰ��ϴ� �����ΰ���..." << std::endl;
			pAngler->ChangeState(GoHomeAndSleepTilRested::Instance());
		}
	}

}

void EnterFishAndFishing::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << ":����� " << pAngler->FishCarried() << "���� ��Ҵ�!" << std::endl;
}
// -------------------------------------------------------------
// VisitShopAndBuyOrSell------------------------------------

VisitShopAndBuyOrSell* VisitShopAndBuyOrSell::Instance()
{
	static VisitShopAndBuyOrSell instance;
	return &instance;
}

void VisitShopAndBuyOrSell::Enter(Angler* pAngler)
{
	if (pAngler->Location() != Location_Type::shop)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":�������� �̵�" << std::endl;

		pAngler->ChangeLocation(Location_Type::shop);
	}
}

void VisitShopAndBuyOrSell::Excute(Angler* pAngler)
{
	if (pAngler->FishCarried() >= MAX_FISH)
	{
		// ����� �������� ��á�� ���
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		pAngler->SetFishCarried(-5);
		pAngler->SetMoney(5);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":\"����⸦ �Ǹ��Ͽ����ϴ�.\"" << std::endl;
		std::cout << GetNameOfEntity(pAngler->ID()) << ": ���� ��:" << pAngler->MoneyFull() << std::endl << std::endl;
		if (pAngler->MoneyFull() >= MAX_MONEY)
		{
			pAngler->ChangeState(VisitBankAndDepositGold::Instance());
		}
		else
		{
			// 
			pAngler->ChangeState(EnterFishAndFishing::Instance());
		}
	}
	else
	{
		// ���� �����Ͽ� ���� �緯 �Դ�.
		if (pAngler->FishCarried() == 0) // ������� ������ �ذ�
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << ":\"���� �Һ��Ͽ� ���� �缭 ����� �ذ�.\"" << std::endl;
			pAngler->SetMoney(-1);
			pAngler->EatFish();
		}
		else if (pAngler->MoneyFull() <= 0)
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << ":\"���� �����Ͽ� ������ �Ǹ��Ͽ� ������ ������ϴ�.\"" << std::endl;
			pAngler->SetFishCarried(-1);
			pAngler->SetBottle(2);
		}
		else
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << ":\"���� �Һ��Ͽ� ������ ������ϴ�.\"" << std::endl;
			pAngler->SetMoney(-1);
			pAngler->SetBottle(2);
		}
		pAngler->ChangeState(EnterFishAndFishing::Instance()); // ���� ȹ���� �Ǵ� ������� �ذ� �� �� �����ͷ� �̵�
	}
}
void VisitShopAndBuyOrSell::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << "������ ������." << std::endl;
}

// VisitBankAndDepositGold ------------------------------------

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Angler* pAngler)
{
	if (pAngler->Location() != Location_Type::bank)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":�������� �̵�" << std::endl;

		pAngler->ChangeLocation(Location_Type::bank);
	}
}

void VisitBankAndDepositGold::Excute(Angler* pAngler)
{
	pAngler->AddToWealth(pAngler->MoneyFull());

	pAngler->SetMoney(MAX_MONEY);

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << ":�� ����\n\n���� �ܱ�:" << pAngler->Wealth() << std::endl << std::endl;

	// ���� �ݾ��� Ȯ��,
	if (pAngler->Wealth() >= COMFORT_LEVEL)
	{
		// ������ ��ŭ ���� ��Ҵ�.
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":\"���! ���� ���� ���ڴ�. ���� �ִ� �Ƴ����Է� ���ư���.\"" << std::endl;

		pAngler->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else
	{
		// �����Ҹ��� ���� �ƴϾ �����ͷ� �̵�.
		pAngler->ChangeState(EnterFishAndFishing::Instance());
	}
}

void VisitBankAndDepositGold::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << ":������ ������" << std::endl;
}
// -------------------------------------------------------------

// GoHomeAndSleepTilRested -------------------------------------

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Angler* pAngler)
{
	if (pAngler->Location() != Location_Type::shack)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":������ ����" << std::endl;

		pAngler->ChangeLocation(Location_Type::shack);
	}
}

void GoHomeAndSleepTilRested::Excute(Angler* pAngler)
{
	// �Ƿε��� Ȯ��.
	if (pAngler->GetFatigued()==0)
	{
		// �Ƿΰ� �� �ʸ��� �ٽ� ���� ĳ������.
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":\"������ �þ����� ���! �����ͷ� ��������.\"" << std::endl;

		pAngler->ChangeState(EnterFishAndFishing::Instance());
	}
	else
	{
		// �ǰ��ϴ� ���� �ܴ�.
		pAngler->DecreaseFatigue();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":...zZ" << std::endl;
	}
}

void GoHomeAndSleepTilRested::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << ":���� ������" << std::endl;
}
// -------------------------------------------------------------

// QuenchThirst ------------------------------------------------
QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Angler* pAngler)
{
	std::cout << GetNameOfEntity(pAngler->ID()) << "���濡�� ���� ������" << std::endl;
}

void QuenchThirst::Excute(Angler* pAngler)
{
	// ������ �ִٸ�,
	if (pAngler->Thirsty())
	{
		if (pAngler->Bottle() == 0)
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << "�̷�! ���̾��� ..." << std::endl;
			pAngler->ChangeState(VisitShopAndBuyOrSell::Instance());
		}
		else
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << "���� ���ô� �ÿ��ϱ�!" << std::endl;
			pAngler->DrinkWater();
			pAngler->ChangeState(EnterFishAndFishing::Instance());
		}
		
		
	}
	else
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\nError!\nError!!\nError!!!" << std::endl;
	}
}
void QuenchThirst::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	if (pAngler->Thirsty())
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << " ����������! " << std::endl;
	}
	else
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << "������ �ذ������� �ٽ� ���ø� ����" << std::endl;
	}
}
// ----------------------------------------------------------

// QuenchHungry ---------------------------------------------

QuenchHungry* QuenchHungry::Instance()
{
	static QuenchHungry instance;
	return &instance;
}

void QuenchHungry::Enter(Angler* pAngler)
{
	std::cout << GetNameOfEntity(pAngler->ID()) << "���� ������� ������" << std::endl;
}

void QuenchHungry::Excute(Angler* pAngler)
{
	if (pAngler->FishCarried() == 0)
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << " �̷� ����Ⱑ ����! " << std::endl;
		pAngler->ChangeState(VisitShopAndBuyOrSell::Instance());
	}
	else
	{
		pAngler->EatFish();
		std::cout << GetNameOfEntity(pAngler->ID()) << " �߹����� �Ծ����! " << std::endl;
		pAngler->ChangeState(EnterFishAndFishing::Instance());
	}
}
void QuenchHungry::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	if (pAngler->Hungry())
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << " ����������! " << std::endl;
	}
	else
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << "������� �ذ������� �ٽ� ���ø� ����" << std::endl;
	}
	
}