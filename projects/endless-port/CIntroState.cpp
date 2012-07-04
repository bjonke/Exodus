
#include <stdio.h>

#include "CGameEngine.h"
#include "CGameState.h"
#include "CIntroState.h"
//#include "playstate.h"

CIntroState CIntroState::m_IntroState;

void CIntroState::Init()
{
	printf("CIntroState Init\n");
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
}

void CIntroState::Update(CGameEngine* game) 
{
}

void CIntroState::Draw(CGameEngine* game) 
{
}
