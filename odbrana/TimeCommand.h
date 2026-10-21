#ifndef TIMECOMMAND_H
#define TIMECOMMAND_H

#include "Commands.h"
#include <ctime>

//Klasa TimeCommand sluzi kao komanda koja ispisuje trenutno vreme
class TimeCommand : public Commands {
public:
	//Konstruktor koji uzima objekat Gorica
	TimeCommand(Gorica* info);

	//Izvrsava komandu za ispis trenutnog vremena
	string execute() override;

};

#endif