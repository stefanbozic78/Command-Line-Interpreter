#ifndef ERRORS_H
#define ERRORS_H
#include <exception>
#include <iostream>
#include <string>

using namespace std;
//All errors that may occur are located here


//Error "UnknownCommand"
class UnknownCommand : public exception {
public:
	UnknownCommand(string error) {message = "\nGreska! Nepoznata komanda: " + error + "!";}

	const char* what() const noexcept override { return message.c_str();}
private:
	string message;
};

//Error "UnknownFile"
class UnknownFile : public exception {
public:
	UnknownFile() :exception("\nGreska! Nepoznata putanja do fajla!"){}
};

//Error "UnknownOption"
class UnknownOption : public exception {
public:
	UnknownOption() : exception("\nGreska! Nepoznata opcija za odabranu komandu!") {}
};

//Error "NoOption"(No option is picked)
class NoOption : public exception {
public:
	NoOption() : exception("\nGreska! Morate odabrati neku od opcija!\n ponudjeno: \n -w \n -c") {}
};

//Error "InvalidArgument"
class InvalidArgument : public exception {
public:
	InvalidArgument() : exception("\nGreska! Nepoznati argument!") {}
};


//Error "ExistingFile"
class ExistingFile : public exception {
public:
	ExistingFile() : exception("\nGreska! file vec postoji!") {}
};

//Error "NoQuoteEnd" (For commands like echo, it must contain 2 quote signs)
class NoQuoteEnd : public exception {
public:
	NoQuoteEnd() :exception("\nGreska! Nisu zatvoreni navodnici !") {}
};

//Error "NotExistingOption" (When command needs option in its input)
class NotExistingOption : public std::exception {
public:
	NotExistingOption() : exception("\nGreska! Ova komanda zahteva opciju!") {}

};

//Error "NotExistingArgument" (When command needs argument in its input)
class NotExistingArgument : public std::exception {
public:
	NotExistingArgument() : exception("\nGreska! Ova komanda zahteva argument!") {}

};

//Error "NotAllowedInputRedirection"
class NotAllowedInputRedirection : public std::exception {
public:
	NotAllowedInputRedirection() : exception("\nGreska! Ova komanda ne podrzava ulaznu redirekciju!") {}

};

//Class LexicalMistakes serves to throw error if characters are not expected to be in that particular place
class LexicalMistakes : public std::exception {
public:
	//Constructor that takes string type message 
	LexicalMistakes(string error) {
		message = "\nGreska! Neocekivani karakteri:\n" + error;
	}

	const char* what() const noexcept override {
		return message.c_str();
	}

private:
	string message;
};

//Class ArgumentPipe serves to throw error if the command in the pipeline is not supposed to have argument
class ArgumentInPipe : public std::exception {
public:
	ArgumentInPipe() : exception("\nGreska! Komanda u cevovodu ne moze imati argument!") {}

};
//Class UnaryPipe serves to throw error if the command can only be in the first part of the pipeline
class UnaryPipe : public std::exception {
public:
	UnaryPipe() : exception("\nGreska! Komanda ne sme biti u drugom delu cevovoda!") {}

};









//class LeavingArea : public std::exception {};


#endif 