#pragma once

#include <mutex>
#include <ostream>

namespace Singleton
{
    enum class LogLevel : std::uint8_t
    {
        Info,
        Warn,
        Error
    };

    class Logger final
    {
    public:
        Logger(const Logger&) = delete;
        Logger(Logger&&) = delete;

        Logger& operator=(const Logger&) = delete;
        Logger& operator=(Logger&&) = delete;

    public:
        void SetStream(std::ostream* stream);
        void Log(LogLevel level, const std::string& data);

        static Logger& GetInstance();

    private:
        Logger();

    private:
        std::ostream* stream_;
        std::mutex mutex_;
    };
}