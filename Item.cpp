#include "pch.h"
#include "Item.h"

Item::Item(string name, string type, string location, string description, string roomLocation, bool isPickup, int damage, string content) :
	name(name), type(type), location(location), description(description), roomLocation(roomLocation), isPickup(isPickup), damage(damage), content(content)
	{
	}

Item::~Item()
{
}
