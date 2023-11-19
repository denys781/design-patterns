#include "XorStreamWriterDecorator.h"
#include <algorithm>

namespace Decorator
{
    XorStreamWriterDecorator::XorStreamWriterDecorator(
        std::shared_ptr<IStreamWriter> stream,
        std::uint8_t key
    )
    {
        if (!stream)
        {
            throw std::runtime_error(
                "XorStreamWriterDecorator can't be constructed with null pointer."
            );
        }
        stream_ = stream;
        key_ = key;
    }

    IStreamWriter& XorStreamWriterDecorator::Write(const std::string& data)
    {
        std::string buf(data);

        std::transform(data.begin(), data.end(), buf.begin(),
            [this](char byte) -> char
        {
            return byte ^ key_;
        });

        stream_->Write(buf);
        return *this;
    }

    void XorStreamWriterDecorator::Flush()
    {
        stream_->Flush();
    }
}