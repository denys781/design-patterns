#include "Image.h"
#include <fstream>

namespace Proxy
{
    Image::Image(const std::string& path)
    {
        LoadImage(path);
    }

    void Image::PrintImage(std::ostream* stream)
    {
        stream->write(reinterpret_cast<const char*>(image_.data()), image_.size());
    }

    Bytes Image::GetImage()
    {
        return image_;
    }

    void Image::LoadImage(const std::string& path)
    {
        std::ifstream stream(path);

        if (!stream.is_open())
        {
            return;
        }

        stream.seekg(0, std::ios::end);
        const std::size_t file_size = stream.tellg();
        stream.seekg(0);
        image_.resize(file_size);

        stream.read(reinterpret_cast<char*>(image_.data()), file_size);
    }
}