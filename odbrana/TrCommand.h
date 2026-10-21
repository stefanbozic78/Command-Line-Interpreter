#ifndef TRCOMMAND_H
#define	TRCOMMAND_H
#include <sstream>
#include "Commands.h"
#include "Errors.h"

using namespace std;
class TrCommand : public Commands{
public:
	TrCommand(Gorica* info);

	string execute() override;
};

#endif

