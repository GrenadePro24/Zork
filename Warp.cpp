#include "pch.h"
#include "Warp.h"
#include <string>

Warp::Warp(string name, string type, string description, string targetRoom, string roomLocation, bool isLocked, string keyItem) :
	name(name), type(type), description(description), targetRoom(targetRoom), roomLocation(roomLocation), isLocked(isLocked), keyItem(keyItem)
	{
	}

Warp::~Warp()
{
}
