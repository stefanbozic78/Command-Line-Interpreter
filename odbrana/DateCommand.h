#ifndef DATECOMMAND_H
#define DATECOMMAND_H
#include "Commands.h"

//Klasa DateCommand sluzi kao komanda koja ispisuje trenutno vreme
class DateCommand : public Commands {
public:
	//Konstruktor koji uzima objekat Gorica
	DateCommand(Gorica* info);

	//Izvrsava komandu da ispisuje trenutno vreme
	string execute() override;

};
#endif 