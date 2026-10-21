#ifndef TRCOMMAND_H
#define	TRCOMMAND_H
#include <sstream>
#include "Commands.h"
#include "Errors.h"

using namespace std;
// Class TrCommand serves as an command that replaces certain character strings with others or removes them completely.
class TrCommand : public Commands{
public:

	// Construstor taking an General object.
	TrCommand(General* info);

	// Executes the command to replace or remove certain character strings.
	string execute() override;
};

#endif

