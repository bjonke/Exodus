#include<windows.h>
#include<string>
#include<list>
#include<vector>
#include<queue>
using namespace std;
#include "CGameMessages.h"

CGameMessages::CGameMessages()   // Constructor
{
}
 
CGameMessages::CGameMessages(const CGameMessages &copyin)   // Copy constructor to handle pass by value.
{
}
 
ostream &operator<<(ostream &output, const CGameMessages &aaa)
{
   //output << aaa.x << ' ' << aaa.y << ' ' << aaa.z << endl;
   return output;
}
 
CGameMessages& CGameMessages::operator=(const CGameMessages &rhs)
{
   //this->x = rhs.x;
   //this->y = rhs.y;
   //this->z = rhs.z;
   return *this;
}
 
int CGameMessages::operator==(const CGameMessages &rhs) const
{
   //if( this->x != rhs.x) return 0;
   //if( this->y != rhs.y) return 0;
   //if( this->z != rhs.z) return 0;
   return 1;
}
 
// This function is required for built-in STL list functions like sort
int CGameMessages::operator<(const CGameMessages &rhs) const
{
   //if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;
   //if( this->x == rhs.x && this->y < rhs.y) return 1;
   //if( this->x < rhs.x ) return 1;
   return 0;
}

void CGameMessages::Render(HDC BackBuffer, RECT Screen, POINT iOffset)
{

	RECT MessageWindow = {Screen.left,Screen.bottom - 100,Screen.right,Screen.bottom};
	DrawFocusRect(BackBuffer,&MessageWindow);
	for( std::list<std::string>::iterator i(Messages.begin()), end(Messages.end()); i != end; ++i )
	{
		MessageWindow.top += 15;
		MessageWindow.bottom += 15;
		DrawText(BackBuffer,(*i).c_str(),strlen((*i).c_str()),&MessageWindow,DT_LEFT);
	}
}

void CGameMessages::Post(std::string iMessage)
{
/*
string programmers[] = {”Hussainweb”, “BOTW”, “VMC”, “Ziggy^3″, “Ray45512″,
“Mallowman”, “PRTSoft”, “MaxK”,”Pelican”, “Moonie”, “Ruudje”, “And Many More”};
//To add all these elements to a vector, we can simply to do it as:
vector <string> prog (programmers, programmers + sizeof(programmers)/sizeof(string));
*/
	if(Messages.size() > 4)
		Messages.pop_front();
	Messages.push_back(iMessage);
}