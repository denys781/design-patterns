#pragma once

#include "IHttpPackageBuilder.h"

namespace Builder
{
    class HttpResponsePackageBuilder final : public IHttpPackageBuilder
    {
    public:
        IHttpPackageBuilder& SetStatus(const std::string& status) override;
        IHttpPackageBuilder& SetHeaders(const HeadersList& headers) override;
        IHttpPackageBuilder& SetBody(const std::string& body) override;

        HttpResponsePackage GetConstructedHttpResponsePackage();

    private:
        HttpResponsePackage package_;
    };
}