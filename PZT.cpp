#include "pch.h"
#include <list>
#include <iostream>
#include <string>
#include "ActionManager.h"
#include "Command.h"
#include "Parser.h"
#include "Item.h"
#include "Warp.h"
#include "Room.h"
#include "NPC.h"

using namespace std;
Parser parser;
const list<Item> inventory;
const list<Item> items;
const list<Room> rooms;
const list<Warp> warps;
const list<NPC> NPCs;
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
		cout << cmd.action << "|" << cmd.targetA << "|" << cmd.conjunction << "|" << cmd.targetB;
	}
}
