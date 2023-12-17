#include "ConsoleLogger.h"
#include <iostream>

namespace ChainOfResponsibility
{
    ConsoleLogger::ConsoleLogger(LogLevel usedLogLevel)
        : BaseLogger(usedLogLevel)
    {
    }

    void ConsoleLogger::Write(const std::string& text)
    {
        std::cerr << GetUsedLogLevelStringRepresantation() << ": " << text << '\n';
    }
}