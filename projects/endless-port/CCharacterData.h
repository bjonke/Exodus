
#ifndef CHARACTERDATA_H
#define CHARACTERDATA_H

#include <vector>
using namespace std;

class CCharacterObject;

class CCHaracterData
{
public:

	void Init(const char* title, int width=640, int height=480, 
		      int bpp=0, bool fullscreen=false);
	void Cleanup();


	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	//SDL_Surface* screen;

private:
	// the stack of states
	vector<CCharacterObject*> objects;

	bool m_running;
	bool m_fullscreen;
};

#endif
