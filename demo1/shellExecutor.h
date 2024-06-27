#ifndef SHELLEXECUTOR_H
#define SHELLEXECUTOR_H

#include <string>

class ShellExecutor {
public:
    static int executeCommand(const std::string& cmdLine);
};

#endif // SHELLEXECUTOR_H
