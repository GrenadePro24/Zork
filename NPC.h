#ifndef NPC_
#define NPC_
#include <string>

using namespace std;

class NPC
{
public:
	NPC(string name, string location, string description, string roomLocation, int hitpoints, int strength, string keyItem, string reward);
	~NPC();
public:
	string name;
	string location;
	string description;
	string roomLocation;
	int hitpoints;
	int strength;
	string keyItem;
	string reward;
};

#endif

