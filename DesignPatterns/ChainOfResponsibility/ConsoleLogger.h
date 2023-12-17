#pragma once

#include "BaseLogger.h"

namespace ChainOfResponsibility
{
    class ConsoleLogger : public BaseLogger
    {
    public:
        ConsoleLogger(LogLevel usedLogLevel);

    private:
        void Write(const std::string& text) override;
    };
}