#include "HttpResponsePackageBuilder.h"

namespace Builder
{
    IHttpPackageBuilder& HttpResponsePackageBuilder::SetStatus(const std::string& status)
    {
        package_.status_ = status;
        return *this;
    }

    IHttpPackageBuilder& HttpResponsePackageBuilder::SetHeaders(const HeadersList& headers)
    {
        package_.headers_ = headers;
        return *this;
    }

    IHttpPackageBuilder& HttpResponsePackageBuilder::SetBody(const std::string& body)
    {
        package_.body_ = body;
        return *this;
    }

    HttpResponsePackage HttpResponsePackageBuilder::GetConstructedHttpResponsePackage()
    {
        return std::move(package_);
    }
}