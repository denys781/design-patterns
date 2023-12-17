#include "FileLogger.h"
#include <stdexcept>

namespace ChainOfResponsibility
{
    FileLogger::FileLogger(LogLevel usedLogLevel, const std::string& filePath)
        : BaseLogger(usedLogLevel)
        , stream_(std::make_shared<std::ofstream>(filePath, std::ios::out || std::ios::app))
    {
    }

    void FileLogger::Write(const std::string& text)
    {
        *stream_ << GetUsedLogLevelStringRepresantation() << ": " << text << '\n';
    }
}