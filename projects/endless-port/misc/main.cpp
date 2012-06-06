#include <crtdbg.h>
#include <windows.h>
#include <wininet.h>
#include <ctime>
#include <stack>
#include "../misc/main.h"

extern bool Focused = true;

/**********************************************************************
* Globaler
/*********************************************************************/
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

/***************************************************************************************
	Main window entry point
****************************************************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   PSTR szCmdLine, int iCmdShow) 
{
	srand ( (unsigned int)time(NULL) );

	std::fstream cfg;
	cfg.open("conf/cfg.txt", ios::in);

	reader.readCSV(cfg,csvCfg);
	cfg.close();

	
	TCHAR szAppName[] = "Exodus";
	HWND hwnd;
	MSG			msg = {0};
	WNDCLASS	wndclass ;

	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc ;
	wndclass.cbClsExtra		= 0 ;
	wndclass.cbWndExtra		= 0 ;
	wndclass.hInstance		= hInstance ;
	wndclass.hIcon			= LoadIcon (hInstance, IDI_APPLICATION) ;
	wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground	= (HBRUSH) GetStockObject (BLACK_BRUSH) ;
	wndclass.lpszMenuName	= NULL ;
	wndclass.lpszClassName	= szAppName ;

	if (!RegisterClass (&wndclass))
	{
		xmllog.WriteLog("Main", "main", "Error", "RegisterClass failed", FILE_INFO);
		return 0;
	}
	else
	{
		xmllog.WriteLog("Main", "main", "Info", "RegisterClass initialized...", FILE_INFO);
	}

	hwnd = CreateWindow (szAppName,		// Window class name
						 TEXT ("Exodus"),	//window caption
						 WS_POPUPWINDOW,
						 CW_USEDEFAULT,
						 CW_USEDEFAULT,
						 1024,
						 768,
						 NULL,
						 NULL,
						 hInstance,
						 NULL) ;

	ShowWindow(hwnd, iCmdShow) ;
	UpdateWindow(hwnd);

	DEVMODE dm;	
	EnumDisplaySettings(NULL,ENUM_CURRENT_SETTINGS, &dm );
	ChangeDisplaySettingsEx(0,&dm,0,CDS_FULLSCREEN,0);

	DWORD			dwExStyle;			// Window Extended Style
	DWORD			dwStyle;
	dwExStyle=WS_EX_TOPMOST;			// Window Extended Style

	dwStyle=WS_POPUPWINDOW;
	RECT WindowRect = {0,0,dm.dmPelsWidth,dm.dmPelsHeight};

	//Get Screen resolution with height - taskbar height
	RECT WorkArea;
	SystemParametersInfo(SPI_GETWORKAREA, sizeof(RECT), &WorkArea,0);

	AdjustWindowRectEx(&WindowRect, dwStyle, false, dwExStyle);
	RECT rect = WindowRect;
	
	//MoveWindow(window_handle,0,0,WindowRect.right-WindowRect.left,WindowRect.bottom-WindowRect.top,1);	
	SetWindowPos(hwnd, NULL, 0, 0, (int)dm.dmPelsWidth, (int)dm.dmPelsHeight,
		SWP_NOACTIVATE | SWP_NOCOPYBITS | SWP_NOOWNERZORDER | SWP_NOREPOSITION | SWP_NOZORDER);

	while(msg.message != WM_QUIT)
	{
		if(PeekMessage (&msg,0,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// Execute code here...
		}
	}
	return(msg.wParam) ;
}

/*******************************************************************************
* LRESULT CALLBACK WndProc() sköter grovjobbet
/*******************************************************************************/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message)
	{
	case WM_TIMER:
		break;
	case WM_CREATE:
		break;
	case WM_CHAR:
		break;
	case WM_SETFOCUS:
		Focused = true;
		break;
	case WM_KILLFOCUS:
		Focused = false;
		break;
    case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage (0);
		break;
	case WM_MOUSEMOVE:
		//int X = GET_X_LPARAM(lParam);
		//int Y = GET_Y_LPARAM(lParam);
		break;
	}

	return DefWindowProc (hwnd, message, wParam, lParam) ;
}