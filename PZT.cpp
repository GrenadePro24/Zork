#include "pch.h"
#include <list>
#include <iostream>
#include <string>
#include "PZT.h"
#include "ActionManager.h"
#include "Command.h"
#include "Parser.h"
#include "Item.h"
#include "Warp.h"
#include "Room.h"
#include "NPC.h"

using namespace std;
Parser parser;
ActionManager manager;
list<Item> inventory;
list<Item> items;
list<Room> rooms;
list<Warp> warps;
list<NPC> NPCs;
Room currentRoom = Room("","");
int playerHitpoints = 10;
string instructions = "WIP";

int main()
{
    cout << "Welcome to my Zork-like Adventure." << endl;
	cout << instructions << endl;
	while (true)
	{
		cout << ">";
		string input;
		getline(cin, input);
		Command cmd = parser.parseCommand(input);
		cout << cmd.action;
		manager.chooseAction(cmd,currentRoom);
		cout << cmd.action << "|" << cmd.targetA << "|" << cmd.conjunction << "|" << cmd.targetB;
	}
}

static void loadRoom(Room room)
{
	cout << "\n";
	cout << room.name + "\n";
	cout << room.description + "\n";
	currentRoom = room;
	for(Item initItems : items)
	{
		if (initItems.roomLocation == currentRoom.name)
			cout << "You see a " + initItems.name + " " + initItems.location + "\n";
	}
	for(Warp initWarps : warps)
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
				cout << "There's a " + initWarps.name + " " + initWarps.description + "\n";
		}

	}
	for(NPC initNPCs : NPCs)
	{
		if (initNPCs.roomLocation == currentRoom.name)
			cout << "You see a " + initNPCs.name + " " + initNPCs.location + "\n";
	}
}

void initiateRooms()
{
	rooms.clear();
	//START-------------------------------------------
	rooms.push_back(Room("Start Bedroom", "You wake up inside your bedroom."));
	rooms.push_back(Room("Hallway", "You're inside a long hallway filled with locked doors."));
	rooms.push_back(Room("Rooftop", "You're on the roof of your apartment."));
	rooms.push_back(Room("Lobby", "You're in the lobby of your apartment."));
	rooms.push_back(Room("Outside", "You're outside your apartment."));
	//PATH1: WALKING----------------------------------
	rooms.push_back(Room("Metro Station", "You're inside the metro station."));

	//PATH2: TAXI-------------------------------------
	rooms.push_back(Room("Metro Station", "You're inside the metro station."));

	//PATH3: METRO------------------------------------


	//FINALE------------------------------------------


}

void initiateItems()
{
	items.clear();
	//START-------------------------------------------
	items.push_back(Item("Yellow Key", "key", "on a table.", "Normal key to open doors. It has a label that reads \"Bedroom\".", "Start Bedroom", true, 0, "NULL"));
	items.push_back(Item("Blue Key", "key", "on a table.", "Normal key to open doors. It's label is worn and not legible.", "Start Bedroom", true, 0, "NULL"));
	items.push_back(Item("Lead Pipe", "weapon", "on a corner.", "A rusted lead pipe. Quite blunt, can be used as a weapon.", "Rooftop", true, 5, "NULL"));

	//PATH1: WALKING----------------------------------
	items.push_back(Item("Lunchbox", "container", "on the floor.", "A bloodstained lunchbox. Wonder what's inside.", "Rooftop", true, 5, "Silver Sword"));

	//PATH2: TAXI-------------------------------------


	//PATH3: METRO------------------------------------


	//FINALE------------------------------------------


	//OUTOFBOUNDS-------------------------------------
	items.push_back(Item("Silver Sword", "weapon", "on the floor.", "A sharp silver sword.", "The Void", true, 100, "NULL"));
	items.push_back(Item("Feather", "weapon", "on the floor.", "A bird feather. Rather pointless to attack someone with this.", "The Void", true, 0, "NULL"));
	items.push_back(Item("Coin", "item", "on the floor.", "A 1 euro coin.", "The Void", true, 0, "NULL"));
}

void initiateWarps()
{
	warps.clear();
	//START-------------------------------------------
	warps.push_back(Warp("Hallway", "door", "leads to a Hallway.", "Hallway", "Start Bedroom", true, "Yellow Key"));
	warps.push_back(Warp("Start Bedroom", "door", "leads to the Start Bedroom.", "Start Bedroom", "Hallway", false, ""));
	warps.push_back(Warp("upstairs", "staircase", "leads Upstairs.", "Rooftop", "Hallway", false, ""));
	warps.push_back(Warp("downstairs", "staircase", "leads Downstairs.", "Hallway", "Rooftop", false, ""));
	warps.push_back(Warp("downstairs", "staircase", "leads Downstairs.", "Lobby", "Hallway", false, ""));
	warps.push_back(Warp("upstairs", "staircase", "leads Upstairs.", "Hallway", "Lobby", false, ""));
	warps.push_back(Warp("Outside", "door", "leads outside.", "Outside", "Lobby", false, ""));
	warps.push_back(Warp("Lobby", "door", "leads to the Lobby.", "Lobby", "Outside", false, ""));
	warps.push_back(Warp("down the street", "path", "right that leads Down The Street.", "Start Bedroom", "Outside", false, ""));
	warps.push_back(Warp("Metro Station", "staircase", "leads to the Metro Station.", "Start Bedroom", "Outside", false, ""));
	warps.push_back(Warp("Taxi", "object", "that is empty and waiting.", "Start Bedroom", "Outside", false, ""));

	//PATH1: WALKING----------------------------------


	//PATH2: TAXI-------------------------------------


	//PATH3: METRO------------------------------------


	//FINALE------------------------------------------


}

void initiateNPCs()
{
	NPCs.clear();
	//START-------------------------------------------
	NPCs.push_back(NPC("Receptionist", "behind the helpdesk.", "\"Hello it's 7:40am on this sunny friday morning.\"", "Lobby", 10, 2, "", "Coin"));


	//PATH1: WALKING----------------------------------


	//PATH2: TAXI-------------------------------------


	//PATH3: METRO------------------------------------


	//FINALE------------------------------------------


}

void startGame()
{
	system("CLS");
	initiateRooms();
	initiateWarps();
	initiateItems();
	initiateNPCs();
	currentRoom = rooms.front();
	inventory = list<Item>();
	loadRoom(currentRoom);
}

void exitGame()
{
	terminate();
}

