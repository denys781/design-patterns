#pragma once

#include "IImage.h"
#include <memory>
#include <string>

namespace Proxy
{
    // virtual proxy
    class ImageProxy final : public IImage
    {
    public:
        explicit ImageProxy(const std::string&);

        void PrintImage(std::ostream*) override;
        Bytes GetImage() override;

    private:
        std::shared_ptr<IImage> GetRealImage();

    private:
        std::string path_;
        std::shared_ptr<IImage> realImage_;
    };
}