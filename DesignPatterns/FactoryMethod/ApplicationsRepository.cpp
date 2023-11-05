#include "ApplicationsRepository.h"

namespace FactoryMethod
{
    ApplicationsList ApplicationsRepository::GetAvailableApplications()
    {
        return GetApplicationsByQuery("SELECT * FROM AvailableApplications");
    }

    ApplicationsList ApplicationsRepository::GetBlockedApplications()
    {
        return GetApplicationsByQuery("SELECT * FROM BlockedApplications");
    }

    ApplicationsList ApplicationsRepository::GetPlannedApplications()
    {
        return GetApplicationsByQuery("SELECT * FROM PlannedApplications");
    }

    ApplicationsList ApplicationsRepository::GetApplicationsByQuery(const std::string& query)
    {
        auto databaseEngine = GetDatabaseEngine(); // factory method call

        if (!databaseEngine->Connect())
        {
            throw std::runtime_error("Database connection has not been established.");
        }

        Table table = databaseEngine->ExecuteQuery(query);
        ApplicationsList applications;

        applications.reserve(table.size());

        for (const auto& row : table)
        {
            Application application;

            application.name_ = row.at("name");
            application.founder_ = row.at("founder");

            applications.push_back(application);
        }
        return applications;
    }
}