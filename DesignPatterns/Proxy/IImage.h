#pragma once

#include <vector>
#include <ostream>

namespace Proxy
{
    using Bytes = std::vector<unsigned char>;

    class IImage
    {
    public:
        virtual ~IImage() = default;

        virtual void PrintImage(std::ostream*) = 0;
        virtual Bytes GetImage() = 0;
    };
}