#include "pch.h"
#include "Command.h"
#include "Parser.h"
#include <list>
#include <string>

#include <iostream>

list<string> conjunctions = {"with", "on"};

bool isConjunction(string target)
{
	for (string listedConjunction : conjunctions)
	{
		if (target == listedConjunction)
		{
			return true;
		}
	}
	return false;
}

Command Parser::parseCommand(string input)
{
	Command targetCommand = Command("", "", "", "");
	if (input.length() > 0)
	{
		targetCommand.action = input.substr(0, input.find(' '));
		input = input.erase(0, input.find(' ') + 1);
	}
	while (input.length() > 0)
	{
		if (isConjunction(input.substr(0, input.find(' '))))
		{
			targetCommand.conjunction = input.substr(0, input.find(' '));
			input = input.erase(0, input.find(' ') + 1);
			break;
		}
		else
		{
			targetCommand.targetA += input.substr(0, input.find(' '));
			input = input.erase(0, input.find(' ') + 1);
		}
	}
	if (input.length() > 0)
	{
		targetCommand.targetB = input;
	}
	return targetCommand;
}