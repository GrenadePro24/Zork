#ifndef Init_
#define Init_
#include <list>
#include <string>
#include "Item.h"
#include "Warp.h"
#include "Room.h"
#include "NPC.h"

class Init
{
public:
	list<Item> inventory;
	list<Item> items;
	list<Room> rooms;
	list<Warp> warps;
	list<NPC> NPCs;
	Room currentRoom = Room("","");
	string instructions;
	int playerHitpoints = 10;

	void initiateRooms();
	void initiateItems();
	void initiateWarps();
	void initiateNPCs();
	void loadRoom(Room currentRoom);
};

#endif

