#ifndef READER_H
#define READER_H
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Errors.h"
using namespace std;

//Klasa Reader sluzi kao apstraktna osnovna klasa za odredjene reader-e 
class Reader
{
public:
	//Konstrutkor koji prima pokazivac na ulazni stream
	Reader(istream* input);

	//Destkrustor
	virtual ~Reader() = default;
	
	//Proverava da li je doslo do kraja ulaznog stream-a (trazi se EOF)
	virtual bool isEnd();

	//Cita liniju sa ulaznog stream-a
	virtual string readLine();

	virtual streampos getPosition() { return m_input->tellg(); }
	
	virtual void setPosition(streampos pos) { m_input->seekg(pos); }
protected:
	//Pokazivac na ulazni stream
	istream* m_input;
};

//Izvedena klasa ConsoleReader sluzi kao citac iz konzole(standardnog ulaza) 
class ConsoleReader : public Reader {
public:
	//Singlton DP. Vraca instancu klase ConsoleReader
	static ConsoleReader* getInstance();

	//Cita liniju sa konzole(standardnog ulaza)
	virtual string readLine() override;

	//Setter
	void setIStream(string istream);

	static void destroyInstance();
	
	streampos getPosition() override {
		if (m_input == &cin) return 0;
		return Reader::getPosition();
	}
	void setPosition(streampos pos) override {
		if (m_input != &cin) {
			Reader::setPosition(pos);
		}
	}
	string getCurrentFile() const { return currentFile; }
	bool isInFile() const { return m_input != &cin; }


	bool isAtEnd();
	
private:
	//Privatni konstruktor kako bi se sprecilo direktno stvaranje instanci
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

//Izvedena klasa FileReader sluzi kao citac iz fajla
class FileReader : public Reader {
public:
	//Konstruktor koji prima putanju do fajla
	FileReader(string path);

	//Destruktor
	~FileReader();
	
	//Proverava da li je otvoren fajl
	bool isFileOpen() const;
};

#endif