#ifndef WCCOMMAND_H
#define WCCOMMAND_H
#include <sstream>
#include "Commands.h"

//Klasa WcCommand sluzi kao komanda koja broji reci ili karaktere u prosledjenoj liniji zavisno od odabrane opcije 
class WcCommand:public Commands {
public:
	//Konstruktor koji prima objekat Gorica
	WcCommand(Gorica* info);

	//Izvrsava komandu koja broji reci ili slova u prosledjenoj liniji zavisno od opcije
	string execute() override;

};


#endif