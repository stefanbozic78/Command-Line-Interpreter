#ifndef RMCOMMAND_H
#define RMCOMMAND_H


#include "Commands.h"
#include "Errors.h"

using namespace std;

// RmCommand class serves as a command that deletes the file which name was passed through argument.
class RmCommand: public Commands{
public:

	// Construstor taking an General object.
	RmCommand(General* info);

	// Executes the command to delete the file.
	string execute() override;
};

#endif


