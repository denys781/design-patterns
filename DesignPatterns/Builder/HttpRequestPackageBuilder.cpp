#include "HttpRequestPackageBuilder.h"

namespace Builder
{
    IHttpPackageBuilder& HttpRequestPackageBuilder::SetRequest(const std::string& request)
    {
        package_.request_ = request;
        return *this;
    }

    IHttpPackageBuilder& HttpRequestPackageBuilder::SetHeaders(const HeadersList& headers)
    {
        package_.headers_ = headers;
        return *this;
    }

    IHttpPackageBuilder& HttpRequestPackageBuilder::SetBody(const std::string& body)
    {
        package_.body_ = body;
        return *this;
    }

    HttpRequestPackage HttpRequestPackageBuilder::GetConstructedHttpRequestPackage()
    {
        return std::move(package_);
    }
}