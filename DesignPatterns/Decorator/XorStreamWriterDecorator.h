#pragma once

#include "IStreamWriter.h"
#include <memory>

namespace Decorator
{
    class XorStreamWriterDecorator : public IStreamWriter
    {
    public:
        XorStreamWriterDecorator(
            std::shared_ptr<IStreamWriter> stream,
            std::uint8_t key
        );

        IStreamWriter& Write(const std::string&) override;
        void Flush() override;

    private:
        std::shared_ptr<IStreamWriter> stream_;
        std::uint8_t key_;
    };
}