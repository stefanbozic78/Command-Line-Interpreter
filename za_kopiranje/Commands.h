#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include<string>
#include "Reader.h"
#include "Errors.h"
using namespace std;

//Podaci vezani za komandu(argument, opcija, komanda...)
struct Gorica{
	string cmd, opt, arg, flag, what, with;
	string input, output, outputFile;
	int pipe;
};

//Klasa Commands sluzi kao apstraktna osnovna klasa za komande
class Commands{
public:
	//Konstruktor ove klase, prihvata pokazivac na strukturu Gorica koja sadrzi podatke komande
	Commands(Gorica* info);

	//Destruktor
	~Commands();

	//Apstraktna funkcija koju ce da nasledjuju sve komande
	virtual string execute() = 0;
protected:
	//Pokazivac na podatke komande
	Gorica* m_Gorica;

	//Cita podake u zavisnosti od flag-a koji parser prosledi 
	string shared(); 

};
#endif 