#ifndef ERRORS_H
#define ERRORS_H
#include <exception>
#include <iostream>
#include <string>

using namespace std;
//Sve greske koje mogu da se pojave se nalaze ovde 


//Greska "Nepoznata komanda"
class UnknownCommand : public exception {
public:
	UnknownCommand(string error) {message = "\nGreska! Nepoznata komanda: " + error + "!";}

	const char* what() const noexcept override { return message.c_str();}
private:
	string message;
};

//Greska "Nepoznat fajl"
class UnknownFile : public exception {
public:
	UnknownFile() :exception("\nGreska! Nepoznata putanja do fajla!"){}
};

//Greska "Nepoznata opcija"
class UnknownOption : public exception {
public:
	UnknownOption() : exception("\nGreska! Nepoznata opcija za odabranu komandu!") {}
};

//Greska "Nije odabrana opcija"
class NoOption : public exception {
public:
	NoOption() : exception("\nGreska! Morate odabrati neku od opcija!\n ponudjeno: \n -w \n -c") {}
};

//Greska "Nepoznat argument"
class InvalidArgument : public exception {
public:
	InvalidArgument() : exception("\nGreska! Nepoznati argument!") {}
};


//Greska "Fajl vec postoji"
class ExistingFile : public exception {
public:
	ExistingFile() : exception("\nGreska! file vec postoji!") {}
};

//Greska "Navodnici nisu zatvoreni"
class NoQuoteEnd : public exception {
public:
	NoQuoteEnd() :exception("\nGreska! Nisu zatvoreni navodnici !") {}
};


class NotExistingOption : public std::exception {
public:
	NotExistingOption() : exception("\nGreska! Ova komanda zahteva opciju!") {}

};


class NotExistingArgument : public std::exception {
public:
	NotExistingArgument() : exception("\nGreska! Ova komanda zahteva argument!") {}

};


class NotAllowedInputRedirection : public std::exception {
public:
	NotAllowedInputRedirection() : exception("\nGreska! Ova komanda ne podrzava ulaznu redirekciju!") {}

};



class LexicalMistakes : public std::exception {
public:
	LexicalMistakes(string error) {
		message = "\nGreska! Neocekivani karakteri:\n" + error;
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	string message;
};

class ArgumentInPipe : public std::exception {
public:
	ArgumentInPipe() : exception("\nGreska! Komanda u cevovodu ne moze imati argument!") {}

};

class UnaryPipe : public std::exception {
public:
	UnaryPipe() : exception("\nGreska! Komanda ne sme biti u drugom delu cevovoda!") {}

};









//class LeavingArea : public std::exception {};


#endif 