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
		input = input.erase(0, input.find(' '));
		if(input.find_first_of(' ') == 0)
			input = input.erase(0, 1);
	}
	while (input.length() > 0)
	{
		if (isConjunction(input.substr(0, input.find(' '))))
		{
			targetCommand.conjunction = input.substr(0, input.find(' '));
			input = input.erase(0, input.find(' '));
			if (input.find_first_of(' ') == 0)
				input = input.erase(0, 1);
			break;
		}
		else
		{
			targetCommand.targetA += input.substr(0, input.find(' '));
			input = input.erase(0, input.find(' '));
			if (input.find_first_of(' ') == 0)
			{
				input = input.erase(0, 1);
				targetCommand.targetA += " ";
			}
		}
	}
	if (input.length() > 0)
	{
		targetCommand.targetB = input;
	}
	if (targetCommand.targetA.length() > 0 && targetCommand.targetA.find_last_of(' ') == targetCommand.targetA.length() - 1)
		targetCommand.targetA.erase(targetCommand.targetA.length() - 1, 1);
	if (targetCommand.targetB.length() > 0 && targetCommand.targetB.find_last_of(' ') == targetCommand.targetB.length() - 1)
		targetCommand.targetB.erase(targetCommand.targetB.length() - 1, 1);
	return targetCommand;
}