#pragma once

#include <string>
#include <map>

namespace Builder
{
    using HeadersList = std::map<std::string, std::string>;

    struct CommonHttpPackagePart
    {
        HeadersList headers_;
        std::string body_;
    };

    struct HttpRequestPackage : CommonHttpPackagePart
    {
        std::string request_;
    };

    struct HttpResponsePackage : CommonHttpPackagePart
    {
        std::string status_;
    };
}