
#include <stdio.h>

#include "CGameEngine.h"
#include "CGameState.h"

void CGameEngine::Init(const char* title, int width, int height, 
						 int bpp, bool fullscreen)
{
	int flags = 0;

	// initialize Video

	// set the title bar text

	if ( fullscreen ) {
		flags = 0;
	}

	// create the screen surface

	m_fullscreen = fullscreen;
	m_running = true;

	printf("CGameEngine Init\n");
}

void CGameEngine::Cleanup()
{
	// cleanup the all states
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// switch back to windowed mode so other 
	// programs won't get accidentally resized
	if ( m_fullscreen ) {
		;
	}

	printf("CGameEngine Cleanup\n");

	// shutdown SDL
}

void CGameEngine::ChangeState(CGameState* state) 
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void CGameEngine::PushState(CGameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void CGameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}


void CGameEngine::HandleEvents() 
{
	// let the state handle events
	states.back()->HandleEvents(this);
}

void CGameEngine::Update() 
{
	// let the state update the game
	states.back()->Update(this);
}

void CGameEngine::Draw() 
{
	// let the state draw the screen
	states.back()->Draw(this);
}
