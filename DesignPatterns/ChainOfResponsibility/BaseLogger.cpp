#include "BaseLogger.h"
#include <map>

namespace ChainOfResponsibility
{
    BaseLogger::BaseLogger(LogLevel usedLogLevel)
        : logLevel_(usedLogLevel)
    {
    }

    void BaseLogger::Log(LogLevel logLevel, const std::string& text)
    {
        if (logLevel_ == logLevel)
        {
            Write(text);
            return;
        }
        if (next_)
        {
            next_->Log(logLevel, text);
        }
    }

    void BaseLogger::SetNext(std::shared_ptr<BaseLogger> next)
    {
        next_ = next;
    }

    std::string BaseLogger::GetUsedLogLevelStringRepresantation()
    {
        static std::map<LogLevel, std::string> logLevels;

        if (logLevels.empty())
        {
            logLevels.emplace(LogLevel::Info, "INFO");
            logLevels.emplace(LogLevel::Warn, "WARN");
            logLevels.emplace(LogLevel::Error, "ERROR");
        }
        return logLevels[logLevel_];
    }
}