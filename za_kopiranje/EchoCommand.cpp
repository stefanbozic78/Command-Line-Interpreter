
#include "EchoCommand.h"

using namespace std;

EchoCommand::EchoCommand(Gorica* info): Commands(info) {}

string EchoCommand::execute() {
    string output = Commands::shared();
    return output;
}
