#pragma once

#include "IHttpPackageBuilder.h"

namespace Builder
{
    class HttpRequestPackageBuilder final : public IHttpPackageBuilder
    {
    public:
        IHttpPackageBuilder& SetRequest(const std::string& request) override;
        IHttpPackageBuilder& SetHeaders(const HeadersList& headers) override;
        IHttpPackageBuilder& SetBody(const std::string& body) override;

        HttpRequestPackage GetConstructedHttpRequestPackage();

    private:
        HttpRequestPackage package_;
    };
}