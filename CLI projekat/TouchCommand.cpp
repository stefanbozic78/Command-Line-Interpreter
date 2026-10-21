#include "TouchCommand.h"

TouchCommand::TouchCommand(General* info): Commands(info) {}

string TouchCommand::execute() {
    if (m_General->arg.empty()) throw InvalidArgument();
    ifstream check(m_General->arg);
    if (check.good()) {
        throw ExistingFile(); 
    }

 
    std::ofstream file(m_General->arg);
    if (!file) {
        throw UnknownFile(); 
    }

    file.close();
    return "";
}
