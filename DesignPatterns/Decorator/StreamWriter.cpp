#include "StreamWriter.h"
#include <stdexcept>

namespace Decorator
{
    StreamWriter::StreamWriter(std::ostream* stream)
    {
        if (!stream)
        {
            throw std::runtime_error(
                "StreamWriter can't be constructed with null pointer."
            );
        }
        stream_ = stream;
    }

    IStreamWriter& StreamWriter::Write(const std::string& data)
    {
        *stream_ << data;
        return *this;
    }

    void StreamWriter::Flush()
    {
        stream_->flush();
    }
}