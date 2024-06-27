#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <string>
#include <vector>

class CommandLineParser {
public:
    CommandLineParser(const std::string& cmdLine);
    std::vector<std::string> getArguments();
    std::string getInputRedirect();
    std::string getOutputRedirect();
    bool hasPipe();
    std::string getPipeCommand();

private:
    std::string cmdLine;
    std::vector<std::string> arguments;
    std::string inputRedirect;
    std::string outputRedirect;
    bool pipe;
    std::string pipeCommand;

    void parseCommandLine();
};

#endif // COMMANDLINEPARSER_H
