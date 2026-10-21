#ifndef PROMPTCOMMAND_H
#define PROMPTCOMMAND_H

#include "Commands.h"
#include "Errors.h"


class PromptCommand: public Commands {

public:
	PromptCommand(Gorica* info);

	string execute() override;

	};

#endif
