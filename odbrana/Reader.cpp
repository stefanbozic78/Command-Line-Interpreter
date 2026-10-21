#include "Reader.h"

Reader::Reader(istream* input): m_input(input) {}

//Reader::~Reader() = default;

void ConsoleReader::destroyInstance() {
	delete instance;
	instance = nullptr;
}

bool Reader::isEnd()
{
	return m_input->eof();
}

string Reader::readLine() {
	string line;
	getline(*m_input, line);
	//if (line.length() > 512) line = line.substr(0, 512);
	return line;
}

ConsoleReader* ConsoleReader::instance = nullptr;

ConsoleReader::ConsoleReader() : Reader(&cin) {}

ConsoleReader* ConsoleReader::getInstance() {
	if (instance == nullptr) {
		instance = new ConsoleReader();
	}
	return instance;
}
string ConsoleReader::readLine()
{
	return Reader::readLine();
}

bool ConsoleReader::isAtEnd() {
    if (m_fileStream.is_open()) {
        return m_fileStream.eof() || m_fileStream.fail() ;
    }
    return m_input->eof();
}

void ConsoleReader::setIStream(string istream) {
    if (!istream.empty()) {
        // 1: Vracanje sa cin-a na fajl
        if (!m_fileStream.is_open() && istream == m_savedFileBeforeCin) {
    
            m_fileStream.clear();
            m_fileStream.open(istream);
            if (m_fileStream.is_open()) {
                m_fileStream.seekg(m_savedPosBeforeCin);
                m_input = &m_fileStream;
                currentFile = istream;
                m_savedFileBeforeCin = "";
                m_savedPosBeforeCin = 0;
                return;
            }
            else throw UnknownFile();
        }

        // 2 Isti fajl koji je vec otvoren
        if (m_fileStream.is_open() && currentFile == istream) {return;}

        //  3 Vracanje na fajl sa steka 
        if (!fileStack.empty() && fileStack.top().filename == istream) {

            if (m_fileStream.is_open()) {
                m_fileStream.close();
            }

            m_fileStream.open(istream);
            if (m_fileStream.is_open()) {
                m_fileStream.seekg(fileStack.top().position);
                m_input = &m_fileStream;
                currentFile = istream;
                fileStack.pop();
               
                return;
            }
        }
        //else throw UnknownFile;

        //  4 Prelazak sa fajla na drugi fajl
      
        if (m_fileStream.is_open()) {
     
            fileStack.push({ currentFile, m_fileStream.tellg() });
            m_fileStream.close();
        }
          
        // Otvoram novi fajl
   
        m_fileStream.clear();
        m_fileStream.open(istream);
   
        if (m_fileStream.is_open()) {
            m_input = &m_fileStream;
            currentFile = istream;
     
        }
        else throw UnknownFile();
    }
    else {
        //  5 Prelazak na cin
    
        if (m_fileStream.is_open()) {
        
            streampos pos = m_fileStream.tellg();
            if (pos != -1) {  
                m_savedFileBeforeCin = currentFile;
                m_savedPosBeforeCin = pos;
            }

            m_fileStream.close();
            currentFile = "";
        }
        m_input = &cin;
    }
}

FileReader::FileReader(string path): Reader(new ifstream(path)) {}

FileReader::~FileReader() {
	((ifstream*)m_input)->close();
	delete m_input;
}

bool FileReader::isFileOpen() const {
	return ((ifstream*)m_input)->is_open();
}