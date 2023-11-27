#pragma once

#include "IStreamWriter.h"
#include <ostream>

namespace Decorator
{
    class StreamWriter : public IStreamWriter
    {
    public:
        explicit StreamWriter(std::ostream*);

        IStreamWriter& Write(const std::string&) override;
        void Flush() override;

    private:
        std::ostream* stream_;
    };
}