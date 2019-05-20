#ifndef ActionManager_
#define ActionManager_
#include "Command.h"
#include "Room.h"

class ActionManager
{
	public:
		int chooseAction(Command cmd);
};

#endif
