#pragma once

#include "HttpStructures.h"

namespace Builder
{
    class IHttpPackageBuilder
    {
    public:
        virtual ~IHttpPackageBuilder() = default;

        virtual IHttpPackageBuilder& SetRequest(const std::string& request) { return *this; }
        virtual IHttpPackageBuilder& SetStatus(const std::string& status) { return *this; }

        virtual IHttpPackageBuilder& SetHeaders(const HeadersList& headers) = 0;
        virtual IHttpPackageBuilder& SetBody(const std::string& body) = 0;
    };
}