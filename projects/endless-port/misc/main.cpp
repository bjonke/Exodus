#define WIN32_LEAN_AND_MEAN
#include <crtdbg.h>
#include <windows.h>
#include <wininet.h>
#include <ctime>
#include <stack>
#include <vector>
using namespace std;

#include "../CGameEngine.h"
#include "../CIntroState.h"
#include "../misc/main.h"

//now let's include our bitmapobject definitions
#include "../graphics/CBitMapObject.h"
#include "../CFileManager.h"

extern bool Focused = true;
DWORD start_time;
/**********************************************************************
* Globaler
/*********************************************************************/
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);
bool GameInit(); // game initialization function
void GameLoop(); //where the game actually takes place
void GameDone(); //clean up! 
void DrawTile(int x, int y, int tile); //coordinates & tile type
void DrawMap(); //draw the whole map.. render function, basically
void NewBlock(); //create a new block!
void RotateBlock(); //rotate a block.. if you can!
void Move(int x, int y); //coordinates to move.
int CollisionTest(int nx, int ny); //test collision of blocks
void RemoveRow(int row); //remove a row.. that would be the 'x'.
void NewGame(); //make a new game!

HINSTANCE hInstMain=NULL; //main app handle
HWND hWndMain=NULL; //main window handle

//map for the program
CBitMapObject bmoMap;
//block images
CBitMapObject bmoBlocks;
CBitMapObject bmoButtons[100];
int Map[10][30+1]; //the game map!

/***************************************************************************************
	Main window entry point
****************************************************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   PSTR szCmdLine, int iCmdShow) 
{


/***************************************************************************************
	Sound init ends here
****************************************************************************************/

	CFileManager FileManager;
	std::fstream test;
	std::string LoadedObject;
	vector<std::string> LoadedVector;
	FileManager.FileLoader(test,"TestData.txt");
	FileManager.ObjectLoader(test,"ObjectData.txt",LoadedObject);
	FileManager.VectorLoader(test,"WeaponData.txt",LoadedVector);
	//assign instance to global variable
	hInstMain=hInstance;

	srand ( (unsigned int)time(NULL) );

	std::fstream cfg; 
	cfg.open("conf/cfg.txt", ios::in);

	reader.readCSV(cfg,csvCfg);
	cfg.close();

	
	MSG			msg = {0};
	WNDCLASSEX WndClsEx;// Populate the WNDCLASSEX structure
	WndClsEx.cbSize        = sizeof(WNDCLASSEX);
	WndClsEx.style         = CS_OWNDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	WndClsEx.lpfnWndProc   = WndProc;
	WndClsEx.cbClsExtra    = 0;
	WndClsEx.cbWndExtra    = 0;
	WndClsEx.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	WndClsEx.hCursor       = LoadCursor(NULL, IDC_ARROW);
	WndClsEx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClsEx.lpszMenuName  = NULL;
	WndClsEx.lpszClassName = "ExodusClass";
	WndClsEx.hInstance     = hInstMain;
	WndClsEx.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	// Register the class
	RegisterClassEx(&WndClsEx);
	
	hWndMain = CreateWindowEx(0,"ExodusClass",
		csvCfg.at(0).at(2).c_str(),
 			  WS_OVERLAPPEDWINDOW,
 			  CW_USEDEFAULT,
 			  CW_USEDEFAULT,
 			  CW_USEDEFAULT,
 			  CW_USEDEFAULT,
 			  NULL,
 			  NULL,
 			  hInstance,
 			  NULL);

	CGameEngine game;
	// initialize the engine
	game.Init(hWndMain, "Engine Test v1.0" );
	// load the intro
	game.ChangeState( CIntroState::Instance() );


	GameInit();
	ShowWindow(hWndMain, SW_SHOWNORMAL) ; //iCmdShow
	UpdateWindow(hWndMain);
	//msg.message != WM_QUIT

	while( game.Running() )
	{
		if(PeekMessage (&msg,0,0,0,PM_REMOVE))
		{
			if(msg.message==WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		game.HandleEvents();
		game.Update();
		game.Draw();
		GameLoop();
	}

	// cleanup the engine
	game.Cleanup();

	return(msg.wParam) ;
}

/*******************************************************************************
* LRESULT CALLBACK WndProc() sk�ter grovjobbet
/*******************************************************************************/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		{
			//check for escape key
			if(wParam==VK_ESCAPE)
			{
				DestroyWindow(hwnd);
				return(0);//handled message
			}
			//check for space key
			if(wParam==VK_F1)
			{
				SetWindowText(hwnd,"Start new game");
				BitBlt(bmoMap,0,0,bmoButtons[0].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[0],0,0,SRCAND);
				BitBlt(bmoMap,0,0,bmoButtons[0].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[10],0,0,SRCPAINT);
				//invalidate the window rect
				InvalidateRect(hWndMain,NULL,FALSE);

				return(0);//handled message
			}
			if(wParam==VK_F2)
			{
				SetWindowText(hwnd,"Continue saved game");
				return(0);//handled message
			}
			if(wParam==VK_F3)
			{
				SetWindowText(hwnd,"Preferences");
				return(0);//handled message
			}
			if(wParam==VK_F4)
			{
				SetWindowText(hwnd,"Credits");
				return(0);//handled message
			}
			if(wParam==VK_F5)
			{
				SetWindowText(hwnd,"Quit");
				return(0);//handled message
			}


		}
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
	case WM_DESTROY:
		PostQuitMessage (0);
		break;
	case WM_PAINT://the window needs repainting
		{
			//a variable needed for painting information
			PAINTSTRUCT ps;
			
			//start painting
			HDC hdc=BeginPaint(hwnd,&ps);

			//redraw the map
			BitBlt(hdc,0,0,1024,768,bmoMap,0,0,SRCCOPY);

			//end painting
			EndPaint(hwnd,&ps);
			
					
			//handled message, so return 0
			return(0);
		}break;
	case WM_MOUSEMOVE:
		//int X = GET_X_LPARAM(lParam);
		//int Y = GET_Y_LPARAM(lParam);
		break;
	}

	return DefWindowProc (hwnd, message, wParam, lParam) ;
}

bool GameInit()
{
	RECT rcTemp;
	SetRect(&rcTemp,0,0,1024,768);//160x480 client area
	AdjustWindowRect(&rcTemp,WS_BORDER | WS_SYSMENU | WS_CAPTION| WS_VISIBLE,FALSE);//adjust the window size based on desired client area
	SetWindowPos(hWndMain,NULL,0,0,rcTemp.right-rcTemp.left,rcTemp.bottom-rcTemp.top,SWP_NOMOVE);//set the window width and height

	//create map image
	HDC hdc=GetDC(hWndMain);
	
	bmoMap.Create(hdc,1024,768);
	FillRect(bmoMap,&rcTemp,(HBRUSH)GetStockObject(WHITE_BRUSH));
	ReleaseDC(hWndMain,hdc);

	bmoBlocks.Load(NULL,"./data/gfx/menu/menu-background.bmp");

	bmoButtons[0].Load(NULL,"./data/gfx/menu/StartNewGameMask.bmp");
	bmoButtons[1].Load(NULL,"./data/gfx/menu/ContinueSavedGameMask.bmp");
	bmoButtons[2].Load(NULL,"./data/gfx/menu/PreferencesMask.bmp");
	bmoButtons[3].Load(NULL,"./data/gfx/menu/CreditsMask.bmp");
	bmoButtons[4].Load(NULL,"./data/gfx/menu/QuitMask.bmp");

	bmoButtons[5].Load(NULL,"./data/gfx/menu/StartNewGameImage.bmp");
	bmoButtons[6].Load(NULL,"./data/gfx/menu/ContinueSavedGameImage.bmp");
	bmoButtons[7].Load(NULL,"./data/gfx/menu/PreferencesImage.bmp");
	bmoButtons[8].Load(NULL,"./data/gfx/menu/CreditsImage.bmp");
	bmoButtons[9].Load(NULL,"./data/gfx/menu/QuitImage.bmp");

	bmoButtons[10].Load(NULL,"./data/gfx/menu/QuitImageActive.bmp");
	//set the client area size
	/*
	RECT rcTemp;
	SetRect(&rcTemp,0,0,MAPWIDTH*TILESIZE+TILESIZE*GREY,MAPHEIGHT*TILESIZE);//160x480 client area
	AdjustWindowRect(&rcTemp,WS_BORDER | WS_SYSMENU | WS_CAPTION| WS_VISIBLE,FALSE);//adjust the window size based on desired client area
	SetWindowPos(hWndMain,NULL,0,0,rcTemp.right-rcTemp.left,rcTemp.bottom-rcTemp.top,SWP_NOMOVE);//set the window width and height

	//create map image
	HDC hdc=GetDC(hWndMain);
	
	bmoMap.Create(hdc,MAPWIDTH*TILESIZE+TILESIZE*GREY,MAPHEIGHT*TILESIZE);
	FillRect(bmoMap,&rcTemp,(HBRUSH)GetStockObject(BLACK_BRUSH));
	ReleaseDC(hWndMain,hdc);

	bmoBlocks.Load(NULL,"blocks.bmp");
	NewGame();
	*/
	return(true);//return success
}
#define TILESIZE 16
void DrawTile(int x,int y,int tile)//put a tile
{
	//mask first
	BitBlt(bmoMap,x*TILESIZE,y*TILESIZE,TILESIZE,TILESIZE,bmoBlocks,tile*TILESIZE,TILESIZE,SRCAND);
	//then image
	BitBlt(bmoMap,x*TILESIZE,y*TILESIZE,TILESIZE,TILESIZE,bmoBlocks,tile*TILESIZE,0,SRCPAINT);
}

void GameLoop()
{

	POINT cursorPos;
        GetCursorPos(&cursorPos);
        float x = 0;
        x = cursorPos.x; 
        float y = 0;
        y = cursorPos.y;

        char msg[50];

        sprintf(msg, "x: %.2f\n"
            "y : %.2f\n", x, y);


	if( (GetTickCount() - start_time) > 1000)
	{
		//Move(0,1);
		start_time=GetTickCount();
	}
/*	
for(int xmy=10; xmy< 11; xmy++)
		for(int ymx=0; ymx< 30; ymx++)
			DrawTile(xmy, ymx, 1);
//draw the map
	//loop through the positions
	for(int xmy=0;xmy< 10;xmy++)
		for(int ymx=0;ymx< 30;ymx++)
				DrawTile(xmy,ymx,Map[xmy][ymx]);
//draw preview block
	for(int xmy=0; xmy<4; xmy++)
		for(int ymx=0; ymx<4; ymx++)
				DrawTile(12+xmy, ymx,2);
*/
	BitBlt(bmoMap,0,0,bmoBlocks.GetWidth(),bmoBlocks.GetHeight(),bmoBlocks,0,0,SRCCOPY);

	BitBlt(bmoMap,0,0,bmoButtons[0].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[0],0,0,SRCAND);
	BitBlt(bmoMap,0,0,bmoButtons[0].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[5],0,0,SRCPAINT);

	BitBlt(bmoMap,0,60,bmoButtons[1].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[1],0,0,SRCAND);
	BitBlt(bmoMap,0,60,bmoButtons[1].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[6],0,0,SRCPAINT);

	BitBlt(bmoMap,0,120,bmoButtons[2].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[2],0,0,SRCAND);
	BitBlt(bmoMap,0,120,bmoButtons[2].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[7],0,0,SRCPAINT);

	BitBlt(bmoMap,0,180,bmoButtons[3].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[3],0,0,SRCAND);
	BitBlt(bmoMap,0,180,bmoButtons[3].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[8],0,0,SRCPAINT);
	
	BitBlt(bmoMap,0,240,bmoButtons[4].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[4],0,0,SRCAND);
	BitBlt(bmoMap,0,240,bmoButtons[5].GetWidth(),bmoButtons[0].GetHeight(),bmoButtons[9],0,0,SRCPAINT);
	//BitBlt(bmoMap,0,0,160,480,bmoBlocks,0,0,SRCAND);

	//invalidate the window rect
	InvalidateRect(hWndMain,NULL,FALSE);
}