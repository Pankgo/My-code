// Test04.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Test.h"
#pragma comment(lib, "msimg32.lib") 

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

HBITMAP Chess, Dog; // 전역 변수.
float g_nX = 0; // 전역 변수.
void Draw(HWND hWnd, HDC hdc);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    HWND hWnd = CreateWindowW(szWindowClass, L"window", WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);


    Chess = (HBITMAP)LoadImage(NULL, L"block_w_00.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    Dog = (HBITMAP)LoadImage(NULL, L"00.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    HDC hdc = GetDC(hWnd);
    ULONGLONG checkTime, limitTime = GetTickCount64();
    ULONGLONG fps = 1000 / 120;

    MSG msg;

    // 게임 루프입니다:
    while (1)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT) break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            checkTime = GetTickCount64();
            if (limitTime <= checkTime)
            {
                float deltaTime = ((checkTime - limitTime) + fps) * 0.001f;
                limitTime = checkTime + fps;

                if (GetAsyncKeyState(VK_RIGHT)) {
                    g_nX += 200 * deltaTime;
                }
                if (GetAsyncKeyState(VK_LEFT)) {
                    g_nX -= 200 * deltaTime;
                }

                Draw(hWnd, hdc);
            }
        }
    }

    DeleteObject(Chess);
    DeleteObject(Dog);
    ReleaseDC(hWnd, hdc);

    return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


HBITMAP MyCreateDIBSection(HDC hdc, int width, int height)
{
    BITMAPINFO bm_info;
    ZeroMemory(&bm_info.bmiHeader, sizeof(BITMAPINFOHEADER));
    bm_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    // color bits : 1, 4, 8, 16, 24, 32
    // 1:흑백, 4:16색, 8:256색, 16:2^15색, 24,31:2^24색
    bm_info.bmiHeader.biBitCount = 24;
    bm_info.bmiHeader.biWidth = width; // 너비, 비트맵의 가로 픽셀 수.
    bm_info.bmiHeader.biHeight = height;// 높이, 비트맵의 세로 픽셀 수.
    bm_info.bmiHeader.biPlanes = 1; // 1로 고정, 반드시 1이어야 한다.
    LPVOID pBits;
    return CreateDIBSection(hdc, &bm_info, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
}
void Draw(HWND hWnd, HDC hdc)
{
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);

    HBITMAP backBitmap = MyCreateDIBSection(hdc, clientRect.right + 1, clientRect.bottom + 1);
    HDC backDC = CreateCompatibleDC(hdc);

    SelectObject(backDC, backBitmap);
    HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, Chess);
    TransparentBlt(backDC, 100 + g_nX, 100, 125, 125, memDC, 0, 0, 125, 125, RGB(255, 0, 255));
    SelectObject(memDC, oldBitmap);
    oldBitmap = (HBITMAP)SelectObject(memDC, Dog);
    BitBlt(backDC, 0, 0, 145, 245, memDC, 0, 0, SRCCOPY);
    StretchBlt(backDC, 200, 200, 245, 345, memDC, 0, 0, 145, 245, SRCCOPY);
    SelectObject(memDC, oldBitmap);
    DeleteDC(memDC);

    BitBlt(hdc, 0, 0, clientRect.right + 1, clientRect.bottom + 1, backDC, 0, 0, SRCCOPY);

    DeleteDC(backDC);
    DeleteObject(backBitmap);
}

int g_nGetKeyX = 0, g_nGetAsyncKeyX = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
