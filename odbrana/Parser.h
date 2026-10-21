#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "Commands.h"
#include"Reader.h"
using namespace std;

//klasa Parser  sluzi kao parser zacelu liniju 
class Parser {
public:

	//Konstruktor koji uzima Reader objekat
	Parser(Reader* reader);

	//Destruktor
	~Parser();
	
	//Parsira prosledjenu liniju u delove jedne komande
	unique_ptr<Gorica> parseCommand(const string& line);

	vector<string> Pipe(string line);

	vector<size_t> Lexer(string line);
	
private:

	//Pomocne funkcije 
	void passSpace(string line, size_t &i, size_t len);
	void getWord(string line, size_t& i, size_t len, string& cmd);
	void getQuotes(string line, size_t& i, size_t len, string& cmd);
	void getAllQuotes(string line, size_t& i, size_t len, string& cmd,string& flag);
	void proveraIzlaza(string line, size_t& i, size_t len, string& output);
	bool isPath(char c);
	bool isAllowedOutsideQuotes(char c);
	vector<string> Pipe2(string line, char stopSymbol);
	void trHelper(string line, size_t& i, size_t& len, string& flag, string& what, string& with);

	//Pokazivac na Reader objekat
	Reader* m_reader;
};


#endif 