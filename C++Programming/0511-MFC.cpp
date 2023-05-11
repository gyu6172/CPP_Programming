#include <windows.h>
LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdLine, int nCmdShow)
{
    WNDCLASS wc;
    HWND hwnd;
    MSG msg;

    wc.style = 0;
    wc.lpfnWndProc = (WNDPROC)WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "MyWndClass";

    RegisterClass(&wc);

    hwnd = CreateWindow(
        "MyWndClass",               // WNDCLASS name
        "SDK Application",          // Window title
        WS_OVERLAPPEDWINDOW,        // Window style
        CW_USEDEFAULT,              // Horizontal position
        CW_USEDEFAULT,              // Vertical position        
        CW_USEDEFAULT,              // Initial width
        CW_USEDEFAULT,              // Initial height
        HWND_DESKTOP,               // Handle of parent window
        NULL,                       // Menu handle
        hInstance,                  // Application's instance handle
        NULL                        // Window-creation data
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam,
    LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message) {

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        Ellipse(hdc, 0, 0, 200, 100);

        RECT rect;
        GetClientRect(hwnd, &rect);
        DrawText(hdc, "hello, Windows", -1, &rect,
            DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        EndPaint(hwnd, &ps);

        return 0;

    case WM_LBUTTONUP:

        MessageBox(hwnd, "haha", "Test!", MB_OK);

        break;


    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;


    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}

//프로젝트 설정 변경
//1. 링커->시스템->콘솔에서 창으로 변경
//2. 고급->문자집합->유니코드에서 설정 안함으로 변경