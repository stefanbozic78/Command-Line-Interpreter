#ifndef HEADCOMMAND_H
#define HEADCOMMAND_H

#include <sstream>
#include <vector>

#include "Commands.h"
#include "Errors.h"

using namespace std;
//Class HeadCommand serves as a command that prints the first few lines from the input stream
class HeadCommand : public Commands{
public:

	// Construstor taking an General object.
	HeadCommand(General* info);

	// Executes the command to print the first few lines.
	string execute() override;
};

#endif

