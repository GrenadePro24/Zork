#ifndef ActionManager_
#define ActionManager_
#include "Command.h"
#include "Room.h"

class ActionManager
{
	public:
		void chooseAction(Command cmd, Room currentRoom);
};

#endif
