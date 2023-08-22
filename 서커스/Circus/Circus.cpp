// Circus.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Circus.h"
#include "GameManager.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.              
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

void Draw(HWND hWnd, HDC hdc);
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDC_CIRCUS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);


    HWND hWnd = CreateWindowW(szWindowClass, L"CIRCUS", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // 애플리케이션 초기화를 수행합니다:
    MSG msg;


    ULONGLONG checkTime, limitTime = GetTickCount64();
    int fps = 1000 / 120; // 초당 몇회 갱신 ( 30,60,120.. => Fps)

    // 기본 메시지 루프입니다:
  
    GameManager::GetInstance()->Init(hWnd);
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
            checkTime = GetTickCount64();// clock() 흘러가는시간(로컬시스템시간x)
            if (checkTime >= limitTime)
            {
                float deltaTime = ((checkTime - limitTime) + fps) * 0.001f; // 한프레임이 몇초가 지났는지의 값(check 랑 limit 같을 경우 대비해서 fps 더함) 거리를 알기위해 필요한 변수
                limitTime = checkTime + fps;// 현재시간부터 지났을때의 값(갱신에 필요한값)
                GameManager::GetInstance()->Update(deltaTime);

  
            }
        }
    }
   
    GameManager::GetInstance()->Release();//DC초기화
    GameManager::GetInstance()->Destroy();//생성된 게임매니저 초기화

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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIRCUS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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


