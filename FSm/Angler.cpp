#include "Angler.h"
#include "AnglerOwnedState.h"

Angler::Angler(const int& id) :
	BaseGameEntity(id),
	m_Location(Location_Type::shack),
	m_nMoneyInBank(0),
	m_nfish(0),
	m_nbottle(3),
	m_nThirsty(0),
	m_nCurMoney(0),
	m_nHungry(0),
	m_nFatigue(0),
	m_pCurrState(GoHomeAndSleepTilRested::Instance()) { }

void Angler::Update()
{

	if (m_pCurrState)
	{
		m_pCurrState->Excute(this);
	}
}

void Angler::ChangeState(State* pState)
{
	assert(m_pCurrState && pState);

	m_pCurrState->Exit(this);
	m_pCurrState = pState;
	m_pCurrState->Enter(this);
}

void Angler::SetMoney(const int& value)
{
	m_nCurMoney += value;
}

void Angler::AddToWealth(const int& value)
{
	m_nMoneyInBank += value;
	if (m_nMoneyInBank < 0)
	{
		m_nMoneyInBank = 0;
	}
}


bool Angler::Thirsty() const
{
	if (THIRST_LEVEL <= m_nThirsty)
	{
		return true;
	}

	return false;
}

bool Angler::Hungry() const
{
	if (HUNGRY_LEVEL <= m_nHungry)
	{
		return true;
	}

	return false;
}

bool Angler::Fatigued() const
{
	if (TIREDNESS_THRESHOLD  < m_nFatigue)
	{
		return true;
	}

	return false;
}