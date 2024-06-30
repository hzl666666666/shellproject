#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <string>
#include <vector>

class CommandLineParser {
public:
      // 构造函数，接受一个命令行字符串并解析它。
    CommandLineParser(const std::string& cmdLine);
      // 获取命令行参数的列表。
    std::vector<std::string> getArguments();
        // 获取输入重定向的文件名。
    std::string getInputRedirect();

    // 获取输出重定向的文件名。
    std::string getOutputRedirect();
        // 检查命令行中是否有管道操作。
    bool hasPipe();
        // 获取管道操作后的命令。
    std::string getPipeCommand();

private:
    // 原始命令行字符串。
    std::string cmdLine;

    // 解析后的命令行参数。
    std::vector<std::string> arguments;

    // 输入重定向的文件名。
    std::string inputRedirect;

    // 输出重定向的文件名。
    std::string outputRedirect;

    // 是否存在管道操作。
    bool pipe;

    // 管道操作后的命令。
    std::string pipeCommand;

    // 解析命令行的私有方法。
    void parseCommandLine();
};

#endif // COMMANDLINEPARSER_H
