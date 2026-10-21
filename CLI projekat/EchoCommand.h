#ifndef ECHO_H
#define ECHO_H

#include "Commands.h"
#include "Reader.h"
#include "Errors.h"

//Class EchoCommand servess as command that prints the passed or entered arguments
class EchoCommand : public Commands {
public:
	//Constructor that takes object General
	EchoCommand(General* info);

	//Executes the print command
	string execute() override;

};

#endif 