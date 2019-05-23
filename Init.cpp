#include "pch.h"
#include "Item.h"
#include "Warp.h"
#include "Room.h"
#include "NPC.h"
#include <iostream>
#include <list>
#include <string>
#include "Init.h"

using namespace std;
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
"Examples: \"Use key on door\", \"Use healing potion\"\n"
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

void Init::initiateRooms()
{
	rooms.clear();
	//START-------------------------------------------
	rooms.push_back(Room("Bedroom", "You wake up inside your bedroom."));
	rooms.push_back(Room("Apartment Hallway", "You're inside a long hallway filled with locked doors."));
	rooms.push_back(Room("Rooftop", "You're on the roof of your apartment."));
	rooms.push_back(Room("Apartment Lobby", "You're in the lobby of your apartment."));
	rooms.push_back(Room("Apartment Outside", "You're outside your apartment."));
	//PATH1: WALKING----------------------------------
	rooms.push_back(Room("Alleyway", "You take a shortcut and end on a dark and lonely alleway."));
	rooms.push_back(Room("Darker Alley", "The fence closes behind you. You're in an even darker alley wondering if that shortcut was even worth it."));
	rooms.push_back(Room("Office Backroom", "You're in the service area of your office building. Almost there."));
	//PATH2: TAXI-------------------------------------
	rooms.push_back(Room("Taxi", "You're inside a taxi."));
	rooms.push_back(Room("Jail Cell", "The taxi driver hit another driver and you both got thrown to jail. You have to get out of here."));
	rooms.push_back(Room("Holding Cells", "You're out of your cell. Almost free."));
	rooms.push_back(Room("Break Room", "You're inside the guard beak room."));
	rooms.push_back(Room("Police Alleyway", "You're behind the police station. Your office should be Across the Street."));
	rooms.push_back(Room("Down Street", "You're just outside of your office building."));
	//PATH3: METRO------------------------------------
		//METRO MAZE--------------------------------------
		rooms.push_back(Room("Home Station", "You're in the Home Station entrace."));
		rooms.push_back(Room("Home Station Red", "You're in the red connection of the Home Station."));
		rooms.push_back(Room("Home L1 Boarding", "You're in the L1 Train boarding area."));
		rooms.push_back(Room("Home Station Blue", "You're in the blue connection of the Home Station."));
		rooms.push_back(Room("Home L5 Boarding", "You're in the L5 Train boarding area."));
		rooms.push_back(Room("Beach Station", "You're in the Beach Station entrace."));
		rooms.push_back(Room("Beach Station Red", "You're in the red connection of the Beach Station."));
		rooms.push_back(Room("Beach L1 Boarding", "You're in the L1 Train boarding area."));
		rooms.push_back(Room("Beach Station Yellow", "You're in the yellow connection of the Beach Station."));
		rooms.push_back(Room("Beach L4 Boarding", "You're in the L4 Train boarding area."));
		rooms.push_back(Room("Beach Station Green", "You're in the green connection of the Beach Station."));
		rooms.push_back(Room("Beach L3 Boarding", "You're in the L3 Train boarding area."));
		rooms.push_back(Room("Stadium Station", "You're in the Stadium Station entrace."));
		rooms.push_back(Room("Stadium Station Purple", "You're in the purple connection of the Stadium Station."));
		rooms.push_back(Room("Stadium L2 Boarding", "You're in the L2 Train boarding area."));
		rooms.push_back(Room("Stadium Station Blue", "You're in the blue connection of the Stadium Station."));
		rooms.push_back(Room("Stadium L5 Boarding", "You're in the L5 Train boarding area."));
		rooms.push_back(Room("Stadium Station Green", "You're in the green connection of the Stadium Station."));
		rooms.push_back(Room("Stadium L3 Boarding", "You're in the L3 Train boarding area."));
		rooms.push_back(Room("Office Station", "You're in the Office Station entrace."));
		rooms.push_back(Room("Office Station Purple", "You're in the purple connection of the Office Station."));
		rooms.push_back(Room("Office L2 Boarding", "You're in the L2 Train boarding area."));
		rooms.push_back(Room("Office Station Yellow", "You're in the yellow connection of the Office Station."));
		rooms.push_back(Room("Office L4 Boarding", "You're in the L4 Train boarding area."));
		rooms.push_back(Room("Stadium Station Cafeteria", "You're in the stadium station cafeteria."));
		//METRO MAZE END----------------------------------
	rooms.push_back(Room("Front Street", "You're outside the metro station. That felt like a maze down there."));
	//FINALE------------------------------------------
	rooms.push_back(Room("Office Lobby", "You're in the lobby of your office building."));
	rooms.push_back(Room("Office Hallway", "You're in the hallway of your office building."));
	rooms.push_back(Room("Storage Room", "You're inside your office's storage room."));
	rooms.push_back(Room("Office", "You're inside your office."));
	rooms.push_back(Room("Chair", "You won congratulations."));
}

void Init::initiateItems()
{
	items.clear();
	//START-------------------------------------------
	items.push_back(Item("Yellow Key", "key", "on a table.", "Normal key to open doors. It has a label that reads \"Bedroom\".", "Bedroom", false, "", 0, ""));
	items.push_back(Item("Lead Pipe", "weapon", "on a corner.", "A rusted lead pipe. Quite blunt, can be used as a weapon.", "Rooftop", false, "", 8, ""));
	items.push_back(Item("Rum", "potion", "on a table.", "A rum bottle. You're not an alcoholic, just a pirate.", "Bedroom", false, "", 8, ""));
	//PATH1: WALKING----------------------------------
	items.push_back(Item("Wooden Stick", "weapon", "on a corner.", "A rusted lead pipe. Quite blunt, can be used as a weapon.", "Alleyway", false, "", 3, ""));
	//PATH2: TAXI-------------------------------------
	items.push_back(Item("Paper Roll", "container", "under the bed.", "A small paper roll. Contains something small and pointy.", "Jail Cell", false, "", 0, "Makeshift Lockpick"));
	items.push_back(Item("Paper Bag", "container", "on a table.", "A nice paper bag. Contains something big.", "Break Room", false, "", 0, "Cheese Sandwich"));
	items.push_back(Item("Toolbox", "container", "on a table.", "A nice paper bag. Contains something big.", "Break Room", true, "Toolbox Key", 0, "Crowbar"));
	//PATH3: METRO------------------------------------
	items.push_back(Item("Sign", "sign", "on the Wall.", "East: Home Station Red Connection.\nSouth: Home Station Blue Connection.", "Home Station", false, "", 0, ""));
	items.push_back(Item("Sign", "sign", "on the Wall.", "North: Beach Station Red Connection.\nSouth: Beach Station Yellow Connection.", "Beach Station", false, "", 0, ""));
	items.push_back(Item("Sign", "sign", "on the Wall.", "North: Beach Station Entrace.\nSouth: Beach Station Green Connection.", "Beach Station Yellow", false, "", 0, ""));
	items.push_back(Item("Sign", "sign", "on the Wall.", "North: Stadium Station Blue Connection.\nEast: Stadium Station Purple Connection.\nWest: Stadium Station Green Connection.\nSouth: Stadium Station Cafeteria.", "Stadium Station", false, "", 0, ""));
	items.push_back(Item("Sign", "sign", "on the Wall.", "East: Office Station Yellow Connection.\nWest: Stadium Station Purple Connection.", "Office Station Station", false, "", 0, ""));
	//FINALE------------------------------------------
	items.push_back(Item("Coffee", "potion", "on your desk.", "A big mug filled with warm tasty coffee. Someone's getting a raise.", "Office", false, "", 10, ""));
	items.push_back(Item("Storage Key", "key", "on one of your bookcases.", "A key to the office's storage room.", "Office", false, "", 0, ""));
	items.push_back(Item("Fancy Metal Box", "container", "on the back of the room.", "A shiny golden box with siler detailing. Fancy.", "Storage Room", false, "", 0, "The Mighty Pen"));
	//OUTOFBOUNDS-------------------------------------
	items.push_back(Item("Mighty Pen", "weapon", "", "The pen is mightier than the sword.", "The Void", false, "", 20, ""));
	items.push_back(Item("Paper Bag", "container", "", "A dirty brown paper bag. Looks like it has something inside.", "The Void", false, "", 0, "Rusted Key"));
	items.push_back(Item("Rusted Key", "key", "", "A rusted key. Id use it as soon as posible.", "The Void", false, "", 0, ""));
	items.push_back(Item("Steel Cutter", "key", "", "A hefty steel cutter. Cuts through steel like it's butter.", "The Void", false, "", 0, ""));
	items.push_back(Item("Makeshift Lockpick", "key", "", "A homemade lockpick. Seems the last prisoner was busy.", "The Void", false, "", 0, ""));
	items.push_back(Item("Cheese Sandwich", "misc", "", "A tasty looking cheese sandwich.", "The Void", false, "", 0, ""));
	items.push_back(Item("Toolbox Key", "key", "", "The key to the police toolbox.", "The Void", false, "", 0, ""));
	items.push_back(Item("Crowbar", "key", "", "A sturdy crowbar. Can be used to pry things open.", "The Void", false, "", 0, ""));
	items.push_back(Item("Silver Sword", "weapon", "", "A sharp silver sword.", "The Void", false, "", 100, ""));
	items.push_back(Item("Feather", "weapon", "", "A bird feather. Rather pointless to attack someone with this.", "The Void", false, "", 0, ""));
	items.push_back(Item("Coin", "item", "", "A 1 euro coin.", "The Void", false, "", 0, ""));
	items.push_back(Item("Admission Form", "end", "", "You should definitively approve Gabriel Rivas' admission form.", "The Void", false, "", 0, ""));
	items.push_back(Item("Box A", "container", "", "A box containing universe B.", "The Void", false, "", 0, "Box B"));
	items.push_back(Item("Box B", "container", "", "A box containing universe A.", "The Void", false, "", 0, "Box A"));
}

void Init::initiateWarps()
{
	warps.clear();
	//START-------------------------------------------
	warps.push_back(Warp("Apartment Hallway", "door", "leads to the Apartment Hallway.", "Apartment Hallway", "Bedroom", true, "Yellow Key"));
	warps.push_back(Warp("Bedroom", "door", "leads to your Bedroom.", "Bedroom", "Apartment Hallway", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Rooftop", "Apartment Hallway", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Apartment Hallway", "Rooftop", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Apartment Lobby", "Apartment Hallway", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Apartment Hallway", "Apartment Lobby", false, ""));
	warps.push_back(Warp("Outside", "door", "leads outside.", "Apartment Outside", "Apartment Lobby", false, ""));
	warps.push_back(Warp("Lobby", "door", "leads to the Lobby.", "Apartment Lobby", "Apartment Outside", false, ""));
	warps.push_back(Warp("East", "object", "There's a path to the East.", "Alleyway", "Apartment Outside", false, ""));
	warps.push_back(Warp("Metro Station", "staircase", "leads to the Metro Station.", "Home Station", "Apartment Outside", false, ""));
	warps.push_back(Warp("Taxi", "object", "There's a Taxi that is empty and waiting.", "Taxi", "Apartment Outside", false, ""));
	//PATH1: WALKING----------------------------------
	warps.push_back(Warp("Darker Alleyway", "door", "leads further into a Darker Alleyway.", "Darker Alley", "Alleyway", true, "Rusted Key"));
	warps.push_back(Warp("Office Building", "door", "leads into your office building.", "Office Backroom", "Darker Alley", true, "Steel Cutter"));
	warps.push_back(Warp("Office Lobby", "door", "leads into the Office Lobby.", "Office Lobby", "Office Backroom", false, ""));
	//PATH2: TAXI-------------------------------------
	warps.push_back(Warp("Office", "object", "This can take you to the Office quickly.", "Jail Cell", "Taxi", false, ""));
	warps.push_back(Warp("Holding Cells", "door", "leads out to the holding cells.", "Holding Cells", "Jail Cell", true, "Makeshift Lockpick"));
	warps.push_back(Warp("Jail Cell", "door", "leads into your jail cell.", "Jail Cell", "Holding Cells", false, ""));
	warps.push_back(Warp("Window", "object", "There's a Window that leads outside.", "Police Alleyway", "Holding Cells", true, "Crowbar"));
	warps.push_back(Warp("Break Room", "door", "leads to the guard's break room.", "Break Room", "Holding Cells", false, ""));
	warps.push_back(Warp("Holding Cells", "door", "leads back to the holding cells.", "Holding Cells", "Break Room", false, ""));
	warps.push_back(Warp("South", "object", "There's a path that leads south.", "Down Street", "Police Alleyway", false, ""));
	warps.push_back(Warp("Office", "door", "leads into your office.", "Office Lobby", "Down Street", false, ""));
	//PATH3: METRO------------------------------------
	//Home Station
	warps.push_back(Warp("East", "object", "There's a path that leads to the East.", "Home Station Red", "Home Station", false, ""));
	warps.push_back(Warp("West", "object", "There's a path that leads to the West.", "Home Station", "Home Station Red", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Home L1 Boarding", "Home Station Red", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Home Station Red", "Home L1 Boarding", false, ""));
	warps.push_back(Warp("South", "object", "There's a path that leads to the South", "Home Station Blue", "Home Station", false, ""));
	warps.push_back(Warp("North", "object", "There's a path that leads to the North", "Home Station", "Home Station Blue", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Home L5 Boarding", "Home Station Blue", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Home Station Blue", "Home L5 Boarding", false, ""));
	//Beach Station
	warps.push_back(Warp("North", "object", "There's a path that leads to the North.", "Beach Station Red", "Beach Station", false, ""));
	warps.push_back(Warp("South", "object", "There's a path that leads to the South.", "Beach Station", "Beach Station Red", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Beach L1 Boarding", "Beach Station Red", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Beach Station Red", "Beach L1 Boarding", false, ""));
	warps.push_back(Warp("South", "object", "There's a path that leads to the South", "Beach Station", "Beach Station Yellow", false, ""));
	warps.push_back(Warp("North", "object", "There's a path that leads to the North", "Beach Station Yellow", "Beach Station", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Beach L4 Boarding", "Beach Station Yellow", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Beach Station Yellow", "Beach L4 Boarding", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Beach Station Green", "Beach Station Yellow", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Beach Station Yellow", "Beach Station Green", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Beach L3 Boarding", "Beach Station Green", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Beach Station Green", "Beach L3 Boarding", false, ""));
	//Office Station
	warps.push_back(Warp("West", "object", "There's a path that leads to the West.", "Office Station Purple", "Office Station", false, ""));
	warps.push_back(Warp("East", "object", "There's a path that leads to the East.", "Office Station", "Office Station Purple", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Office L2 Boarding", "Office Station Purple", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Office Station Purple", "Office L2 Boarding", false, ""));
	warps.push_back(Warp("East", "object", "There's a path that leads to the East", "Office Station Yellow", "Office Station", false, ""));
	warps.push_back(Warp("West", "object", "There's a path that leads to the West", "Office Station", "Office Station Yellow", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Beach L4 Boarding", "Office Station Yellow", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Office Station Yellow", "Office L4 Boarding", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Front Street", "Office Station", false, ""));
	warps.push_back(Warp("Office", "door", "leads into your Office.", "Office Lobby", "Front Street", false, ""));
	//Stadium Station
	warps.push_back(Warp("North", "object", "There's a path that leads to the North.", "Stadium Station Blue", "Stadium Station", false, ""));
	warps.push_back(Warp("South", "object", "There's a path that leads to the South.", "Stadium Station", "Stadium Station Blue", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Stadium L5 Boarding", "Stadium Station Blue", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Stadium Station Blue", "Stadium L5 Boarding", false, ""));
	warps.push_back(Warp("East", "object", "There's a path that leads to the East.", "Stadium Station Purple", "Stadium Station", false, ""));
	warps.push_back(Warp("West", "object", "There's a path that leads to the West.", "Stadium Station", "Stadium Station Purple", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Stadium L2 Boarding", "Stadium Station Purple", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Stadium Station Purple", "Stadium L2 Boarding", false, ""));
	warps.push_back(Warp("West", "object", "There's a path that leads to the West.", "Stadium Station Green", "Stadium Station", false, ""));
	warps.push_back(Warp("East", "object", "There's a path that leads to the East.", "Stadium Station", "Stadium Station Green", false, ""));
	warps.push_back(Warp("Downstairs", "staircase", "leads Downstairs.", "Stadium L3 Boarding", "Stadium Station Green", false, ""));
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Stadium Station Green", "Stadium L3 Boarding", false, ""));
	warps.push_back(Warp("South", "object", "There's a path that leads to the South.", "Stadium Station Cafeteria", "Stadium Station", false, ""));
	warps.push_back(Warp("North", "object", "There's a path that leads to the North.", "Stadium Station", "Stadium Station Cafeteria", false, ""));
	//Train Warps
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Beach L1 Boarding", "Home L1 Boarding", false, ""));
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Home L1 Boarding", "Beach L1 Boarding", false, ""));
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Stadium L2 Boarding", "Office L2 Boarding", false, ""));
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Office L2 Boarding", "Stadium L2 Boarding", false, ""));
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Stadium L3 Boarding", "Beach L3 Boarding", false, ""));
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Beach L3 Boarding", "Stadium L3 Boarding", false, ""));
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Beach L4 Boarding", "Office L4 Boarding", false, ""));
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Office L4 Boarding", "Beach L4 Boarding", false, ""));
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Home L5 Boarding", "Stadium L5 Boarding", false, ""));
	warps.push_back(Warp("Train", "door", "that leads into the Train.", "Stadium L5 Boarding", "Home L5 Boarding", false, ""));
	//FINALE------------------------------------------
	warps.push_back(Warp("Upstairs", "staircase", "leads Upstairs.", "Office Hallway", "Office Lobby", false, ""));
	warps.push_back(Warp("Storage Room", "door", "leads to the office's storage room.", "Storage Room", "Office Hallway", true, "Storage Key"));
	warps.push_back(Warp("Office Hallway", "door", "leads to the Office Hallway.", "Office Hallway", "Storage Room", false, ""));
	warps.push_back(Warp("Office Hallway", "door", "leads to the Office Hallway.", "Office Hallway", "Office", false, ""));
	warps.push_back(Warp("Office", "door", "leads your office.", "Office", "Office Hallway", false, ""));
}

void Init::initiateNPCs()
{
	NPCs.clear();
	//START-------------------------------------------
	NPCs.push_back(NPC("Receptionist", "behind the helpdesk.", "Hello it's 7am on this sunny friday morning.", "Apartment Lobby", 10, 2, "", "Feather"));
	NPCs.push_back(NPC("Recycler Man", "near a dump.", "Hey! Have any items worth recycling?.", "Apartment Outside", 10, 2, "Lead Pipe", "Coin"));
	//PATH1: WALKING----------------------------------
	NPCs.push_back(NPC("Hobo", "sleeping on the corner.", "Leave me alone!", "Alleyway", 10, 4, "Rum", "Rusted Key"));
	NPCs.push_back(NPC("Thief", "hiding in the shadows.", "Give me your money, NOW!", "Darker Alley", 10, 3, "Coin", "Steel Cutter"));
	NPCs.push_back(NPC("Worker", "cleaning the room.", "Are you alright? You seem a little shaken up.", "Office Backroom", 15, 2, "", "Box A"));
	//PATH2: TAXI-------------------------------------
	NPCs.push_back(NPC("Taxi Driver", "in the driver's seat.", "Hello, just tell me where do you want to Go.", "Taxi", 10, 10, "", ""));
	NPCs.push_back(NPC("Taxi Driver", "in the corner.", "We gotta get out of here!", "Jail Cell", 10, 2, "", ""));
	NPCs.push_back(NPC("Inmate", "inside another cell.", "Hey! I snagged a key from the janitor. I'll trade it to you for something to eat!", "Holding Cells", 4, 1, "Cheese Sandwich", "Toolbox Key"));
	//PATH3: METRO------------------------------------
	NPCs.push_back(NPC("NPC", "sitting on a table.", "This sandwich definitively needs some concentrated dark matter. Do you happen to know the recipe to make some?", "Stadium Station Cafeteria", 2, 0, "", ""));
	//FINALE------------------------------------------
	NPCs.push_back(NPC("Receptionist", "behind the helpdesk.", "Hello it's almost 8am on this sunny friday morning. Coming in early today?", "Office Lobby", 10, 2, "", "Feather"));
	NPCs.push_back(NPC("Master Form", "ready to fight you.", "Fight me you insignificant mortal!", "Office", 20, 10, "", "Admission Form"));
}

void Init::loadRoom(Room targetRoom)
{
	currentRoom = targetRoom;
	cout << "\n";
	cout << currentRoom.name + "\n";
	cout << currentRoom.description + "\n";
	for (Item initItems : items)
	{
		if (initItems.roomLocation == currentRoom.name)
			cout << "You see a " + initItems.name + " " + initItems.location + "\n";
	}
	for (Warp initWarps : warps)
	{
		if (initWarps.roomLocation == currentRoom.name)
		{
			if (initWarps.type == "door")
				cout << "There's a door that " + initWarps.description + "\n";
			if (initWarps.type == "staircase")
				cout << "There's a staircase that " + initWarps.description + "\n";
			if (initWarps.type == "path")
				cout << "There's a path to the " + initWarps.description + "\n";
			if (initWarps.type == "object")
				cout << initWarps.description + "\n";
		}
	}
	for (NPC initNPCs : NPCs)
	{
		if (initNPCs.roomLocation == currentRoom.name)
			cout << "You see a " + initNPCs.name + " " + initNPCs.location + "\n";
	}
}
