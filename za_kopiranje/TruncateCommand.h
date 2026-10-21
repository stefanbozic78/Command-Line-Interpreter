#ifndef TRUNCATECOMMAND_H
#define TRUNCATECOMMAND_H
#include <iostream>
#include <fstream>
#include "Commands.h"
#include "Errors.h"
using namespace std;

class TruncateCommand: public Commands {
public:
	TruncateCommand(Gorica* info);

	string execute() override;

};

#endif
