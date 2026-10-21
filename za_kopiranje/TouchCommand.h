#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H

#include <fstream>
#include "Commands.h"

//Klasa TouchCommand sluzi kao komanda koja otvara fajl sa prosledjenim imenom
class TouchCommand: public Commands {
public:
	//Konstruktor koji uzima objekat Gorica
	TouchCommand(Gorica* info);

	//Izvrsava komandu da otvori fajl sa prosledjenim imenom
	string execute() override;
};

#endif