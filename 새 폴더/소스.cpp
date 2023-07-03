#include"GameManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("CARDGAME");

#define CARDMAX 11

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//배경색
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	//커서
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//아이콘 모양
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;	//프로세스 함수 호출
	WndClass.lpszClassName = lpszClass;	//클레스 이름
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 490, 640,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)//lparam 마우스 wparam 키보드
{
	HDC hdc;
	PAINTSTRUCT ps;
	//static Card card;
	POINT Point;
	switch (iMessage)
	{
	case WM_CREATE:
		GameManager::GetInstance()->Init(hWnd);
		//BitMapManager::GetInstance()->Init(hWnd);
		//card.Init(IMAGE_DOG, 10, 10);

		return 0;
	case WM_LBUTTONDOWN:
		Point.x = LOWORD(lParam);
		Point.y = HIWORD(lParam);
		//if (card.ColliderCheck(Point))
		//{
		//	InvalidateRect(hWnd, NULL, true);
		//}
		/*if (GameManager::GetInstance()->PageCheck())
		{
			if (GameManager::GetInstance()->GameStartCheck(Point))
			{
				InvalidateRect(hWnd, NULL, true);
			}
		}
		else
		{
			if (card.ColliderCheck(Point))
			{
				InvalidateRect(hWnd, NULL, true);
			}
		}
		if (GameManager::GetInstance()->ColliderCheck(Point)
		{
			switch (PageCheck())
			{
			case main: return GameStartCheck(Point);
			default: return card.ColliderCheck(Point);
			}
		})
		{
			InvalidateRect(hWnd, NULL, true);
		}*/

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