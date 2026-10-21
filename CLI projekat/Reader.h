#ifndef READER_H
#define READER_H
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Errors.h"
using namespace std;
 
// Class Reader serves as an abstract base class for certain readers
class Reader
{
public:
	// Constructor that receives a pointer to the input stream
	Reader(istream* input);

	// Destructor
	virtual ~Reader() = default;
	
	// Checking whether the end of input stream has been reached (looking for EOF)
	virtual bool isEnd();

	// Reads a line from the input stream
	virtual string readLine();

	virtual streampos getPosition() { return m_input->tellg(); }
	
	virtual void setPosition(streampos pos) { m_input->seekg(pos); }
protected:

	// Pointer to the input stream
	istream* m_input;
};

// The derived class ConsoleReader serves as reader from the console(standard input)
class ConsoleReader : public Reader {
public:
	// Singlton DP. Returns an instance of the class ConsoleReader 
	static ConsoleReader* getInstance();

	// Reades a line from the console(standard input)
	virtual string readLine() override;

	//Setter
	void setIStream(string istream);

	static void destroyInstance();
	
	// Gets current position
	streampos getPosition() override {
		if (m_input == &cin) return 0;
		return Reader::getPosition();
	}
	// Sets position
	void setPosition(streampos pos) override {
		if (m_input != &cin) {
			Reader::setPosition(pos);
		}
	}
	//Gets current file
	string getCurrentFile() const { return currentFile; }

	//Checks if reading is from filestream 
	bool isInFile() const { return m_input != &cin; }

	bool isAtEnd();
	
private:
	//Private constructor to prevent direct instantiation
	ConsoleReader();

	//Staticki pokazivac instancu
	static ConsoleReader* instance;
	
	//Input file stream
	ifstream m_fileStream;

	string currentFile;
	string m_savedFileBeforeCin;      
	streampos m_savedPosBeforeCin;

	struct FileInfo {
		string filename;
		streampos position;
	};
	stack<FileInfo> fileStack;

};

//Derived class FileReader serves as reader from a file
class FileReader : public Reader {
public:
	//Constructor that receives path to the file
	FileReader(string path);

	//Destructor
	~FileReader();
	
	//Checks if file is opened
	bool isFileOpen() const;
};

#endif