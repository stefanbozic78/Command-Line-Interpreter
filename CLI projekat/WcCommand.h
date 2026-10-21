#ifndef WCCOMMAND_H
#define WCCOMMAND_H
#include <sstream>
#include "Commands.h"
 
//Class WcCommand serves as command that counts words or characters in the passed line depending on the selected option
class WcCommand:public Commands {
public:

	//Constructor that receives an object General
	WcCommand(General* info);

	//Executes a command that counts words or characters in the passed line dependiong on the option
	string execute() override;

};


#endif