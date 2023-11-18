#include "XorStreamWriterDecorator.h"
#include <algorithm>

namespace Decorator
{
    XorStreamWriterDecorator::XorStreamWriterDecorator(
        std::shared_ptr<IStreamWriter> stream,
        std::uint8_t key
    )
        : stream_(stream)
        , key_(key)
    {
    }

    IStreamWriter& XorStreamWriterDecorator::Write(const std::string& data)
    {
        if (stream_)
        {
            std::string buf(data.size(), 0);

            std::transform(data.begin(), data.end(), buf.begin(),
                [this](char byte) -> char
            {
                return byte ^ key_;
            });

            stream_->Write(buf);
        }
        return *this;
    }

    void XorStreamWriterDecorator::Flush()
    {
        if (stream_)
        {
            stream_->Flush();
        }
    }
}