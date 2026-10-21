
#include "Print.h"

Print* Print::instance = nullptr;

Print::Print(): m_output(&cout) {}

Print::~Print() {
    if (m_fileStream.is_open()) m_fileStream.close();
}

Print* Print::getInstance() {
	if (instance == nullptr) {
		instance = new Print();}

	return instance;
}

void Print::destroyInstance() {
    delete instance;
    instance = nullptr;
}


void Print::setOstream(string outstream, string output) {
    if (outstream == currentFile && output == currentMode) {
        return;
    }

    if (m_fileStream.is_open()) {
       
        m_fileStream.close();
       
    }

    if (!outstream.empty()) {
        
        m_fileStream.clear();

        if (output == ">") {
            
            m_fileStream.open(outstream, ios::out);


        }
        else if (output == ">>") {
            
            m_fileStream.open(outstream, ios::app);
    }

        m_output = &m_fileStream;
        currentFile = outstream;
        currentMode = output;

       
    }                                   
    else { 
        m_output = &cout;
        currentFile = "";
        currentMode = "";
    }
}
   
void Print::realPrint(string output,string outputFile ) {
   
    if (output != "" && outputFile.empty()) *m_output << '\n' << output << endl;
    else *m_output << output;

}
