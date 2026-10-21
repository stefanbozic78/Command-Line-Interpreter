#ifndef ECHO_H
#define ECHO_H

#include "Commands.h"
#include "Reader.h"
#include "Errors.h"

//Klasa EchoCommand sluzi kao komanda koja ispisuje prosledjene ili unete argumente
class EchoCommand : public Commands {
public:
	//Konstrutkor koji uzima objekat Gorica
	EchoCommand(Gorica* info);

	//Izvrsava komandu ispisa 
	string execute() override;

};

#endif 