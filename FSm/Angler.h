#pragma once
#include "BaseGameEntity.h"
#include "Locations.h"
#include <cassert>

#define MAX_FISH		5	// ����� �ִ������
#define MAX_MONEY			10	// �ִ� ������.
#define MAX_BOTTLE			3	// �ִ빰����
#define HUNGRY_LEVEL			6
#define THIRST_LEVEL		5	// ���� �Ѱ�.
#define TIREDNESS_THRESHOLD	5	// �Ƿ� �Ѱ�.
#define COMFORT_LEVEL		50 // ���� ��

class Angler;
class State
{
public:
	virtual ~State() {}

	virtual void Enter(Angler*) abstract;
	virtual void Excute(Angler*) abstract;
	virtual void Exit(Angler*) abstract;
};

class Angler : public BaseGameEntity
{
private:
	

	State*			m_pCurrState;
	Location_Type	m_Location;
	int				m_nbottle; // �ִ� ������
	int				m_nfish;	// ���ΰ� ���꿡�� ĵ �ݵ����� ��.
	int				m_nMoneyInBank;	// ���� �ݾ�.
	int				m_nCurMoney;	//������
	int				m_nHungry;		// �����
	int				m_nThirsty;		// ������.
	int				m_nFatigue;		// �Ƿε�.

public:
	virtual ~Angler() {}
	Angler(const int& id);

	void Update() override;
	void ChangeState(State*);

	Location_Type Location() const { return m_Location; }
	void ChangeLocation(const Location_Type& loc_type) { m_Location = loc_type; }

	int FishCarried() const { return m_nfish; } // ����� ����Ȯ��
	void SetFishCarried(const int& value) { m_nfish += value; }// ����� �߰� Ȥ�� ����

	void SetMoney(const int& );// ������ ��ȭ
	int MoneyFull() const { return m_nCurMoney; } // ������ Ȯ��

	bool Hungry() const; // ����� Ȯ��
	void EatFish() { m_nfish--; m_nThirsty = 0; } // ������ذ�

	bool Fatigued() const;						// �Ƿε�Ȯ��
	void DecreaseFatigue() { m_nFatigue --; }   // �Ƿε� ����
	void IncreaseFatigue() { m_nFatigue++; }    // �Ƿε� ����

	int Wealth() const { return m_nMoneyInBank; } // ���� ������ ��Ȯ��
	void AddToWealth(const int&); // �� ����

	bool Thirsty() const; // �񸶸� Ȯ��
	void DrinkWater() { m_nThirsty = 0 ; m_nbottle -= 1; } // �񸶸� �ذ�
	void SetBottle(const int& value) { m_nbottle += value; } // ��������
	bool Bottle() { return(m_nbottle >0); } // ��������
};