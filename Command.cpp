#include "pch.h"
#include "Command.h"
#include <string>

Command::Command(string action, string targetA, string conjunction, string targetB) :
	action(action), targetA(targetA), conjunction(conjunction), targetB(targetB)
	{
	}

Command::~Command()
{
}
