#pragma once

#include <string>

namespace Decorator
{
    class IStreamWriter
    {
    public:
        virtual ~IStreamWriter() = default;

        virtual IStreamWriter& Write(const std::string&) = 0;
        virtual void Flush() = 0;
    };
}