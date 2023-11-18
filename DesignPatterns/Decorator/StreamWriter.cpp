#include "StreamWriter.h"

namespace Decorator
{
    StreamWriter::StreamWriter(std::ostream* stream)
        : stream_(stream)
    {
    }

    IStreamWriter& StreamWriter::Write(const std::string& data)
    {
        if (stream_)
        {
            *stream_ << data;
        }
        return *this;
    }

    void StreamWriter::Flush()
    {
        if (stream_)
        {
            stream_->flush();
        }
    }
}