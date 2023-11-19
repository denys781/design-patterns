#include "Logger.h"
#include <map>
#include <string>

namespace
{
    using Singleton::LogLevel;

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

namespace Singleton
{
    Logger::Logger()
        : stream_(nullptr)
    {
    }

    void Logger::SetStream(std::ostream* stream)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stream_ = stream; // stream can be null pointer to reset stream_
    }

    void Logger::Log(LogLevel level, const std::string& data)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!stream_)
        {
            return;
        }

        *stream_
            << GetLogLevelStringRepresentation(level) << ":\t" << data << '\n' << std::flush;
    }

    Logger& Logger::GetInstance()
    {
        static Logger logger;
        return logger;
    }
}