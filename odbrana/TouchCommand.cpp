#include "TouchCommand.h"

TouchCommand::TouchCommand(Gorica* info): Commands(info) {}

string TouchCommand::execute() {
    if (m_Gorica->arg.empty()) throw InvalidArgument();
    ifstream check(m_Gorica->arg);
    if (check.good()) {
        throw ExistingFile(); 
    }

 
    std::ofstream file(m_Gorica->arg);
    if (!file) {
        throw UnknownFile(); 
    }

    file.close();
    return "";
}
