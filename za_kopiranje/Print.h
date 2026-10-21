#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include<fstream>
#include <string>


using namespace std;

//klasa Print sluzi kao stampac izlaznog sadrzaja
class Print {
public:
	//Singlton DP. Vraca instancu klase Print
	static Print* getInstance();

	static void destroyInstance();

	//Setter funkcija
	void setOstream(string ostream, string output);

	//Ispisuje liniju na output stream
	void realPrint(string output,string flag);

private:
	//Privatni konstruktor da bi se sprecilo direktno stvaranje instanci
	Print();

	~Print();
	//Staticki pokazivac na single instancu
	static Print* instance;
	
	//Pokazivac na output stream
	ostream* m_output;

	//Output fajl stream	
	ofstream m_fileStream;

	string currentFile;

	string currentMode;
};

#endif