#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "Commands.h"
#include"Reader.h"
using namespace std;

// Class Parser serves as parser for the entire line
class Parser {
public:

	//Constructor that takes a Reader object
	Parser(Reader* reader);

	//Destructor
	~Parser();
	
	//Parses the passed line into parts of a single command
	unique_ptr<General> parseCommand(const string& line);

	vector<string> Pipe(string line);

	vector<size_t> Lexer(string line);
	
private:

	//Helper functions
	void passSpace(string line, size_t &i, size_t len);
	void getWord(string line, size_t& i, size_t len, string& cmd);
	void getQuotes(string line, size_t& i, size_t len, string& cmd);
	void getAllQuotes(string line, size_t& i, size_t len, string& cmd,string& flag);
	void proveraIzlaza(string line, size_t& i, size_t len, string& output);
	bool isPath(char c);
	bool isAllowedOutsideQuotes(char c);
	vector<string> Pipe2(string line, char stopSymbol);
	void trHelper(string line, size_t& i, size_t& len, string& flag, string& what, string& with);

	//Pointer to the Reader object
	Reader* m_reader;
};


#endif 