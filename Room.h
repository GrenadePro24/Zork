#ifndef Room_
#define Room_
#include <string>

using namespace std;

class Room
{
public:
	Room(string name, string description);
	~Room();
public:
	string name;
	string description;
};

#endif

