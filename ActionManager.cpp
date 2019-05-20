#include "pch.h"
#include "ActionManager.h"
#include "Init.h"
#include "Warp.h"
#include "Item.h"
#include "Room.h"
#include "NPC.h"
#include <algorithm>
#include <iostream>
using namespace std;
Init init;
//Warp findWarp(string target)
//{
//	Warp resultWarp = Warp("NULL", "NULL", "NULL", "NULL", "NULL", false, "NULL");
//	for(Warp results : warps)
//	{
//		string resultName = results.name;
//		transform(resultName.begin(), resultName.end(), resultName.begin(), tolower);
//		transform(target.begin(), target.end(), target.begin(), tolower);
//		if (resultName == target && results.roomLocation == currentRoom.name)
//			resultWarp = results;
//	}
//	return resultWarp;
//}
//
//Item findItem(list<Item> list, string target, bool overrideRoom)
//{
//	Item resutlItem = Item("NULL", "NULL", "NULL", "NULL", "NULL", false, 0, NULL);
//	for(Item results : list)
//	{
//		string resultName = results.name;
//		transform(resultName.begin(), resultName.end(), resultName.begin(), tolower);
//		transform(target.begin(), target.end(), target.begin(), tolower);
//		if (resultName == target && (results.roomLocation == currentRoom.name || overrideRoom))
//			resutlItem = results;
//	}
//	return resutlItem;
//}
//
//NPC findNPC(string target)
//{
//	NPC resultNPC = NPC("NULL", "NULL", "NULL", "NULL", 0, 0, "NULL", "NULL");
//	for(NPC results : NPCs)
//	{
//		string resultName = results.name;
//		transform(resultName.begin(), resultName.end(), resultName.begin(), tolower);
//		transform(target.begin(), target.end(), target.begin(), tolower);
//		if (resultName == target && results.roomLocation == currentRoom.name)
//			resultNPC = results;
//	}
//	return resultNPC;
//}
//
//Room findRoom(string target)
//{
//	Room resultRoom = Room("NULL", "NULL");
//	for(Room results : rooms)
//	{
//		string resultName = results.name;
//		transform(resultName.begin(), resultName.end(), resultName.begin(), tolower);
//		transform(target.begin(), target.end(), target.begin(), tolower);
//		if (resultName == target)
//			resultRoom = results;
//	}
//	return resultRoom;
//}
//
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

	if (cmd.action == "exit" || cmd.action == "quit")
	{
		cout << "Why ya leavin?\n";
		return 0;
	}

	return 1;
}