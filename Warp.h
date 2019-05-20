#ifndef Warp_
#define Warp_
#include <string>

using namespace std;

class Warp
{
	public:
		Warp(string name, string type, string description, string targetRoom, string roomLocation, bool isLocked, string keyItem);
		~Warp();
	public :
		string name;
		string type;
		string description;
		string targetRoom;
		string roomLocation;
		bool isLocked;
		string keyItem;
};

#endif
