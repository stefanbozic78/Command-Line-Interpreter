#ifndef RMCOMMAND_H
#define RMCOMMAND_H


#include "Commands.h"
#include "Errors.h"

using namespace std;

class RmCommand: public Commands{
public:
	RmCommand(Gorica* info);

	string execute() override;
};

#endif


