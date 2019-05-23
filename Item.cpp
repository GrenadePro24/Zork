#include "pch.h"
#include "Item.h"

Item::Item(string name, string type, string location, string description, string roomLocation, bool isLocked, string keyItem, int damage, string content) :
	name(name), type(type), location(location), description(description), roomLocation(roomLocation), isLocked(isLocked), keyItem(keyItem), damage(damage), content(content)
	{
	}

Item::~Item()
{
}
