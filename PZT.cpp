#include "pch.h"
#include <list>
#include <iostream>
#include <string>
#include "Item.h"
#include "Command.h"
#include "Parser.h"

using namespace std;
Parser parser;
list<Item> inventory;
list<Item> items;
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
