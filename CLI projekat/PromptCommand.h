#ifndef PROMPTCOMMAND_H
#define PROMPTCOMMAND_H

#include "Commands.h"
#include "Errors.h"

//Class PromptCommand serves as an command that changes the start sign of CLI.
class PromptCommand: public Commands {

public:
	// Construstor taking an General object.
	PromptCommand(General* info);

	// Executes the command to change the start sign of CLI.
	string execute() override;

	};

#endif
