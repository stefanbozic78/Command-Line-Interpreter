#ifndef TIMECOMMAND_H
#define TIMECOMMAND_H

#include "Commands.h"
#include <ctime>

//Class TimeCommand serves as command that prints the current time
class TimeCommand : public Commands {
public:

	//Constructor that takes an object General
	TimeCommand(General* info);

	//Executes command to print the current time
	string execute() override;

};

#endif