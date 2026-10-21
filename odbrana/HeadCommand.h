#ifndef HEADCOMMAND_H
#define HEADCOMMAND_H

#include <sstream>
#include <vector>

#include "Commands.h"
#include "Errors.h"

using namespace std;
class HeadCommand : public Commands{
public:
	HeadCommand(Gorica* info);

	string execute() override;
};

#endif

