#ifndef SHELLEXECUTOR_H
#define SHELLEXECUTOR_H

#include <string>

class ShellExecutor {
public:
    // 执行给定命令行字符串的命令。
    static int executeCommand(const std::string& cmdLine);
};

#endif // SHELLEXECUTOR_H
