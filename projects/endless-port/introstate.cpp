
#include <stdio.h>
#include <Windows.h>

#include "gameengine.h"
#include "gamestate.h"
#include "introstate.h"
#include "playstate.h"

CIntroState CIntroState::m_IntroState;

void CIntroState::Init(HWND hwnd)
{
	SetWindowText(hwnd,"CIntroState Init");
	//printf("CIntroState Init\n");
}

void CIntroState::Cleanup()
{
	printf("CIntroState Cleanup\n");
}

void CIntroState::Pause()
{
	printf("CIntroState Pause\n");
}

void CIntroState::Resume()
{
	printf("CIntroState Resume\n");
}

void CIntroState::HandleEvents(CGameEngine* game)
{
/*
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_SPACE:
						game->ChangeState( CPlayState::Instance() );
						break;

					case SDLK_ESCAPE:
						game->Quit();
						break;
				}
				break;
		}
	}
	*/
}

void CIntroState::Update(CGameEngine* game) 
{
	printf("CIntroState Update\n");
}

void CIntroState::Draw(CGameEngine* game) 
{
	printf("CIntroState Draw\n");
}
