#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace ChainOfResponsibility
{
    enum class LogLevel : std::uint8_t
    {
        Info,
        Warn,
        Error
    };

    class BaseLogger
    {
    public:
        virtual ~BaseLogger() = default;

        void Log(LogLevel logLevel, const std::string& text);
        void SetNext(std::shared_ptr<BaseLogger> next);

    protected:
        BaseLogger(LogLevel usedLogLevel);

        std::string GetUsedLogLevelStringRepresantation();

    private:
        virtual void Write(const std::string& text) = 0;

    private:
        LogLevel logLevel_;
        std::shared_ptr<BaseLogger> next_;
    };
}