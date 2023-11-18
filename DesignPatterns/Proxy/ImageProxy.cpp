#include "ImageProxy.h"
#include "Image.h"

namespace Proxy
{
    ImageProxy::ImageProxy(const std::string& path)
        : path_(path)
    {
    }

    void ImageProxy::PrintImage(std::ostream* stream)
    {
        GetRealImage()->PrintImage(stream);
    }

    Bytes ImageProxy::GetImage()
    {
        return GetRealImage()->GetImage();
    }

    std::shared_ptr<IImage> ImageProxy::GetRealImage()
    {
        if (!realImage_)
        {
            realImage_ = std::make_shared<Image>(path_);
        }
        return realImage_;
    }
}