
#include "EchoCommand.h"

using namespace std;

EchoCommand::EchoCommand(General* info): Commands(info) {}

string EchoCommand::execute() {
    string output = Commands::shared();
    return output;
}
