#include "Commands.h"


Commands::Commands(Gorica* info): m_Gorica(info) {}

Commands::~Commands() = default;

 string Commands::shared()
{
    string output = "";
    if(m_Gorica->pipe == 1) return m_Gorica->arg;
    if (m_Gorica->flag == "quote") {
        return m_Gorica->arg;
    }
    else if (m_Gorica->flag == "file") {
        FileReader* reader = new FileReader(m_Gorica->arg);

        if (!reader->isFileOpen()) throw UnknownFile();

        while (!reader->isEnd()) {
            string line = reader->readLine(); 
            output += line;
            if (m_Gorica->cmd == "unique")output += "\n";
        }
        delete reader;
    }

    else {
        ConsoleReader* reader = ConsoleReader::getInstance();
        string line;
        string stariFajl = reader->getCurrentFile();
        streampos staraPozicija = reader->getPosition();
        reader->setIStream("");

        cout << endl;
       
        while (true) {
            line += reader->readLine();

            if (reader->isEnd()) {
                cin.clear();
                break;
            }
            line += '\n';
        }
      
        output += line;
        if (!stariFajl.empty()) {
            reader->setIStream(stariFajl);
            reader->setPosition(staraPozicija);
        }
    }
    return output;
 }


