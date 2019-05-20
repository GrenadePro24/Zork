#ifndef Item_
#define Item_
#include <string>

using namespace std;

class Item
{
	public:
		Item(string name, string type, string location, string description, string roomLocation, bool isPickup, int damage, string content);
		~Item();
	public :
		string name;
		string type;
		string location;
		string description;
		string roomLocation;
		bool isPickup;
		int damage;
		string content;
};

#endif

