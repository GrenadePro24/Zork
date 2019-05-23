#include "pch.h"
#include <list>
#include <iostream>
#include <string>
#include "PZT.h"
#include "ActionManager.h"
#include "Parser.h"
#include "Init.h"
#include "Item.h"
#include "Warp.h"
#include "Room.h"
#include "NPC.h"

using namespace std;
Parser parser;
ActionManager manager;
Init initiate;

int main()
{
    cout << "Welcome to my Zork-like Adventure.\n";
	cout << initiate.instructions;
	while (true)
	{
		cout << ">";
		string input;
		getline(cin, input);
		Command cmd = parser.parseCommand(input);
		manager.chooseAction(cmd);
	}
}
