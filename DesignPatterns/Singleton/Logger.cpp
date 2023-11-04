#include "Logger.h"
#include <map>
#include <sstream>

namespace
{
    using Logging::LogLevel;

    std::string GetLogLevelStringRepresentation(LogLevel level)
    {
        static std::map<LogLevel, std::string> logLevels;

        if (logLevels.empty())
        {
            logLevels.emplace(LogLevel::Info,  "INFO");
            logLevels.emplace(LogLevel::Warn,  "WARN");
            logLevels.emplace(LogLevel::Error, "ERROR");
        }
        return logLevels[level];
    }
}

namespace Logging
{
    Logger::Logger()
        : stream_(nullptr)
    {
    }

    void Logger::SetStream(std::ostream* stream)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stream_ = stream;
    }

    void Logger::Log(LogLevel level, const std::string& data)
    {
        std::ostringstream buffer;
        buffer << GetLogLevelStringRepresentation(level) << ":\t" << data << '\n';

        std::lock_guard<std::mutex> lock(mutex_);
        if (stream_ != nullptr)
        {
            *stream_ << buffer.str() << std::flush;
        }
    }

    Logger& Logger::GetInstance()
    {
        static Logger logger;
        return logger;
    }
}