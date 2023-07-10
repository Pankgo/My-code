#include"GameManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("CARDGAME");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//����
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	//Ŀ��
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//������ ���
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;	//���μ��� �Լ� ȣ��
	WndClass.lpszClassName = lpszClass;	//Ŭ���� �̸�
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOWWIDTH, WINDOWHEIGHT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)//lparam ���콺 wparam Ű����
{
	HDC hdc;
	PAINTSTRUCT ps;
	POINT Point;
	switch (iMessage)
	{
	case WM_CREATE:
		GameManager::GetInstance()->Init(hWnd);
		return 0;
	case WM_LBUTTONDOWN:
		Point.x = LOWORD(lParam);
		Point.y = HIWORD(lParam);
		if (GameManager::GetInstance()->ColliderCheck(Point,hWnd))//�̹��� ���� �ִ��� Ȯ��
			InvalidateRect(hWnd, NULL, true);

		//if (GameManager::GetInstance()->ColliderCheck(Point,GameManager::GetInstance()->PageCheck()))//�̹��� ���� �ִ��� Ȯ��
		//{
		//	switch (GameManager::GetInstance()->PageCheck())
		//	{
		//	case Start: GameManager::GetInstance()->GameStart(); break;//����ȭ�� �ϰ�� ���۹�ư Ȯ��
		//	case End:  GameManager::GetInstance()->GoHome();  ; break;
		//	default: 
		//		if (GameManager::GetInstance()->GetGameStop() == false)GameManager::GetInstance()->CardCheck(Point);
		//		else GameManager::GetInstance()->GameStop();
		//		break;//�������ϰ�� ī�� ������
		//	}
		//}
		////if()GameManager::GetInstance()->GameStop();
		//InvalidateRect(hWnd, NULL, true);

		return 0;
	case WM_TIMER:
		GameManager::GetInstance()->GameStop(hWnd);
		InvalidateRect(hWnd, NULL, true);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GameManager::GetInstance()->PageDraw(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}