#ifndef BATCHCOMMAND_H
#define BATCHCOMMAND_H

#include "Commands.h"
class BatchCommand : public Commands {

public:

	BatchCommand(Gorica* info);
	
	string execute() override;
};
#endif
