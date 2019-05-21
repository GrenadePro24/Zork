#include "pch.h"
#include "ActionManager.h"
#include "Init.h"
#include "Warp.h"
#include "Item.h"
#include "Room.h"
#include "NPC.h"
#include <algorithm>
#include <iostream>
#include "windows.h"
#include "stdlib.h"
using namespace std;
Init init;

string toLower(string target)
{
	transform(target.begin(), target.end(), target.begin(), tolower);
	return target;
}

Warp findWarp(string target)
{
	Warp resultWarp = Warp("NULL", "NULL", "NULL", "NULL", "NULL", false, "NULL");
	for(Warp results : init.warps)
	{
		string resultName = results.name;
		if (toLower(resultName) == toLower(target) && results.roomLocation == init.currentRoom.name)
			resultWarp = results;
	}
	return resultWarp;
}

Item findItem(list<Item> list, string target, bool overrideRoom)
{
	Item resutlItem = Item("NULL", "NULL", "NULL", "NULL", "NULL", false, 0, "NULL");
	for(Item results : list)
	{
		string resultName = results.name;
		if (toLower(resultName) == toLower(target) && (results.roomLocation == init.currentRoom.name || overrideRoom))
			resutlItem = results;
	}
	return resutlItem;
}

NPC findNPC(string target)
{
	NPC resultNPC = NPC("NULL", "NULL", "NULL", "NULL", 0, 0, "NULL", "NULL");
	for(NPC results : init.NPCs)
	{
		string resultName = results.name;
		if (toLower(resultName) == toLower(target) && results.roomLocation == init.currentRoom.name)
			resultNPC = results;
	}
	return resultNPC;
}

Room findRoom(string target)
{
	Room resultRoom = Room("NULL", "NULL");
	for(Room results : init.rooms)
	{
		string resultName = results.name;
		if (toLower(resultName) == toLower(target))
			resultRoom = results;
	}
	return resultRoom;
}

list<Item> removeItem(list<Item> targetList, Item targetItem)
{
	list<Item>::iterator it = targetList.begin();
	int index = 0;
	for (Item listItem : targetList)
	{
		if (listItem.name == targetItem.name)
		{
			advance(it, index);
			break;
		}
		else
			++index;
	}
	targetList.erase(it);
	return targetList;
}

list<Warp> removeWarp(list<Warp> targetList, Warp targetWarp)
{
	list<Warp>::iterator it = targetList.begin();
	int index = 0;
	for (Warp listWarp : targetList)
	{
		if (listWarp.name == targetWarp.name)
		{
			advance(it, index);
			break;
		}
		else
			++index;
	}
	targetList.erase(it);
	return targetList;
}

list<NPC> removeNPC(list<NPC> targetList, NPC targetNPC)
{
	list<NPC>::iterator it = targetList.begin();
	int index = 0;
	for (NPC listNPC : targetList)
	{
		if (listNPC.name == targetNPC.name)
		{
			advance(it, index);
			break;
		}
		else
			++index;
	}
	targetList.erase(it);
	return targetList;
}

bool combatSimulator(NPC targetNPC, Item weapon)
{
	int attackValue = 0;
	while (true)
	{
		Sleep(1000);
		attackValue = rand() % weapon.damage;
		if (attackValue >= targetNPC.hitpoints)
		{
			cout << "You killed the " + targetNPC.name + "!\n";
			return true;
		}
		else
		{
			cout << "You swing for " << attackValue <<  " points!\n";
			targetNPC.hitpoints -= attackValue;
		}
		Sleep(1000);
		attackValue = rand() % targetNPC.strength;
		if (attackValue >= init.playerHitpoints)
		{
			cout << "You're dead...\n";
			return false;
		}
		else
		{
			cout << "The " + targetNPC.name + " swings for " << attackValue << " points!\n";
			init.playerHitpoints -= attackValue;
		}
	}
}

int ActionManager::chooseAction(Command cmd)
{
	if (cmd.action == "")
	{
		return 0;
	}

	if (cmd.action == "start")
	{
		system("CLS");
		init.initiateRooms();
		init.initiateWarps();
		init.initiateItems();
		init.initiateNPCs();
		init.inventory.clear();
		init.currentRoom = init.rooms.front();
		init.loadRoom(init.currentRoom);
		return 0;
	}

	if (cmd.action == "help")
	{
		cout << init.instructions;
		return 0;
	}

	if (cmd.action == "clear")
	{
		system("CLS");
		init.loadRoom(init.currentRoom);
		return 0;
	}

	if (cmd.action == "take")
	{
		if (cmd.targetA == "")
		{
			cout << "What do you want to take?\n";
			getline(cin, cmd.targetA);
		}
		Item targetItem = findItem(init.items, cmd.targetA, false);
		if (init.currentRoom.name == targetItem.roomLocation && targetItem.name != "NULL")
		{
			init.inventory.push_back(targetItem);
			init.items = removeItem(init.items, targetItem);
			cout << targetItem.name + " taken.\n";
		}
		else
			cout << "You can't see that item.\n";
		return 0;
	}

	if (cmd.action == "drop")
	{
		if (cmd.targetA == "")
		{
			cout << "What do you want to drop?\n";
			getline(cin, cmd.targetA);
		}
		Item targetItem = findItem(init.inventory, cmd.targetA, true);
		if (targetItem.name != "NULL")
		{
			init.inventory = removeItem(init.inventory, targetItem);
			targetItem.location = "on the floor.";
			targetItem.roomLocation = init.currentRoom.name;
			init.items.push_back(targetItem);
			cout << targetItem.name + " dropped.\n";
		}
		else
			cout << "You dont have such item.\n";
		return 0;
	}

	if (cmd.action == "open")
	{
		if (cmd.targetA == "")
		{
			cout << "What do you want to open?\n";
			getline(cin, cmd.targetA);
		}
		Item targetItem = findItem(init.inventory, cmd.targetA, true);
		if (targetItem.type == "container")
		{
			if (targetItem.name != "NULL")
			{
				if (targetItem.type == "container")
				{
					init.inventory.push_back(findItem(init.items, targetItem.content, true));
					init.items = removeItem(init.items, findItem(init.items, targetItem.content, true));
					cout << "You found a " + targetItem.content + " inside the " + targetItem.name + ".\n";
					init.inventory = removeItem(init.items, targetItem);
				}
			}
			else
				cout << "You dont have such item.\n";
		}
		else
			cout << "You can't open that.\n";
		return 0;
	}

	if (cmd.action == "look")
	{
		init.loadRoom(init.currentRoom);
		return 0;
	}

	if (cmd.action == "inventory")
	{
		if (init.inventory.size() > 0)
		{
			cout << "In your inventory you have:\n";
			for(Item invItem : init.inventory)
			{
				cout << invItem.name + "\n";
			}
		}
		else
			cout << "Your inventory is empty.\n";
		return 0;
	}

	if (cmd.action == "enter")
	{
		if (cmd.targetA == "")
		{
			cout << "Where do you want to enter?\n";
			getline(cin, cmd.targetA);
		}
		Warp targetWarp = findWarp(cmd.targetA);
		if (init.currentRoom.name == targetWarp.roomLocation && targetWarp.name != "NULL")
		{
			if (!targetWarp.isLocked)
			{
				init.currentRoom.name = targetWarp.targetRoom;
				init.loadRoom(findRoom(targetWarp.targetRoom));
			}
			else
				cout << "This " + targetWarp.type + " is locked.\n";
		}
		else
			cout << "You can't see that location.\n";
		return 0;
	}

	if (cmd.action == "go")
	{
		if (cmd.targetA == "")
		{
			cout << "Where do you want to go?\n";
			getline(cin, cmd.targetA);
		}
		cmd.action = "enter";
		chooseAction(cmd);
		return 0;
	}

	if (cmd.action == "inspect")
	{
		if (cmd.targetA == "")
		{
			cout << "What do you want to inspect?\n";
			getline(cin, cmd.targetA);
		}
		Item targetItem = findItem(init.inventory, cmd.targetA, true);
		if (targetItem.name != "NULL")
		{
			cout << targetItem.description + "\n";
		}
		else
			cout << "You don't have such item.\n";
		return 0;
	}

	if (cmd.action == "use")
	{
		if (cmd.targetA == "")
		{
			cout << "What do you want to use?\n";
			getline(cin, cmd.targetA);
		}

		Item targetItem = findItem(init.inventory, cmd.targetA, true);

		if (targetItem.name == "NULL")
		{
			cout << "You don't have such item in your inventory.\n";
			return 0;
		}
		if (targetItem.type == "key")
		{
			if (cmd.conjunction == "")
			{
				cout << "What do you want to use the key with?\n";
				getline(cin, cmd.targetB);
			}
			Warp targetWarp = findWarp(cmd.targetB);
			if (targetWarp.name != "NULL")
			{
				if (targetWarp.isLocked)
				{
					if (toLower(targetWarp.keyItem) == toLower(targetItem.name))
					{
						init.warps = removeWarp(init.warps, targetWarp);
						targetWarp.isLocked = false;
						init.warps.push_back(targetWarp);
						init.inventory = removeItem(init.inventory, targetItem);
						cout << targetWarp.type + " unlocked.\n";
						return 0;
					}
					else
					{
						cout << "This key wont open this " + targetWarp.type + ".\n";
						return 0;
					}
				}
				else
				{
					cout << "This " + targetWarp.type + " isn't even locked.\n";
					return 0;
				}
			}
			else
			{
				cout << "You can't see an object named " + cmd.targetB + ".\n";
				return 0;
			}
		}
		cout << "Nothing interesting happens.\n";
		return 0;
	}

	if (cmd.action == "talk")
	{
		if (cmd.targetA == "")
		{
			cout << "Who do you want to talk to?\n";
			getline(cin, cmd.targetA);
		}
		NPC targetNPC = findNPC(cmd.targetA);
		if (targetNPC.name != "NULL")
		{
			cout << targetNPC.name + ": " + targetNPC.description + "\n";
		}
		else
			cout << "You can't see that NPC.\n";
		return 0;
	}

	if (cmd.action == "attack")
	{
		cout << cmd.action + "|" + cmd.targetA + "|" + cmd.conjunction + "|" + cmd.targetB + "|\n";
		if (cmd.targetA == "")
		{
			cout << "What do you want to attack?\n";
			getline(cin, cmd.targetA);
		}
		NPC targetNPC = findNPC(cmd.targetA);
		if (targetNPC.name != "NULL")
		{
			if (cmd.targetB == "")
			{
				cout << "What do you want to attack the " + targetNPC.name + " with?\n";
				getline(cin, cmd.targetB);
			}
			Item targetItem = findItem(init.inventory, cmd.targetB, true);
			if (targetItem.name != "NULL")
			{
				if (targetItem.type == "weapon")
				{
					if (combatSimulator(targetNPC, targetItem))
					{
						targetItem = findItem(init.items, targetNPC.reward, true);
						init.items = removeItem(init.items, targetItem);
						targetItem.roomLocation = init.currentRoom.name;
						init.items.push_back(targetItem);
						cout << "The " + targetNPC.name + " dropped a " + targetItem.name + "!\n";
						init.NPCs = removeNPC(init.NPCs, targetNPC);
					}
					else
					{
						cout << "Use \" start\" to restart\n";
					}
				}
				else
					cout << "That is not a weapon.\n";
			}
			else
				cout << "You dont have that weapon.\n";
			return 0;
		}
		else
			cout << "You can't see that NPC.\n";
		return 0;
	}

	//CHEATS----------------------------
	if (cmd.action == "cget")
	{
		Item targetItem = findItem(init.items, cmd.targetA, true);
		if (targetItem.name != "NULL")
		{
			init.inventory.push_back(targetItem);
			init.items = removeItem(init.items, targetItem);
			cout << targetItem.name + " taken.\n";
		}
		else
			cout << "That item doesn't exist.\n";
		return 0;
	}

	if (cmd.action == "cwarp")
	{
		Room targetRoom = findRoom(cmd.targetA);
		if (targetRoom.name != "NULL")
		{
			init.loadRoom(targetRoom);
			return 0;
		}
		else
		{
			cout << "That room doesn't exist.\n";
			return 0;
		}
	}

	cout << "Didn't quite get that. Try again.\n";
	return 0;
}