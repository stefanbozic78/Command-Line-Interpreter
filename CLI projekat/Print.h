#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include<fstream>
#include <string>


using namespace std;

// Class Print serves as a printer of the output content
class Print {
public:
	// Singlton DP. Returns an intstance of the class Print
	static Print* getInstance();

	static void destroyInstance();

	// Setter function
	void setOstream(string ostream, string output);

	// Prints a line to the output stream
	void realPrint(string output,string flag);

private:
	// Private constructor to prevent direct instantiation
	Print();

	~Print();
	// Static pointer to single instance
	static Print* instance;
	
	// Pointer to the output stream
	ostream* m_output;

	// Output file stream	
	ofstream m_fileStream;

	string currentFile;

	string currentMode;
};

#endif