#include "shellExecutor.h"
#include "CommandLineParser.h"
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

int ShellExecutor::executeCommand(const std::string& cmdLine) {
    CommandLineParser parser(cmdLine);
    std::vector<std::string> arguments = parser.getArguments();

    char** args = new char*[arguments.size() + 1];
    for (size_t i = 0; i < arguments.size(); i++) {
        args[i] = const_cast<char*>(arguments[i].c_str());
    }
    args[arguments.size()] = nullptr;

    pid_t pid = fork();
    if (pid == 0) {
        if (!parser.getInputRedirect().empty()) {
            freopen(parser.getInputRedirect().c_str(), "r", stdin);
        }
        if (!parser.getOutputRedirect().empty()) {
            freopen(parser.getOutputRedirect().c_str(), "w", stdout);
        }

        if (execvp(args[0], args) == -1) {
            std::cerr << "Error executing command" << std::endl;
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
    } else {
        std::cerr << "Fork failed" << std::endl;
    }

    delete[] args;

    return 0;
}
