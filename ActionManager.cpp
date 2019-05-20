#include "pch.h"
#include "PZT.cpp"
#include "ActionManager.h"
#include "Warp.h"
#include <algorithm>
using namespace std;
Warp findWarp(string target)
{
	Warp resultWarp = Warp("NULL", "NULL", "NULL", "NULL", "NULL", false, "NULL");
	for(Warp results : warps)
	{
		string resultName = results.name;
		transform(resultName.begin(), resultName.end(), resultName.begin(), tolower);
		transform(target.begin(), target.end(), target.begin(), tolower);
		if (resultName == target && results.roomLocation == currentRoom.name)
			resultWarp = results;
	}
	return resultWarp;
}

Item findItem(list<Item> list, string target, bool overrideRoom)
{
	Item resutlItem = Item("NULL", "NULL", "NULL", "NULL", "NULL", false, 0, NULL);
	for(Item results : list)
	{
		string resultName = results.name;
		transform(resultName.begin(), resultName.end(), resultName.begin(), tolower);
		transform(target.begin(), target.end(), target.begin(), tolower);
		if (resultName == target && (results.roomLocation == currentRoom.name || overrideRoom))
			resutlItem = results;
	}
	return resutlItem;
}

NPC findNPC(string target)
{
	NPC resultNPC = NPC("NULL", "NULL", "NULL", "NULL", 0, 0, "NULL", "NULL");
	for(NPC results : NPCs)
	{
		string resultName = results.name;
		transform(resultName.begin(), resultName.end(), resultName.begin(), tolower);
		transform(target.begin(), target.end(), target.begin(), tolower);
		if (resultName == target && results.roomLocation == currentRoom.name)
			resultNPC = results;
	}
	return resultNPC;
}

Room findRoom(string target)
{
	Room resultRoom = Room("NULL", "NULL");
	for(Room results : rooms)
	{
		string resultName = results.name;
		transform(resultName.begin(), resultName.end(), resultName.begin(), tolower);
		transform(target.begin(), target.end(), target.begin(), tolower);
		if (resultName == target)
			resultRoom = results;
	}
	return resultRoom;
}

void ActionManager::chooseAction(Command cmd, Room currentRoom)
{
}
