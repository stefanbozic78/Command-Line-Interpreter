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

//Klasa Program simulira operacije interpretera komandne linije
class Program
{
public:
	//Singlton DP. Vraca instancu klase Program
	static Program* getInstance();

	//Simulira sistem
	void program();

	void program2(string Istream1, string ostream1, string output1);

	//Setter
	void setStartSign(string newSign);

	//Getter
	string getStartSign() const;

	//Destruktor
	~Program();

	void destroyInstance();

private:
	//Privatni konstruktor kako bi se sprecilo direktno stvaranje instanci
	Program();
	
	//Staticki pokazivac instancu
	static Program* instance;

	//Pocetni znak za CLI
	string startSign;
};

#endif