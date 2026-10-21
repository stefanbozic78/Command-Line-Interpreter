#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H

#include <fstream>
#include "Commands.h"

//Class TouchCommand serves as command that opens file with passed name
class TouchCommand: public Commands {
public:
	//Constructor that takes an object General
	TouchCommand(General* info);

	//Executes command to open file with the passed name
	string execute() override;
};

#endif