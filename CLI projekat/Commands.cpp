#include "Commands.h"


Commands::Commands(General* info): m_General(info) {}

Commands::~Commands() = default;

 string Commands::shared()
{
    string output = "";
    if(m_General->pipe == 1) return m_General->arg;
    if (m_General->flag == "quote") {
        return m_General->arg;
    }
    else if (m_General->flag == "file") {
        FileReader* reader = new FileReader(m_General->arg);

        if (!reader->isFileOpen()) throw UnknownFile();

        while (!reader->isEnd()) {
            string line = reader->readLine(); 
            output += line;
            if (m_General->cmd == "unique")output += "\n";
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


