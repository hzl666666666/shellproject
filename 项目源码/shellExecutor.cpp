#include "shellExecutor.h"
#include "CommandLineParser.h"
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
// 执行给定命令行字符串的命令。
int ShellExecutor::executeCommand(const std::string& cmdLine) {

       // 使用 CommandLineParser 解析命令行
    CommandLineParser parser(cmdLine);
    std::vector<std::string> arguments = parser.getArguments();

    // 将参数列表转换为 C 风格字符串数组。
    char** args = new char*[arguments.size() + 1];
    for (size_t i = 0; i < arguments.size(); i++) {
        args[i] = const_cast<char*>(arguments[i].c_str());
    }
    args[arguments.size()] = nullptr;
 // 使用 fork 创建一个子进程来执行命令。
    pid_t pid = fork();
    if (pid == 0) {
        // 子进程中，根据需要重定向标准输入输出。
        if (!parser.getInputRedirect().empty()) {
            freopen(parser.getInputRedirect().c_str(), "r", stdin);
        }
        if (!parser.getOutputRedirect().empty()) {
            freopen(parser.getOutputRedirect().c_str(), "w", stdout);
        }
   // 使用 execvp 执行命令，如果失败则输出错误信息并退出。
        if (execvp(args[0], args) == -1) {
            std::cerr << "Error executing command" << std::endl;
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        // 父进程中，等待子进程结束。
        int status;
        waitpid(pid, &status, 0);
    } else {
        // 如果 fork 失败，输出错误信息。
        std::cerr << "Fork failed" << std::endl;
    }
// 释放之前分配的参数数组内存。
    delete[] args;
  // 返回 0 表示成功执行命令。
    return 0;
}
