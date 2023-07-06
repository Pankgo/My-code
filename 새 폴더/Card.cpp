#include "Card.h"

Card::Card()
{
	m_eCardState = CARD_REAR;
}


void Card::Init(IMAGE Index, int x, int y)
{
	checkImageIndex = Index;
	m_pBitMap[CARD_FRONT] = BitMapManager::GetInstance()->GetImage(Index);
	m_pBitMap[CARD_REAR] = BitMapManager::GetInstance()->GetImage(IMAGE_BLACK);
	m_ix = x;
	m_iy = y;
	m_BitMapRect.left = x;
	m_BitMapRect.top = y;
	m_BitMapRect.right = m_BitMapRect.left + 80;
	m_BitMapRect.bottom = m_BitMapRect.top + 80;
}
void Card::Draw(HDC hdc,CHECKIMAGE check)
{
	m_pBitMap[m_eCardState]->Draw(hdc, m_ix, m_iy,check);
}
bool Card::ColliderCheck(POINT point)
{
	if (PtInRect(&m_BitMapRect, point))
	{
		return true;
	}
	return false;
}

void Card::ChangeState()
{
	if (m_eCardState == CARD_FRONT)
		m_eCardState = CARD_REAR;
	else
		m_eCardState = CARD_FRONT;
}

Card::~Card()
{
}
