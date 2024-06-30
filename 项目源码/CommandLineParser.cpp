#include "CommandLineParser.h"
#include <sstream>
#include <iostream>

// 构造函数，初始化成员变量并解析命令行。
CommandLineParser::CommandLineParser(const std::string& cmdLine) : cmdLine(cmdLine), pipe(false) {
    parseCommandLine();
}

// 解析命令行，将命令行分解成参数，识别输入输出重定向和管道操作。
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


// 返回解析后的命令行参数列表。
std::vector<std::string> CommandLineParser::getArguments() {
    return arguments;
}

// 返回输入重定向的文件名。
std::string CommandLineParser::getInputRedirect() {
    return inputRedirect;
}


// 返回输出重定向的文件名。
std::string CommandLineParser::getOutputRedirect() {
    return outputRedirect;
}


// 检查是否存在管道操作。
bool CommandLineParser::hasPipe() {
    return pipe;
}

// 返回管道操作后的命令。
std::string CommandLineParser::getPipeCommand() {
    return pipeCommand;
}
