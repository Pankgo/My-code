#include <iostream>
#include "BitMapManager.h"


enum PIECES
{
	PIECES_MOVE,
	PIECES_NONMOVE,
	PIECES_END
};



class Chess {

	IMAGE pices; //�ǽ� ����
	BitMap* pices_Image; //�ǽ��̹���
	RECT pices_rect; // �԰�
	int P_x, P_y; // ���� �ǽ� ��ġ
	PIECES mypieces_state;//�ǽ��� �����ϼ� �ִ��� ������Ȯ��
	

public:
	Chess();
	virtual void Move(); // �ǽ� �����̴� �Լ�(�� �ǽ����� �����ϼ��ִ� ĭ�� �ٸ�)
	void Init(IMAGE Index, int x, int y); // ���� �Է�
	void Draw(HDC hdc, CHECKIMAGE check); // �׸��� �Լ�
	bool ColliderCheck(POINT point); //�⹰�� ���콺 ��ġ Ȯ��






};