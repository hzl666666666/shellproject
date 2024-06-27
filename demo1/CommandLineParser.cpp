#include "CommandLineParser.h"
#include <sstream>
#include <iostream>

CommandLineParser::CommandLineParser(const std::string& cmdLine) : cmdLine(cmdLine), pipe(false) {
    parseCommandLine();
}

void CommandLineParser::parseCommandLine() {
    std::istringstream iss(cmdLine);
    std::string token;
    bool inputRedirectFlag = false;
    bool outputRedirectFlag = false;

    while (iss >> token) {
        if (token == "<") {
            inputRedirectFlag = true;
            continue;
        }
        if (token == ">") {
            outputRedirectFlag = true;
            continue;
        }
        if (token == "|") {
            pipe = true;
            iss >> pipeCommand;
            break;
        }

        if (inputRedirectFlag) {
            inputRedirect = token;
            inputRedirectFlag = false;
        } else if (outputRedirectFlag) {
            outputRedirect = token;
            outputRedirectFlag = false;
        } else {
            arguments.push_back(token);
        }
    }
}

std::vector<std::string> CommandLineParser::getArguments() {
    return arguments;
}

std::string CommandLineParser::getInputRedirect() {
    return inputRedirect;
}

std::string CommandLineParser::getOutputRedirect() {
    return outputRedirect;
}

bool CommandLineParser::hasPipe() {
    return pipe;
}

std::string CommandLineParser::getPipeCommand() {
    return pipeCommand;
}
