#pragma once

#include "BaseLogger.h"
#include <fstream>
#include <memory>

namespace ChainOfResponsibility
{
    class FileLogger : public BaseLogger
    {
    public:
        FileLogger(LogLevel usedLogLevel, const std::string& filePath);

    private:
        void Write(const std::string& text) override;

    private:
        std::shared_ptr<std::ofstream> stream_;
    };
}