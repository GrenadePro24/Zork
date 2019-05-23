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
	int playerHitpoints = 10;
	bool isInitialized = false;

	string instructions = "\nInstructions:\n"
		"Use \"take\" to pick up items and store them in your inventory.\n"
		"Use \"drop\" to drop items in the floor.\n"
		"Use \"use\" to unlock doors and consume items.\n"
		"Use \"give\" to give items to NPCs.\n"
		"Use \"enter\" or \"go\" to use warps and move to other rooms.\n"
		"Use \"look\" to look around the room you're standing in.\n"
		"Use \"inventory\" to list the items in your inventory.\n"
		"Use \"inspect\" to inspect items in your inventory.\n"
		"Use \"open\" to open containers and get the item inside.\n"
		"Use \"talk\" to talk to NPCs.\n"
		"Use \"read\" to read signs.\n"
		"Use \"attack\" to attack NPCs.\n"
		"Use \"approve\" to.. you'll know when.\n"
		"Use \"help\" to show these instructions.\n"
		"Use \"start\" to start and restart the game.\n"
		"\n";

	void initiateRooms();
	void initiateItems();
	void initiateWarps();
	void initiateNPCs();
	void loadRoom(Room currentRoom);
};

#endif

