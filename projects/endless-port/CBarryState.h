
#ifndef BARRYSTATE_H
#define BARRYSTATE_H

#include "CGameState.h"

class CBarryState : public CGameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	static CBarryState* Instance() {
		return &m_BarryState;
	}

protected:
	CBarryStateState() { }

private:
	static CBarryState m_BarryState;

	int alpha;
};

#endif