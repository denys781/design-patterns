#pragma once

#include "PostgreSQLDatabaseEngine.h"
#include <string>
#include <vector>
#include <memory>

namespace FactoryMethod
{
    struct Application
    {
        std::string name_;
        std::string founder_;
    };

    using ApplicationsList = std::vector<Application>;

    class ApplicationsRepository
    {
    public:
        virtual ~ApplicationsRepository() = default;

        ApplicationsList GetAvailableApplications();
        ApplicationsList GetBlockedApplications();
        ApplicationsList GetPlannedApplications();

    private:
        ApplicationsList GetApplicationsByQuery(const std::string& query);

        virtual std::unique_ptr<IDatabaseEngine> GetDatabaseEngine() = 0;
    };
}