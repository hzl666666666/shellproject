#include "shellExecutor.h"
#include <iostream>
#include <string>

int main() {
    std::string cmdLine;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, cmdLine);
        if (cmdLine == "exit") {
            break;
        }
        ShellExecutor::executeCommand(cmdLine);
    }
    return 0;
}
