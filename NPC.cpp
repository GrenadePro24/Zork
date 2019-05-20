#include "pch.h"
#include "NPC.h"
#include <string>

NPC::NPC(string name, string location, string description, string roomLocation, int hitpoints, int strength, string keyItem, string reward) :
	name(name), location(location), roomLocation(roomLocation), hitpoints(hitpoints), strength(strength), keyItem(keyItem), reward(reward)
	{
	}

NPC::~NPC()
{
}
