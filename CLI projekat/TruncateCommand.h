#ifndef TRUNCATECOMMAND_H
#define TRUNCATECOMMAND_H
#include <iostream>
#include <fstream>
#include "Commands.h"
#include "Errors.h"
using namespace std;

//Class TruncateCommand serves as a command that deletes all the contents of the file.
class TruncateCommand: public Commands {
public:

	// Construstor taking an Elem object.
	TruncateCommand(General* info);

	// Executes the command to delete all the contents of the file.
	string execute() override;

};

#endif
