#ifndef BATCHCOMMAND_H
#define BATCHCOMMAND_H

#include "Commands.h"
//The BatchCommand class serves as a command that executes the command package received by the input stream.
class BatchCommand : public Commands {

public:
	// Construstor taking an General object.
	BatchCommand(General* info);
	// Executes the command to execute the command package received by the input stream.
	string execute() override;
};
#endif
