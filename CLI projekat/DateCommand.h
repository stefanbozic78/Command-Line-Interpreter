#ifndef DATECOMMAND_H
#define DATECOMMAND_H
#include "Commands.h"

//Class DateComand serves as a command that prints the current time
class DateCommand : public Commands {
public:
	//Constructor that takes object General
	DateCommand(General* info);

	//Executes the command to print current time
	string execute() override;

};
#endif 