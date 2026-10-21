#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include<string>
#include "Reader.h"
#include "Errors.h"
using namespace std;

//Data related to the command(argument, options,command...)
struct General{
	string cmd, opt, arg, flag, what, with;
	string input, output, outputFile;
	int pipe;
};

//Class Commands serves as an abstract base class for commands
class Commands{
public:
	
	//Constructor of this class, accepts pointer to the structure General that contains the command data
	Commands(General* info);

	//Destructor
	~Commands();

	//Abstract function that will be inherited by all commands 
	virtual string execute() = 0;
protected:
	//Pointer to command data
	General* m_General;
 
	//Reads data depending on the flag passed by parser 
	string shared(); 

};
#endif 