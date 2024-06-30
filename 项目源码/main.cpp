#include "shellExecutor.h"
#include <iostream>
#include <string>

int main() {
    std::string cmdLine;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, cmdLine);// 读取用户输入的命令行。
        if (cmdLine == "exit") {
            break;// 如果用户输入 "exit"，则退出循环。
        }
        ShellExecutor::executeCommand(cmdLine); // 执行用户输入的命令。
    }
    return 0; // 程序正常结束。
}
