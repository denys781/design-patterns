#pragma once

#include "IImage.h"

namespace Proxy
{
    class Image final : public IImage
    {
    public:
        explicit Image(const std::string&);

        void PrintImage(std::ostream*) override;
        Bytes GetImage() override;

    private:
        void LoadImage(const std::string&);

    private:
        Bytes image_;
    };
}