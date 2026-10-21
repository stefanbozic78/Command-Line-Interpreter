#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include "Reader.h"
#include "Parser.h"
#include "Commands.h"
#include "TimeCommand.h"
#include "Print.h"
#include "DateCommand.h"
#include "Errors.h"
#include "EchoCommand.h"
#include "WcCommand.h"
#include "TouchCommand.h"
#include "RmCommand.h"
#include "TruncateCommand.h"
#include "TrCommand.h"
#include "HeadCommand.h"
#include "BatchCommand.h"

using namespace std;

//Class Program simulates command line interpreter operations
class Program
{
public:
	//Singlton DP. Returns an instance of the class Program
	static Program* getInstance();

	//Simulates the system
	void program();
	//Helper function
	void program2(string Istream1, string ostream1, string output1);

	//Setter
	void setStartSign(string newSign);

	//Getter
	string getStartSign() const;

	//Destructor
	~Program();

	void destroyInstance();

private:

	// Private constructor to prevent direct instantiation
	Program();
	
	// Static pointer to the instance
	static Program* instance;

	//Starting sign for the CLI
	string startSign;
};

#endif